/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: Mp3Decoder.h
 * Brief: Mp3 Decoder implementation
 * Module: Audio
 */


#ifndef ATE_AUDIO_PLAYER_MP3_DECODER_H_
#define ATE_AUDIO_PLAYER_MP3_DECODER_H_

#include "AudioPlayer/Decoder/IDecoder.h"
#include "spiritMP3Dec.h"

namespace ATE::Audio
{
	class Mp3Decoder : public IDecoder
	{
	public:
		Mp3Decoder(std::unique_ptr<Device::IFile> f);

		std::size_t Decode(std::int16_t* buffer, std::size_t nSamples) override;
		std::uint32_t GetSampleFrequency() override;

	private:
		TSpiritMP3Decoder impl;
		TSpiritMP3Info info;

		static unsigned int DecoderCallback(
			    void * pMP3CompressedData,
				unsigned int nMP3DataSizeInChars,
				void * token );
	};
}

#endif /* ATE_AUDIO_PLAYER_MP3_DECODER_H_ */
