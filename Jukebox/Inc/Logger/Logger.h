/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: Logger.h
 * Brief: Logger implementation using Postform
 * Module: Logger
 */

#ifndef ATE_LOGGER_LOGGER_H_
#define ATE_LOGGER_LOGGER_H_

#ifdef __cplusplus

#include "postform/rtt/transport.h"
#include "postform/serial_logger.h"

namespace ATE::Logger
{
	Postform::SerialLogger<Postform::Rtt::Transport>* GetLogger();

	void SetLevel(Postform::LogLevel level);
}

#else 

void log_error(const char* str);

#endif

#endif /* ATE_LOGGER_LOGGER_H_ */
