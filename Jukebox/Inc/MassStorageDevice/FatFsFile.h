/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: FatFsFile.h
 * Brief: File wrapper for FatFs
 * Module: Device
 */

#ifndef ATE_DEVICE_FATFS_FILE_H_
#define ATE_DEVICE_FATFS_FILE_H_

#include "MassStorageDevice/IFile.h"
#include "ff.h"

namespace ATE::Device
{
    class FatFsFile : public IFile
    {
    public:
        FatFsFile(const char *path);
        virtual ~FatFsFile();
        std::size_t Read(std::uint8_t* buffer, std::size_t length) override;
        bool Exists() override;

    private:
        FIL file;
        bool exists;
    };
}

#endif /* ATE_DEVICE_FATFS_FILE_H_ */
