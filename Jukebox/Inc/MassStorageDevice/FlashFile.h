/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: FlashFile.cc
 * Brief: File wrapper for internal flash
 * Module: Device
 */

#ifndef ATE_DEVICE_FLASH_FILE_H_
#define ATE_DEVICE_FLASH_FILE_H_

#include "MassStorageDevice/IFile.h"

namespace ATE::Device
{
    class FlashFile : public IFile
    {
    public:
        FlashFile(const std::uint8_t *data, std::size_t length);

        std::size_t Read(std::uint8_t* buffer, std::size_t length) override;
        bool Exists() override;

    private:
        const std::uint8_t *Ptr;
        const std::size_t FileLength;

        std::size_t Offset;
    };
}



#endif /* ATE_DEVICE_FLASH_FILE_H_ */
