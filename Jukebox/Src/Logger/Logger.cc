/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: Logger.cc
 * Brief: Logger implementation using uart in DMA mode
 * Module: Logger
 */

#include "Logger/Logger.h"
#include "OS/UniqueLock.h"

#include <cstdio>
#include <cstdarg>
#include <cstring>

#include "usart.h"

namespace ATE
{
	constexpr static size_t MAX_QUEUE_LENGTH = 10;
	constexpr static char TASK_NAME[] = "Logger";

	Logger& Logger::GetLogger()
	{
		static Logger logger;
		return logger;
	}

	Logger::Logger() :
		Task(TASK_NAME, osPriorityHigh, 1024),
		level(LogLevel_DEBUG),
		queue(MAX_QUEUE_LENGTH)
	{

	}

	void Logger::SetLevel(LogLevel level)
	{
		OSAL::UniqueLock lock(mutex);
		this->level = level;
	}

	void Logger::Log(LogLevel level, const char* format, ... )
	{
		OSAL::UniqueLock lock(mutex);

		if (level >= this->level)
		{
			LogMsg msg;

			std::va_list args;
			va_start(args, format);
			std::vsnprintf(reinterpret_cast<char*>(msg.msg), LogMsg::MAX_LENGTH, format, args);
			va_end(args);

			queue.Push(msg, 0);
		}
	}

	void Logger::Init()
	{

	}

	bool Logger::Run()
	{
		LogMsg msg;

		if (queue.Pop(msg))
		{
			HAL_UART_Transmit(&huart2, reinterpret_cast<std::uint8_t*>(msg.msg), std::strlen(msg.msg), 1000);
		}
		return true;
	}
}
