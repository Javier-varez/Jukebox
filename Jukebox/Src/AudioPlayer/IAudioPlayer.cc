/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: IAudioPlayer.cc
 * Brief: Audio Player Interface
 * Module: Audio
 */

#include "AudioPlayer/IAudioPlayer.h"
#include "OS/UniqueLock.h"

namespace ATE::Audio
{
	void IPlayer::Notify(State state)
	{
		OSAL::UniqueLock l(eventCbMutex);
		if (eventCb != nullptr)
		{
			eventCb(state);
		}
	}

	void IPlayer::Subscribe(AudioEventCb_t cb)
	{
		OSAL::UniqueLock l(eventCbMutex);
		eventCb = cb;
	}

	IPlayer::State IPlayer::GetState()
	{
		OSAL::UniqueLock l(StateMutex);
		return CurrentState;
	}

	void IPlayer::SetState(State state)
	{
		{
			OSAL::UniqueLock l(StateMutex);
			CurrentState = state;
		}
		Notify(state);
	}
}
