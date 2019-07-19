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
#include <memory>

namespace ATE::Audio
{
	class IPlayer
	{
	public:
		virtual bool Play(std::unique_ptr<IDecoder> decoder) = 0;

		virtual void Pause() = 0;
		virtual void Resume() = 0;
		virtual void Stop() = 0;

		virtual void SetVolume(std::uint8_t volume) = 0;
	};
}

#endif /* ATE_IAUDIO_PLAYER_H_ */
