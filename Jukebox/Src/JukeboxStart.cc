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
#include <map>
#include <cstring>
#include <cstdio>

#include "JukeboxStart.h"

#include "OS/Task.h"
#include "OS/Semaphore.h"
#include "Logger/Logger.h"

#include "MassStorageDevice/MassStorageDeviceFactory.h"
#include "AudioPlayer/AudioPlayerFactory.h"

#include "AudioPlayer/Decoder/Mp3Decoder.h"
#include "AudioPlayer/Decoder/WavDecoder.h"

#include "MassStorageDevice/FlashFile.h"

#include "SM/KeyPadSM.h"

#include "FailSound.h"
#include "OkSound.h"

namespace ATE::Jukebox
{
    constexpr static char TASK_NAME[] = "JukeboxTask";

    class JukeboxTask : public OSAL::Task
    {
    public:
        enum EventType
        {
            Event_NoEvent = 0,
            Event_UsbStorageChanged,
            Event_PlaybackStateChanged,
            Event_KeyPadUpdate,
            Event_KeyPadStopPlayback
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

        enum TrackType
        {
            TRACK_NONE = 0,
            TRACK_MP3,
            TRACK_WAV
        };

        JukeboxTask():
            Task(TASK_NAME, osPriorityRealtime, 4096),
            EventQueue(20),
            MassStorageDevice(Device::MassStorageDeviceFactory::GetUSBHostStorage()),
            AudioPlayer(Audio::PlayerFactory::GetI2SPlayer())
        {

        }

        void UsbDevCb(Device::IMassStorageDevice::Event event)
        {
            EventQueue.Push(Event(Event_UsbStorageChanged, event), 0);
        }

        void AudioDevCb(Audio::IPlayer::State state)
        {
            EventQueue.Push(Event(Event_PlaybackStateChanged, state), 0);
        }

        void KeyPadSMCb(SM::KeyPadSM::EventType event, char letter, char number)
        {
            if (event == SM::KeyPadSM::Event_PlaySong)
            {
                EventQueue.Push(Event(Event_KeyPadUpdate, letter, number), 0);
            }
            else if (event == SM::KeyPadSM::Event_StopPlayback)
            {
                EventQueue.Push(Event(Event_KeyPadStopPlayback, letter, number), 0);
            }
        }

        virtual void Init() override
        {
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

            KeyPadSM.Subscribe(
                    std::bind(
                            &JukeboxTask::KeyPadSMCb,
                            this,
                            std::placeholders::_1,
                            std::placeholders::_2,
                            std::placeholders::_3)
            );
        }

        bool IdentifyFiles()
        {
            constexpr char rootPath[] = "/";
            constexpr std::array<char, 20> letters =
                { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'J', 'K',
                  'L', 'N', 'M', 'P', 'Q', 'R', 'S', 'T', 'U', 'V' };

            auto dirReader = MassStorageDevice.OpenDir(rootPath);
            Device::FileInfo fInfo;

            do
            {
                fInfo = dirReader->ReadNext();
                if ((fInfo.type == Device::FileInfo::TYPE_FILE) && (fInfo.path[0] != '.'))
                {
                    char letter = fInfo.path[0];
                    std::uint8_t number = fInfo.path[1] - '0';

                    if (!std::strcmp(&fInfo.path[2], ".mp3"))
                    {
                        trackMap[letter][number] = TRACK_MP3;
                    }
                    else if (!std::strcmp(&fInfo.path[2], ".wav"))
                    {
                        trackMap[letter][number] = TRACK_WAV;
                    }
                    ATE_LOG_DEBUG("%s", fInfo.path);
                }

            } while(fInfo.type != Device::FileInfo::TYPE_NONE);

            /* TODO: remove return true */
            return true;

            for (char letter: letters)
            {
                std::array<TrackType, N_NUMBERS>& letterArray = trackMap[letter];
                for (TrackType type: letterArray)
                {
                    if (type == TRACK_NONE)
                    {
                        return false;
                    }
                }
            }

            return true;
        }

