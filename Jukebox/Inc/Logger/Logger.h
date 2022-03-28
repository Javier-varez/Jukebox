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

#include "postform/rtt/transport.h"
#include "postform/serial_logger.h"

#define ATE_LOG_DEBUG(...) LOG_DEBUG(::ATE::Logger::GetLogger(), __VA_ARGS__)
#define ATE_LOG_INFO(...) LOG_INFO(::ATE::Logger::GetLogger(), __VA_ARGS__)
#define ATE_LOG_WARNING(...) LOG_WARNING(::ATE::Logger::GetLogger(), __VA_ARGS__)
#define ATE_LOG_ERROR(...) LOG_ERROR(::ATE::Logger::GetLogger(), __VA_ARGS__)

namespace ATE::Logger
{
    Postform::SerialLogger<Postform::Rtt::Transport>* GetLogger();
    void SetLevel(Postform::LogLevel level);
}

#endif /* ATE_LOGGER_LOGGER_H_ */
