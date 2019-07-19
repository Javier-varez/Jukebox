/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: AudioPlayerFactory.h
 * Brief: Audio Player Factory
 * Module: Audio
 */

#ifndef ATE_AUDIO_PLAYER_FACTORY_H_
#define ATE_AUDIO_PLAYER_FACTORY_H_

#include "AudioPlayer/IAudioPlayer.h"

namespace ATE::Audio
{
	class PlayerFactory
	{
	public:
		static IPlayer& GetI2SPlayer();
	};
}

#endif /* ATE_AUDIO_PLAYER_FACTORY_H_ */
