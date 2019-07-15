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

#ifndef ATE_OSAL_SEMAPHORE_H_
#define ATE_OSAL_SEMAPHORE_H_

#include "cmsis_os2.h"
#include <cstdint>

namespace ATE::OSAL
{
	class Semaphore
	{
	public:
		Semaphore(std::uint32_t max_count = 1);
		~Semaphore();
		void Take(std::uint32_t timeout = 0);
		void Give();

	private:
		osSemaphoreId_t impl;
	};
}

#endif /* ATE_OSAL_SEMAPHORE_H_ */
