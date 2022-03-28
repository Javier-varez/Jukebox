/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: UniqueLock.h
 * Brief: Locker primitive for a Mutex object
 * Module: OSAL
 */

#ifndef ATE_OSAL_UNIQUE_LOCK_H_
#define ATE_OSAL_UNIQUE_LOCK_H_

#include "OS/Mutex.h"

namespace ATE::OSAL
{
    class UniqueLock
    {
    public:
        UniqueLock(Mutex &mutex);
        ~UniqueLock();

        UniqueLock() = delete;
        UniqueLock(const UniqueLock&) = delete;
        UniqueLock(UniqueLock&&) = delete;

    private:
        Mutex& impl;
    };
}

#endif /* ATE_OSAL_UNIQUE_LOCK_H_ */
