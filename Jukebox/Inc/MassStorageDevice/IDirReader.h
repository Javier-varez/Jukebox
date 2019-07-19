/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: IDirReader.h
 * Brief: Interface for a Directory reader
 * Module: Device
 */

#ifndef ATE_DEVICE_IDIRREADER_H_
#define ATE_DEVICE_IDIRREADER_H_

#include <cstdint>
#include "MassStorageDevice/FileInfo.h"

namespace ATE::Device
{
	class IDirReader
	{
	public:
		virtual FileInfo ReadNext() = 0;

		virtual ~IDirReader() = default;
	};
}

#endif /* ATE_DEVICE_IDIRREADER_H_ */
