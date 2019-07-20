/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: JukeboxStart.h
 * Brief: Startup module
 * Module: Startup
 */

#include <functional>

#include "JukeboxStart.h"

#include "OS/Task.h"
#include "OS/Semaphore.h"
#include "Logger/Logger.h"

#include "KeyPad/KeyPadFactory.h"
#include "MassStorageDevice/MassStorageDeviceFactory.h"
#include "AudioPlayer/AudioPlayerFactory.h"

#include "AudioPlayer/Decoder/Mp3Decoder.h"

#include "MassStorageDevice/FlashFile.h"
#include "ACKSound.h"

namespace ATE::Jukebox
{
	constexpr static char TASK_NAME[] = "JukeboxTask";

	class JukeboxTask : public OSAL::Task
	{
	public:
		enum EventType
		{
			Event_NoEvent = 0,
			Event_KeyStateChanged,
			Event_UsbStorageChanged,
			Event_PlaybackStateChanged
		};

		struct Event
		{
			EventType type;
			std::uint32_t arg1;
			std::uint32_t arg2;

			Event(EventType type = Event_NoEvent,
				  std::uint32_t arg1 = 0,
				  std::uint32_t arg2 = 0) :
					  type(type), arg1(arg1), arg2(arg2)
			{

			}
		};

		JukeboxTask():
			Task(TASK_NAME, osPriorityRealtime, 4096),
			EventQueue(20),
			KeyPad(Device::KeyPadFactory::GetAnalogKeypad()),
			MassStorageDevice(Device::MassStorageDeviceFactory::GetUSBHostStorage()),
			AudioPlayer(Audio::PlayerFactory::GetI2SPlayer()),
			logger(Logger::GetLogger())
		{

		}

		bool KeyPadCb(char key, Device::IKeyPad::KeyState state)
		{
			EventQueue.Push(Event(Event_KeyStateChanged, key, state), 0);
			return true;
		}

		void UsbDevCb(Device::IMassStorageDevice::Event event)
		{
			EventQueue.Push(Event(Event_UsbStorageChanged, event), 0);
		}

		void AudioDevCb(Audio::IPlayer::Event event)
		{
			EventQueue.Push(Event(Event_PlaybackStateChanged, event), 0);
		}

		virtual void Init() override
		{
			// Register KeyPad Callback Handler
			KeyPad.Subscribe(
					std::bind(&JukeboxTask::KeyPadCb,
							this,
							std::placeholders::_1,
							std::placeholders::_2)
			);

			// Register USB Host MSC Callback Handler
			MassStorageDevice.Subscribe(
					std::bind(
							&JukeboxTask::UsbDevCb,
							this,
							std::placeholders::_1)
			);

			// Register Audio Player Callback Handler
			AudioPlayer.Subscribe(
					std::bind(
							&JukeboxTask::AudioDevCb,
							this,
							std::placeholders::_1)
			);
		}

		void HandleKeyStateChangedEvent(char key, Device::IKeyPad::KeyState state)
		{
			logger.Log(ATE::Logger::LogLevel_DEBUG, "Received %c, state %d\r\n", key, state);
			if (state == Device::IKeyPad::KEY_PRESSED)
			{
				AudioPlayer.Play(std::make_unique<Audio::Mp3Decoder>(std::make_unique<Device::FlashFile>(
						Audio::Sound::ACK_mp3,
						sizeof(Audio::Sound::ACK_mp3))));
			}
		}

		void HandleUsbStorageChangedEvent(Device::IMassStorageDevice::Event event)
		{
			switch (event)
			{
			case Device::IMassStorageDevice::MSD_Ready:
				if (MassStorageDevice.Mount())
				{
					AudioPlayer.Play(std::make_unique<Audio::Mp3Decoder>(MassStorageDevice.OpenFile("A1.mp3")));
				}
				break;
			case Device::IMassStorageDevice::MSD_Removed:
				MassStorageDevice.Unmount();
				break;
			}
		}

		void HandlePlaybackStateChangedEvent(Audio::IPlayer::Event event)
		{

		}

		virtual bool Run() override
		{
			Event event;
			EventQueue.Pop(event);

			switch (event.type)
			{
			case Event_KeyStateChanged:
				HandleKeyStateChangedEvent(
						static_cast<char>(event.arg1),
						static_cast<Device::IKeyPad::KeyState>(event.arg2));
				break;
			case Event_UsbStorageChanged:
				HandleUsbStorageChangedEvent(
						static_cast<Device::IMassStorageDevice::Event>(event.arg1));
				break;
			case Event_PlaybackStateChanged:
				HandlePlaybackStateChangedEvent(
						static_cast<Audio::IPlayer::Event>(event.arg1));
				break;
			case Event_NoEvent:
				logger.Log(Logger::LogLevel_ERROR, "%s - %s: Received empty event!\n", __FILE__, __func__);
				break;
			default:
				logger.Log(Logger::LogLevel_ERROR, "%s - %s: Received corrupted event!\n", __FILE__, __func__);
				break;
			}

			return true;
		}

	private:
		OSAL::Queue<Event> EventQueue;
		Device::IKeyPad& KeyPad;
		Device::IMassStorageDevice& MassStorageDevice;
		Audio::IPlayer& AudioPlayer;
		Logger& logger;
	};
}

extern "C"
void JukeboxStart()
{
	osKernelInitialize(); // Initialize CMSIS-RTOS
	{
		static ATE::Jukebox::JukeboxTask task;
		osKernelStart();
	}
}
