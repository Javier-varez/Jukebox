/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: IMassStorageDevice.cc
 * Brief: Interface for a mass storage device
 * Module: Device
 */

#include "MassStorageDevice/IMassStorageDevice.h"

namespace ATE::Device
{
    IMassStorageDevice::IMassStorageDevice() :
        available(false),
        mounted(false)
    {

    }

    bool IMassStorageDevice::IsAvailable()
    {
        OSAL::UniqueLock l (availableMutex);
        return available;
    }

    void IMassStorageDevice::SetAvailable(bool state)
    {
        {
            OSAL::UniqueLock l (availableMutex);

            if (available == state)
                return;

            available = state;
        }

        if (state)
        {
            Notify(IMassStorageDevice::MSD_Ready);
        }
        else
        {
            Notify(IMassStorageDevice::MSD_Removed);
        }
    }

    bool IMassStorageDevice::IsMounted()
    {
        OSAL::UniqueLock l (mountedMutex);
        return mounted;
    }

    void IMassStorageDevice::SetMounted(bool state)
    {
        OSAL::UniqueLock l (mountedMutex);
        mounted = state;
    }

    void IMassStorageDevice::Notify(IMassStorageDevice::Event event)
    {
        OSAL::UniqueLock l(callbackMutex);
        if (callback != nullptr)
            callback(event);
    }
}
