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

#include "MassStorageDevice/FlashFile.h"
#include <cstring>

namespace ATE::Device
{
	FlashFile::FlashFile(const std::uint8_t *data, std::size_t length) :
			Ptr(data),
			FileLength(length),
			Offset(0)
	{

	}

	std::size_t FlashFile::Read(std::uint8_t* buffer, std::size_t length)
	{
		std::size_t actualLength = ((FileLength - Offset)) > length ?
										length :
										(FileLength - Offset);

		std::memcpy(buffer, &Ptr[Offset], actualLength);
		Offset += actualLength;

		return actualLength;
	}

	bool FlashFile::Exists()
	{
		return true;
	}
}
