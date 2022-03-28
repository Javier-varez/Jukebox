/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: MassStorageDeviceFactory.h
 * Brief: Factory for mass storage devices
 * Module: Device
 */

#ifndef ATE_DEVICE_MASS_STORAGE_DEVICE_FACTORY_H_
#define ATE_DEVICE_MASS_STORAGE_DEVICE_FACTORY_H_

#include "MassStorageDevice/IMassStorageDevice.h"

namespace ATE::Device
{
    class MassStorageDeviceFactory
    {
    public:
        static IMassStorageDevice& GetUSBHostStorage();
    };
}

#endif /* ATE_DEVICE_MASS_STORAGE_DEVICE_FACTORY_H_ */
