/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: FatFsDirReader.h
 * Brief: Directory reader for FATFS
 * Module: Device
 */

#include "MassStorageDevice/FatFsDirReader.h"
#include "Logger/Logger.h"

#include <cstring>

namespace ATE::Device
{
	FatFsDirReader::FatFsDirReader(const char *path)
	{
		if (f_opendir(&directory,  path) != FR_OK)
		{
			Logger::GetLogger().Log(Logger::LogLevel_WARNING, "Unable to find path %s\n", path);
			return;
		}
	}

	FatFsDirReader::~FatFsDirReader()
	{
		f_closedir(&directory);
	}

	FileInfo FatFsDirReader::ReadNext()
	{
		FileInfo info;
		if (f_readdir(&directory, &fileinfo) == FR_OK)
		{
			if (fileinfo.fname[0] == '\0')
			{
				return info;
			}

			info.type = (fileinfo.fattrib & AM_DIR) != 0 ?
					FileInfo::TYPE_DIRECTORY : FileInfo::TYPE_FILE;
			std::strncpy(info.path, fileinfo.fname, FileInfo::PATH_MAX_LENGTH);
		}
		return info;
	}

}
