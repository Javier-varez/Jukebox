/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: Task.h
 * Brief: Wrapper for underlying OS Task
 * Module: OSAL
 */

#include "OS/Task.h"

namespace ATE::OSAL
{
	void Task::Impl(void* arg)
	{
		Task &task = *reinterpret_cast<Task*>(arg);

		task.Init();

		while (true)
		{
			task.Run();
		}
	}

	Task::Task(const char *name, osPriority_t prio, std::size_t stackSize)
	{
		const osThreadAttr_t thread_attr =
		{
			name : name,
			attr_bits : osThreadDetached,
			cb_mem : nullptr,
			cb_size : 0,
			stack_mem : nullptr,
			stack_size : stackSize,
			priority : prio,
			tz_module : 0,
			reserved : 0
		};

		tid = osThreadNew(Task::Impl, this, &thread_attr);
		/* TODO: Handle null ptr */
	}

	void Task::Delay(std::uint32_t ms)
	{
		osDelay(ms);
	}
}
