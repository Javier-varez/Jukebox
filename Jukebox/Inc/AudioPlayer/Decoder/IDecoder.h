/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: IDecoder.h
 * Brief: Decodes file into a PCM audio stream
 * Module: Audio
 */


#ifndef ATE_AUDIO_PLAYER_IDECODER_H_
#define ATE_AUDIO_PLAYER_IDECODER_H_

#include <cstdint>
#include <functional>
#include <memory>

#include "MassStorageDevice/IFile.h"

namespace ATE::Audio
{
    class IDecoder
    {
    public:
        IDecoder(std::unique_ptr<Device::IFile> f);
        virtual std::size_t Decode(std::int16_t* buffer, std::size_t nSamples) = 0;

        virtual std::uint32_t GetSampleFrequency() = 0;

    protected:
        std::unique_ptr<Device::IFile> file;
    };
}


#endif /* ATE_AUDIO_PLAYER_IDECODER_H_ */
