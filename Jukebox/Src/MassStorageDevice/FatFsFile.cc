/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: FatFsFile.cc
 * Brief: File wrapper for FatFs
 * Module: Device
 */

#include "MassStorageDevice/FatFsFile.h"
#include "Logger/Logger.h"

namespace ATE::Device
{
	FatFsFile::FatFsFile(const char *path)
	{
		if (f_open(&file, path, FA_READ | FA_WRITE) != FR_OK)
		{
			ATE::Logger::GetLogger().Log(
					ATE::Logger::LogLevel_WARNING,
					"Couldn't open file %s\n", path);
			exists = false;
		}
		exists = true;
	}

	FatFsFile::~FatFsFile()
	{
		f_close(&file);
	}

	std::size_t FatFsFile::Read(std::uint8_t* buffer, std::size_t length)
	{
		std::size_t read = 0;
		if (f_read(&file, buffer, length, &read) != FR_OK)
		{
			return 0;
		}
		return read;
	}

	bool FatFsFile::Exists()
	{
		return exists;
	}
}


