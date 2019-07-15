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

namespace ATE::OSAL
{
	Semaphore::Semaphore()
	{
		const osSemaphoreAttr_t attr =
		{
			name : nullptr,
			attr_bits : 0,
			cb_mem : 0,
			cb_size : 0
		};
		impl = osSemaphoreNew(1, 0, &attr);
	}

	Semaphore::~Semaphore()
	{
		osSemaphoreDelete(impl);
	}

	void Semaphore::Take(std::uint32_t timeout)
	{
		osSemaphoreAcquire(impl, timeout);
	}

	void Semaphore::Give()
	{
		osSemaphoreRelease(impl);
	}
}
