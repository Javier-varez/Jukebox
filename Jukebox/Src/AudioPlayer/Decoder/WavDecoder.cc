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
            ATE_LOG_ERROR("Error reading header");
            return;
        }

        ATE_LOG_DEBUG("SampleRate is %u", header.sampleRate);
        ATE_LOG_DEBUG("NumChannels %hu", header.numChannels);
        ATE_LOG_DEBUG("bitsPerSample %hu", header.bitsPerSample);
        ATE_LOG_DEBUG("byteRate %u", header.byteRate);
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
