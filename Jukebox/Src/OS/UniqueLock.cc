/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: UniqueLock.cc
 * Brief: Locker primitive for a Mutex object
 * Module: OSAL
 */

#include "OS/UniqueLock.h"

namespace ATE::OSAL
{
	UniqueLock::UniqueLock(Mutex &mutex):
			impl(mutex)
	{
		impl.Lock();
	}

	UniqueLock::~UniqueLock()
	{
		impl.Unlock();
	}
}
