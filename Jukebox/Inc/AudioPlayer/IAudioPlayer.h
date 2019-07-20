/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: IAudioPlayer.h
 * Brief: Audio Player
 * Module: Audio
 */


#ifndef ATE_IAUDIO_PLAYER_H_
#define ATE_IAUDIO_PLAYER_H_

#include "MassStorageDevice/IFile.h"
#include "AudioPlayer/Decoder/IDecoder.h"

#include <OS/Mutex.h>
#include <OS/UniqueLock.h>

#include <functional>
#include <memory>

namespace ATE::Audio
{
	class IPlayer
	{
	public:
		enum Event
		{
			Event_None = 0,
			Event_Playing,
			Event_Stopped,
			Event_Resumed,
			Event_Paused,
			Event_VolumeUpdated
		};
		using AudioEventCb_t = std::function<void(Event)>;

		void Subscribe(AudioEventCb_t cb)
		{
			OSAL::UniqueLock l(eventCbMutex);
			eventCb = cb;
		}

		virtual bool Play(std::unique_ptr<IDecoder> decoder) = 0;
		virtual void Pause() = 0;
		virtual void Resume() = 0;
		virtual void Stop() = 0;

		virtual void SetVolume(std::uint8_t volume) = 0;

	private:
		AudioEventCb_t eventCb;
		OSAL::Mutex eventCbMutex;

	protected:
		void Notify(Event event)
		{
			OSAL::UniqueLock l(eventCbMutex);
			if (eventCb != nullptr)
			{
				eventCb(event);
			}
		}
	};
}

#endif /* ATE_IAUDIO_PLAYER_H_ */
