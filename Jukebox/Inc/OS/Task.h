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

#ifndef ATE_OSAL_TASK_H_
#define ATE_OSAL_TASK_H_

#include "cmsis_os2.h"
#include <cstdint>

namespace ATE::OSAL
{
    class Task
    {
    public:
        Task(const char *name, osPriority_t prio, std::size_t stackSize);

        static void Delay(std::uint32_t ms);

    protected:
        virtual void Init() = 0;
        virtual bool Run() = 0;

    private:
        osThreadId_t tid;
        static void Impl(void*);
    };
}

#endif /* ATE_OSAL_TASK_H_ */
