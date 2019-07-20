/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: WavDecoder.h
 * Brief: WAVE Decoder implementation
 * Module: Audio
 */

#include "AudioPlayer/Decoder/WavDecoder.h"
#include "Logger/Logger.h"

namespace ATE::Audio
{
	WavDecoder::WavDecoder(std::unique_ptr<Device::IFile> f)
		: IDecoder(std::move(f))
	{
		if (file->Read(reinterpret_cast<std::uint8_t*>(&header), sizeof(header)) != sizeof(header))
		{
			Logger::GetLogger().Log(Logger::LogLevel_ERROR, "%s: Error reading header\n", __func__);
			return;
		}

		Logger::GetLogger().Log(Logger::LogLevel_DEBUG, "%s: SampleRate is %d\n", __func__, header.sampleRate);
		Logger::GetLogger().Log(Logger::LogLevel_DEBUG, "%s: NumChannels %d\n", __func__, header.numChannels);
		Logger::GetLogger().Log(Logger::LogLevel_DEBUG, "%s: bitsPerSample %d\n", __func__, header.bitsPerSample);
		Logger::GetLogger().Log(Logger::LogLevel_DEBUG, "%s: byteRate %d\n", __func__, header.byteRate);
	}

	std::size_t WavDecoder::Decode(std::int16_t* buffer, std::size_t nSamples)
	{
		return file->Read(reinterpret_cast<std::uint8_t*>(buffer),
				nSamples * header.numChannels * sizeof(std::int16_t))
				/ (header.numChannels * sizeof(std::int16_t));
	}

	std::uint32_t WavDecoder::GetSampleFrequency()
	{
		return header.sampleRate;
	}
}
