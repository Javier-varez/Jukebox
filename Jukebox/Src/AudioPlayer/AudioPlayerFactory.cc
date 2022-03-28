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

#include "AudioPlayer/AudioPlayerFactory.h"
#include "AudioPlayer/I2SAudioPlayer.h"

namespace ATE::Audio
{
    IPlayer& PlayerFactory::GetI2SPlayer()
    {
        return I2SPlayer::GetPlayer();
    }
}
