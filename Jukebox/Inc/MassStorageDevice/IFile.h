/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: IFile.h
 * Brief: Interface for a File inside the storage device
 * Module: Device
 */

#ifndef ATE_DEVICE_IFILE_H_
#define ATE_DEVICE_IFILE_H_

#include <cstdint>

namespace ATE::Device
{
	class IFile
	{
	public:
		virtual std::size_t Read(std::uint8_t* buffer, std::size_t length) = 0;
		virtual bool Exists();

		virtual ~IFile() = default;
	};
}

#endif /* ATE_DEVICE_IFILE_H_ */
