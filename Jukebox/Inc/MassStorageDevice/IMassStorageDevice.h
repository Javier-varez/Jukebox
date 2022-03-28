/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: IMassStorageDevice.h
 * Brief: Interface for a mass storage device
 * Module: Device
 */

#ifndef ATE_DEVICE_IMASSSTORAGEDEVICE_H_
#define ATE_DEVICE_IMASSSTORAGEDEVICE_H_

#include <functional>
#include <memory>

#include "OS/Mutex.h"
#include "OS/UniqueLock.h"
#include "MassStorageDevice/IFile.h"
#include "MassStorageDevice/IDirReader.h"

namespace ATE::Device
{
    class IMassStorageDevice
    {
    public:
        enum Event
        {
            MSD_Ready = 0,
            MSD_Removed
        };

        using eventCb_t = std::function<void(Event)>;

        void Subscribe(const eventCb_t& eventCb)
        {
            OSAL::UniqueLock l(callbackMutex);
            callback = eventCb;
        }

        IMassStorageDevice();

        bool IsAvailable();
        bool IsMounted();

        virtual void Initialize() = 0;

        virtual bool Mount() = 0;
        virtual bool Unmount() = 0;

        virtual std::unique_ptr<IFile> OpenFile(const char *path) = 0;
        virtual std::unique_ptr<IDirReader> OpenDir(const char *path) = 0;

        virtual ~IMassStorageDevice() = default;

    private:
        bool available;
        bool mounted;
        OSAL::Mutex availableMutex;
        OSAL::Mutex mountedMutex;

        eventCb_t callback;
        OSAL::Mutex callbackMutex;

        void Notify(Event event);

    protected:
        void SetAvailable(bool);
        void SetMounted(bool);
    };
}


#endif /* ATE_DEVICE_IMASSSTORAGEDEVICE_H_ */
