/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: Queue.h
 * Brief: Queue abstraction layer for CMSIS OS V2
 * Module: Device
 */

#ifndef ATE_OSAL_QUEUE_H_
#define ATE_OSAL_QUEUE_H_

#include "cmsis_os2.h"
#include <cstdint>
#include <type_traits>

namespace ATE::OSAL
{

	template <class T>
	class Queue
	{
	public:
		Queue(std::size_t maxSize)
		{
			static_assert(std::is_trivially_copyable<T>::value,
				"Queues can only contain trivially copyable types");

			const osMessageQueueAttr_t attr =
			{
				name : nullptr,
				attr_bits : 0,
				cb_mem : nullptr,
				cb_size : 0,
				mq_mem : nullptr,
				mq_size : 0
			};
			impl = osMessageQueueNew (maxSize, sizeof(T), &attr);
			/* TODO Handle null ptr */
		}

		void Push(const T& element, std::uint32_t timeout = osWaitForever)
		{
			osMessageQueuePut(impl, &element, 0, timeout);
		}

		bool Pop(T& element, std::uint32_t timeout = osWaitForever)
		{
			return osMessageQueueGet(impl, &element, nullptr, timeout) == osOK;
		}

		~Queue()
		{
			osMessageQueueDelete(impl);
		}

	private:
		osMessageQueueId_t impl;
	};

}

#endif /* ATE_OSAL_QUEUE_H_ */
