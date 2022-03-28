/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: IDecoder.cc
 * Brief: Decodes file into a PCM audio stream
 * Module: Audio
 */

#include "AudioPlayer/Decoder/IDecoder.h"
#include "Logger/Logger.h"

namespace ATE::Audio
{
    IDecoder::IDecoder(std::unique_ptr<Device::IFile> f) :
            file (std::move(f))
    {
    }
}
