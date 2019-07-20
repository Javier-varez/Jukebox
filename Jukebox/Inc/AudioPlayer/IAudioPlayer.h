/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: IAudioPlayer.h
 * Brief: Audio Player Interface
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
		enum State
		{
			State_Idle,
			State_Playing,
			State_Paused,
		};

		using AudioEventCb_t = std::function<void(State)>;

		void Subscribe(AudioEventCb_t cb);
		State GetState();


		virtual bool Play(std::unique_ptr<IDecoder> decoder) = 0;
		virtual void Pause() = 0;
		virtual void Resume() = 0;
		virtual void Stop() = 0;

		virtual void SetVolume(std::uint8_t volume) = 0;

	private:
		State CurrentState = State_Idle;

		AudioEventCb_t eventCb;
		OSAL::Mutex eventCbMutex;
		OSAL::Mutex StateMutex;

	protected:
		void Notify(State event);
		void SetState(State state);
	};
}

#endif /* ATE_IAUDIO_PLAYER_H_ */
