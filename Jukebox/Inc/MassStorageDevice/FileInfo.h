/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: FileInfo.h
 * Brief: File Information Container
 * Module: Device
 */

#ifndef ATE_DEVICE_FILEINFO_H_
#define ATE_DEVICE_FILEINFO_H_

#include <cstdint>

namespace ATE::Device
{
	struct FileInfo
	{
		enum FileType
		{
			TYPE_NONE = 0,
			TYPE_FILE,
			TYPE_DIRECTORY
		};
		constexpr static std::size_t PATH_MAX_LENGTH = 256;
		constexpr static std::size_t NAME_MAX_LENGTH = 64;

		FileType type;
		std::size_t size;
		char path[PATH_MAX_LENGTH];

		FileInfo() :
			type(TYPE_NONE),
			size(0),
			path("")
		{

		}
	};
}

#endif /* ATE_DEVICE_FILEINFO_H_ */
