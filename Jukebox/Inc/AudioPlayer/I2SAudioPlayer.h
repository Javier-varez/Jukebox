/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: I2SAudioPlayer.h
 * Brief: Audio Player
 * Module: Audio
 */

#ifndef ATE_I2S_AUDIO_PLAYER_H_
#define ATE_I2S_AUDIO_PLAYER_H_

#include "AudioPlayer/IAudioPlayer.h"
#include "OS/Mutex.h"
#include "OS/Task.h"
#include "OS/Queue.h"

extern "C" void BSP_AUDIO_OUT_TransferComplete_CallBack(void);
extern "C" void BSP_AUDIO_OUT_HalfTransfer_CallBack(void);

namespace ATE::Audio
{
    class I2SPlayer : public OSAL::Task, public IPlayer
    {
    public:
        enum HalfBuffer : std::uint32_t
        {
            FirstHalfBuffer,
            LastHalfBuffer
        };

        enum EventType
        {
            Event_NoEvent = 0,
            Event_FillNextBuffer,
            Event_SetVolume,
            Event_Stop,
            Event_Start,
            Event_Pause,
            Event_Resume,
        };

        struct Event
        {
            EventType type;
            std::uint32_t arg;

            Event(EventType type = Event_NoEvent, std::uint32_t arg = 0) :
                type(type),
                arg(arg) { }
        };

        static I2SPlayer& GetPlayer();

        bool Play(std::unique_ptr<IDecoder> decoder) override;

        void Pause() override;
        void Resume() override;
        void Stop() override;

        void SetVolume(std::uint8_t volume) override;

    private:
        static constexpr std::size_t N_CHANNELS = 2;
        static constexpr std::size_t N_SAMPLES_IN_INTERNAL_BUF = 4096;

        I2SPlayer();

        void Init() override;
        bool Run() override;

        void HandleFillNextBufferEvent(std::uint32_t arg);
        void HandleSetVolumeEvent(std::uint8_t volume);
        void HandleStopEvent();
        void HandleStartEvent();
        void HandlePauseEvent();
        void HandleResumeEvent();

        void NotifyEvent(EventType type, std::uint32_t arg = 0, std::uint32_t timeout = osWaitForever);

        void SetShadowDecoder(std::unique_ptr<IDecoder> decoder);
        void UpdateDecoderFromShadow();

        OSAL::Queue<Event> EventQueue;

        std::unique_ptr<IDecoder> CurrentDecoder;

        std::int16_t InternalBuffer[N_CHANNELS * N_SAMPLES_IN_INTERNAL_BUF];

        std::unique_ptr<IDecoder> ShadowDecoder;
        OSAL::Mutex ShadowDecoderMutex;

        friend void ::BSP_AUDIO_OUT_TransferComplete_CallBack(void);
        friend void ::BSP_AUDIO_OUT_HalfTransfer_CallBack(void);
    };
}

#endif /* ATE_I2S_AUDIO_PLAYER_H_ */
