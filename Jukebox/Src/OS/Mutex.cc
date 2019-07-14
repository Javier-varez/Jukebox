/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: Mutex.h
 * Brief: C++ Wrapper for underlying CMSIS OS Mutex
 * Module: OSAL
 */

#include "OS/Mutex.h"

namespace ATE::OSAL
{

	Mutex::Mutex()
	{
		const osMutexAttr_t attr =
		{
			.name = nullptr,
			.attr_bits = osMutexPrioInherit,
			.cb_mem =  nullptr,
			.cb_size = 0
		};

		impl = osMutexNew(&attr);
		/* TODO: Handle null ptr */
	}

	Mutex::~Mutex()
	{
		osMutexDelete(impl);
	}

	void Mutex::Lock(std::uint32_t timeout)
	{
		osMutexAcquire(impl, timeout);
	}

	void Mutex::Unlock()
	{
		osMutexRelease(impl);
	}
}
