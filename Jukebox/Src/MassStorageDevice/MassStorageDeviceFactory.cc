/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: MassStorageDeviceFactory.cc
 * Brief: Factory for mass storage devices
 * Module: Device
 */

#include "MassStorageDevice/MassStorageDeviceFactory.h"
#include "MassStorageDevice/USBHostMSC.h"

namespace ATE::Device
{
	IMassStorageDevice& MassStorageDeviceFactory::GetUSBHostStorage()
	{
		USBHostMSC& msc = USBHostMSC::GetInstance();
		msc.Initialize();
		return msc;
	}

}
