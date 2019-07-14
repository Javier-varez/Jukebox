/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: Logger.h
 * Brief: Logger implementation using uart in DMA mode
 * Module: Logger
 */

#ifndef ATE_LOGGER_LOGGER_H_
#define ATE_LOGGER_LOGGER_H_

#include "OS/Task.h"
#include "OS/Mutex.h"
#include "OS/Queue.h"

namespace ATE
{
	class Logger : public OSAL::Task
	{
	public:
		enum LogLevel
		{
			LogLevel_DEBUG = 0,
			LogLevel_INFO,
			LogLevel_WARNING,
			LogLevel_ERROR,
		};
		struct LogMsg
		{
			constexpr static std::size_t MAX_LENGTH = 20;
			char msg[MAX_LENGTH];
		};


		static Logger& GetLogger();

		void SetLevel(LogLevel level);
		void Log(LogLevel level, const char* format, ... );

		Logger(const Logger&) = delete;
		Logger operator=(const Logger&) = delete;
		Logger(Logger&&) = delete;
	private:
		Logger();
		void Init() override;
		bool Run() override;

		LogLevel level;
		OSAL::Queue<LogMsg> queue;
		OSAL::Mutex mutex;
	};
}



#endif /* ATE_LOGGER_LOGGER_H_ */
