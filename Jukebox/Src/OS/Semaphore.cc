/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: Semaphore.h
 * Brief: Semaphore abstraction layer for CMSIS OS V2
 * Module: Device
 */

#include "OS/Semaphore.h"
#include "FreeRTOS.h"

namespace ATE::OSAL
{
    Semaphore::Semaphore(std::uint32_t max_count)
    {
        const osSemaphoreAttr_t attr =
        {
            name : nullptr,
            attr_bits : 0,
            cb_mem : 0,
            cb_size : 0
        };
        impl = osSemaphoreNew(max_count, 0, &attr);
    }

    Semaphore::~Semaphore()
    {
        osSemaphoreDelete(impl);
    }

    void Semaphore::Take(std::uint32_t timeout)
    {
        if (timeout == 0) timeout = portMAX_DELAY;
        osSemaphoreAcquire(impl, timeout);
    }

    void Semaphore::Give()
    {
        osSemaphoreRelease(impl);
    }
}