        void HandleUsbStorageChangedEvent(Device::IMassStorageDevice::Event event)
        {
            switch (event)
            {
            case Device::IMassStorageDevice::MSD_Ready:
                if (MassStorageDevice.Mount())
                {
                    if (!IdentifyFiles())
                    {
                        PlayFailSound();
                        usbOk = false;
                        return;
                    }

                    usbOk = true;
                    PlayOkSound();
                }
                break;
            case Device::IMassStorageDevice::MSD_Removed:
                MassStorageDevice.Unmount();
                PlayFailSound();
                usbOk = false;
                break;
            }
        }

        void HandlePlaybackStateChangedEvent(Audio::IPlayer::State state)
        {
            playing = state == Audio::IPlayer::State_Playing;
        }

        void HandleKeyPadUpdateEvent(char letter, char number)
        {
            TrackType type = trackMap[letter][number-'0'];

            if (!usbOk)
            {
                ATE_LOG_INFO("Usb not mounted");
                PlayFailSound();
                return;
            }

            constexpr static auto MAX_FILENAME_LEN = 10;
            char fileName[MAX_FILENAME_LEN];
            if (type == TRACK_MP3)
            {
                snprintf(fileName, MAX_FILENAME_LEN, "%c%c.mp3", letter, number);
            }
            else if (type == TRACK_WAV)
            {
                snprintf(fileName, MAX_FILENAME_LEN, "%c%c.wav", letter, number);
            }
            else
            {
                ATE_LOG_INFO("File `%s` wasn't found during scan", fileName);
                PlayFailSound();
                return;
            }

            std::unique_ptr<Device::IFile> file = MassStorageDevice.OpenFile(fileName);
            if (!file->Exists())
            {
                ATE_LOG_INFO("File `%s` doesn't exist", fileName);
                PlayFailSound();
                return;
            }

            if (playing)
            {
                AudioPlayer.Stop();
                Delay(100);
            }

            ATE_LOG_INFO("Playing file %s", fileName);
            std::unique_ptr<Audio::IDecoder> decoder;
            if (type == TRACK_MP3)
            {
                decoder = std::make_unique<Audio::Mp3Decoder>(std::move(file));
            }
            else if (type == TRACK_WAV)
            {
                decoder = std::make_unique<Audio::WavDecoder>(std::move(file));
            }

            AudioPlayer.Play(std::move(decoder));
        }

        void HandleKeyPadStopPlaybackEvent()
        {
            AudioPlayer.Stop();
        }

        void PlayFailSound()
        {
            if (playing)
            {
                AudioPlayer.Stop();
                Delay(100);
            }

            AudioPlayer.Play(
                    std::make_unique<Audio::Mp3Decoder>(
                            std::make_unique<Device::FlashFile>(
                                    Audio::Sound::Fail_mp3,
                                    sizeof(Audio::Sound::Fail_mp3)
                            )
                    )
            );
        }

        void PlayOkSound()
        {
            AudioPlayer.Play(
                    std::make_unique<Audio::Mp3Decoder>(
                            std::make_unique<Device::FlashFile>(
                                    Audio::Sound::Ok_mp3,
                                    sizeof(Audio::Sound::Ok_mp3)
                            )
                    )
            );
        }

        virtual bool Run() override
        {
            Event event;
            EventQueue.Pop(event);

            switch (event.type)
            {
            case Event_UsbStorageChanged:
                HandleUsbStorageChangedEvent(
                        static_cast<Device::IMassStorageDevice::Event>(event.arg1));
                break;
            case Event_PlaybackStateChanged:
                HandlePlaybackStateChangedEvent(
                        static_cast<Audio::IPlayer::State>(event.arg1));
                break;
            case Event_KeyPadUpdate:
                HandleKeyPadUpdateEvent(
                        static_cast<char>(event.arg1),
                        static_cast<char>(event.arg2));
                break;
            case Event_KeyPadStopPlayback:
                HandleKeyPadStopPlaybackEvent();
                break;
            case Event_NoEvent:
                ATE_LOG_ERROR("Received empty event!");
                break;
            default:
                ATE_LOG_ERROR("Received corrupted event!");
                break;
            }

            return true;
        }

    private:
        OSAL::Queue<Event> EventQueue;
        Device::IMassStorageDevice& MassStorageDevice;
        Audio::IPlayer& AudioPlayer;
        SM::KeyPadSM KeyPadSM;

        bool usbOk;
        bool playing;

        constexpr static std::size_t N_NUMBERS = 10;
        std::map<char, std::array<TrackType, N_NUMBERS>> trackMap;
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
