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

#ifndef ATE_AUDIO_PLAYER_WAV_DECODER_H_
#define ATE_AUDIO_PLAYER_WAV_DECODER_H_

#include "AudioPlayer/Decoder/IDecoder.h"

namespace ATE::Audio
{
    class WavDecoder : public IDecoder
    {
    public:

        #pragma pack(push, 1)
        struct Header {
            char chunkID[4];        // 0
            uint32_t chunkSize;        // 4
            char format[4];            // 8
            char subchunkID1[4];    // 12
            uint32_t subchunk1Size;    // 16
            uint16_t audioFormat;    // 20
            uint16_t numChannels;    // 22
            uint32_t sampleRate;    // 24
            uint32_t byteRate;        // 28
            uint16_t blockAlign;    // 32
            uint16_t bitsPerSample;    // 34
            char subchunkID2[4];    // 36
            uint32_t subchunk2Size;    // 40
            // uint8_t data[subchunk2Size]; // 44
        };
        #pragma pack(pop)

        WavDecoder(std::unique_ptr<Device::IFile> f);

        std::size_t Decode(std::int16_t* buffer, std::size_t nSamples) override;
        std::uint32_t GetSampleFrequency() override;

    private:
        Header header;
    };
}

#endif /* ATE_AUDIO_PLAYER_WAV_DECODER_H_ */
