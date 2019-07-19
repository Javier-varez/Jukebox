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

#ifndef ATE_DEVICE_FATFSDIRREADER_H_
#define ATE_DEVICE_FATFSDIRREADER_H_

#include "MassStorageDevice/IDirReader.h"

#include "ff.h"

namespace ATE::Device
{
	class FatFsDirReader : public IDirReader
	{
	public:
		FatFsDirReader(char *path);
		~FatFsDirReader();

		FileInfo ReadNext() override;

	private:
		DIR directory;
		FILINFO fileinfo;
	};
}

#endif /* ATE_DEVICE_FATFSDIRREADER_H_ */
