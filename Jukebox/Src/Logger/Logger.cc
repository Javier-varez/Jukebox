/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: Logger.cc
 * Brief: Logger implementation using Postform
 * Module: Logger
 */

#include "Logger/Logger.h"
#include "OS/UniqueLock.h"

#include <cstdio>
#include <cstdarg>
#include <cstring>

#include "usart.h"

#include "postform/rtt/transport.h"
#include "postform/serial_logger.h"
#include "postform/config.h"

static UNINIT std::array<std::uint8_t, 1024> s_up_buffer;
static std::array<Postform::Rtt::ChannelDescriptor, 1> s_up_descriptors{
    {{"postform_channel", s_up_buffer}}};

Postform::Rtt::ControlBlock<1, 0> _SEGGER_RTT{s_up_descriptors, {}};

static Postform::Rtt::Transport transport{&_SEGGER_RTT.up_channels[0]};
static Postform::SerialLogger<Postform::Rtt::Transport> logger{&transport};

namespace Postform {
uint64_t getGlobalTimestamp() {
  return HAL_GetTick();
}
}  // namespace Postform

DECLARE_POSTFORM_CONFIG(.timestamp_frequency = 1'000);

namespace ATE::Logger
{
	Postform::SerialLogger<Postform::Rtt::Transport>* GetLogger()
	{
		return &logger;
	}

	void SetLevel(Postform::LogLevel level)
	{
		logger.setLevel(level);
	}
}

extern "C" void log_error(const char* str) {
	LOG_ERROR(ATE::Logger::GetLogger(), "%s", str);
}
