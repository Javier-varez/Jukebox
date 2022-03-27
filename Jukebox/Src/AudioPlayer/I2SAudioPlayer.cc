/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: AudioPlayer.h
 * Brief: Audio Player
 * Module: Audio
 */

#include "AudioPlayer/I2SAudioPlayer.h"
#include "OS/UniqueLock.h"
#include "Logger/Logger.h"

#include "stm32f411e_discovery_audio.h"

extern "C"
{
	void BSP_AUDIO_OUT_TransferComplete_CallBack(void)
	{
		using I2SPlayer = ATE::Audio::I2SPlayer;
		I2SPlayer& player = I2SPlayer::GetPlayer();

		player.NotifyEvent(I2SPlayer::Event_FillNextBuffer,
				I2SPlayer::LastHalfBuffer, 0);

		BSP_AUDIO_OUT_ChangeBuffer(reinterpret_cast<std::uint16_t*>(player.InternalBuffer),
				I2SPlayer::N_SAMPLES_IN_INTERNAL_BUF * I2SPlayer::N_CHANNELS);
	}

	void BSP_AUDIO_OUT_HalfTransfer_CallBack(void)
	{
		using I2SPlayer = ATE::Audio::I2SPlayer;
		I2SPlayer& player = I2SPlayer::GetPlayer();

		player.NotifyEvent(I2SPlayer::Event_FillNextBuffer,
				I2SPlayer::FirstHalfBuffer, 0);
	}

	void BSP_AUDIO_OUT_Error_CallBack(void) {
		LOG_ERROR(ATE::Logger::GetLogger(), "Error processing audio out");
	}
}


namespace ATE::Audio
{
	constexpr static std::size_t MAX_EVENTS_IN_QUEUE = 10;
	constexpr static std::size_t INITIAL_VOLUME = 100;

	I2SPlayer& I2SPlayer::GetPlayer()
	{
		static I2SPlayer player;
		return player;
	}

	I2SPlayer::I2SPlayer() :
		Task("I2SPlayer", osPriorityRealtime, 4096),
		EventQueue(MAX_EVENTS_IN_QUEUE),
		CurrentVolume(INITIAL_VOLUME)
	{

	}

	void I2SPlayer::Init()
	{

	}

	bool I2SPlayer::Run()
	{
		Event event;
		EventQueue.Pop(event);

		switch (event.type)
		{
		case Event_FillNextBuffer:
			HandleFillNextBufferEvent(event.arg);
			break;
		case Event_SetVolume:
			HandleSetVolumeEvent(event.arg);
			break;
		case Event_Stop:
			HandleStopEvent();
			break;
		case Event_Start:
			HandleStartEvent();
			break;
		case Event_Pause:
			HandlePauseEvent();
			break;
		case Event_Resume:
			HandleResumeEvent();
			break;
		case Event_NoEvent:
			LOG_ERROR(Logger::GetLogger(),"Empty event");
			break;
		default:
			LOG_ERROR(Logger::GetLogger(),"Received unknown event");
			break;
		}
		return true;
	}

	void I2SPlayer::HandleFillNextBufferEvent(std::uint32_t arg)
	{
		HalfBuffer half = static_cast<HalfBuffer>(arg);
		std::size_t nSamples;

		switch (half)
		{
		case FirstHalfBuffer:
			nSamples = CurrentDecoder->Decode(&InternalBuffer[0],
					N_SAMPLES_IN_INTERNAL_BUF / 2);
			break;
		case LastHalfBuffer:
			nSamples = CurrentDecoder->Decode(&InternalBuffer[N_SAMPLES_IN_INTERNAL_BUF * N_CHANNELS / 2],
					N_SAMPLES_IN_INTERNAL_BUF / 2);
			break;
		default:
			LOG_ERROR(Logger::GetLogger(),
								"Unknown argument");
			return;
			break;
		}

		if (nSamples < N_SAMPLES_IN_INTERNAL_BUF / 2)
		{
			LOG_DEBUG(Logger::GetLogger(),
					"EOF found. Scheduling stop");
			NotifyEvent(Event_Stop);
		}
	}

	void I2SPlayer::HandleSetVolumeEvent(std::uint8_t volume)
	{
		BSP_AUDIO_OUT_SetVolume(volume);
	}

	void I2SPlayer::HandleStopEvent()
	{
		SetState(State_Idle);
		BSP_AUDIO_OUT_Stop(CODEC_PDWN_HW);
	}

	void I2SPlayer::HandleStartEvent()
	{
		if (GetState() == State_Playing) return;

		SetState(State_Playing);
		EventQueue.RemoveAll();
		UpdateDecoderFromShadow();

		std::size_t nSamples = CurrentDecoder->Decode(InternalBuffer, N_SAMPLES_IN_INTERNAL_BUF);
		std::uint32_t SamplingFrequency = CurrentDecoder->GetSampleFrequency();
		LOG_DEBUG(Logger::GetLogger(), "Sampling Frequency is %u", SamplingFrequency);

		if (BSP_AUDIO_OUT_Init(
				OUTPUT_DEVICE_HEADPHONE,
				CurrentVolume,
				SamplingFrequency) != AUDIO_OK)
		{
			LOG_ERROR(Logger::GetLogger(),"Error initializing output device");
			SetState(State_Idle);
			return;
		}

		if (BSP_AUDIO_OUT_Play(reinterpret_cast<std::uint16_t*>(InternalBuffer),
				nSamples * N_CHANNELS * sizeof(std::int16_t)) != AUDIO_OK)
		{
			LOG_ERROR(Logger::GetLogger(),"Error starting playback");
			SetState(State_Idle);
			return;
		}
	}

	void I2SPlayer::HandlePauseEvent()
	{
		if (GetState() != State_Playing) return;

		SetState(State_Paused);
		BSP_AUDIO_OUT_Pause();

	}

	void I2SPlayer::HandleResumeEvent()
	{
		if (GetState() != State_Paused) return;

		SetState(State_Playing);
		BSP_AUDIO_OUT_Resume();
	}

	void I2SPlayer::NotifyEvent(EventType type, std::uint32_t arg, std::uint32_t timeout)
	{
		Event event(type, arg);
		EventQueue.Push(event, timeout);
	}

	void I2SPlayer::SetShadowDecoder(std::unique_ptr<IDecoder> decoder)
	{
		OSAL::UniqueLock l (ShadowDecoderMutex);
		ShadowDecoder = std::move(decoder);
	}

	void I2SPlayer::UpdateDecoderFromShadow()
	{
		OSAL::UniqueLock l (ShadowDecoderMutex);
		CurrentDecoder = std::move(ShadowDecoder);
	}

	bool I2SPlayer::Play(std::unique_ptr<IDecoder> decoder)
	{
		if (decoder == nullptr)
		{
			LOG_ERROR(Logger::GetLogger(),"Can't play anything without a decoder");
			return false;
		}
		if (GetState() == State_Playing)
		{
			LOG_ERROR(Logger::GetLogger(),"Please, stop the audio player first");
			return false;
		}
		SetShadowDecoder(std::move(decoder));

		NotifyEvent(Event_Start);

		return true;
	}

	void I2SPlayer::Pause()
	{
		NotifyEvent(Event_Pause);
	}

	void I2SPlayer::Resume()
	{
		NotifyEvent(Event_Resume);
	}

	void I2SPlayer::Stop()
	{
		NotifyEvent(Event_Stop);
	}

	void I2SPlayer::SetVolume(std::uint8_t volume)
	{
		if (volume > 100)
		{
			volume = 100;
		}

		NotifyEvent(Event_SetVolume, volume);
	}
}
