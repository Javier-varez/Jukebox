/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: Mp3Decoder.cc
 * Brief: Mp3 Decoder implementation
 * Module: Audio
 */

#include "AudioPlayer/Decoder/Mp3Decoder.h"

namespace ATE::Audio
{
	unsigned int Mp3Decoder::DecoderCallback(
		    void * pMP3CompressedData,
			unsigned int nMP3DataSizeInChars,
			void * token )
	{
		Mp3Decoder& decoder = *reinterpret_cast<Mp3Decoder*>(token);
		auto data = reinterpret_cast<std::uint8_t*>(pMP3CompressedData);

		return decoder.file->Read(data, nMP3DataSizeInChars);
	}

	Mp3Decoder::Mp3Decoder(std::unique_ptr<Device::IFile> f) :
			IDecoder(std::move(f))
	{
		__HAL_RCC_CRC_CLK_ENABLE();
		SpiritMP3DecoderInit(&impl, &Mp3Decoder::DecoderCallback, NULL, this);
	}

	std::size_t Mp3Decoder::Decode(std::int16_t* buffer, std::size_t nSamples)
	{
		return SpiritMP3Decode(&impl, buffer, nSamples, &info);
	}

	std::uint32_t Mp3Decoder::GetSampleFrequency()
	{
		return info.nSampleRateHz;
	}
}
