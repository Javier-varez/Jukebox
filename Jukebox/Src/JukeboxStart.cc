/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: JukeboxStart.h
 * Brief: Startup module
 * Module: Startup
 */

#include "JukeboxStart.h"
#include "OS/Task.h"
#include "Logger/Logger.h"
#include "KeyPad/KeyPadFactory.h"

namespace {
	bool keyStateChanged(char key, ATE::Device::IKeyPad::KeyState state)
	{
		ATE::Logger::GetLogger().Log(ATE::Logger::LogLevel_DEBUG, "Received %c, state %d\r\n", key, state);
	}
}

namespace ATE::Jukebox
{
	constexpr static char TASK_NAME[] = "JukeboxTask";

	class JukeboxTask : public OSAL::Task
	{
	public:
		JukeboxTask():
			Task(TASK_NAME, osPriorityRealtime, 1000)
		{

		}

		virtual void Init() override
		{
			Device::IKeyPad &keypad = ATE::Device::KeyPadFactory::GetAnalogKeypad();
			keypad.Subscribe(keyStateChanged);
		}
		virtual bool Run() override
		{
			ATE::Logger &logger = ATE::Logger::GetLogger();
			logger.Log(ATE::Logger::LogLevel_ERROR, "It works!!\r\n");

			Delay(1000);
			return true;
		}
	private:

	};
}

extern "C"
void JukeboxStart()
{
	static ATE::Jukebox::JukeboxTask task;
}
