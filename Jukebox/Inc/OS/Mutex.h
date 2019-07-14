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

#ifndef ATE_OSAL_MUTEX_H_
#define ATE_OSAL_MUTEX_H_

#include "cmsis_os2.h"
#include <cstdint>

namespace ATE::OSAL
{
	class Mutex
	{
	public:
		Mutex();
		~Mutex();
		void Lock(std::uint32_t timeout = 0);
		void Unlock();

		Mutex(const Mutex&) = delete;
		Mutex(Mutex&&) = delete;
	private:
		osMutexId_t impl;
	};
}

#endif /* ATE_OSAL_MUTEX_H_ */
