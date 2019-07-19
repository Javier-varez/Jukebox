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

#include <functional>

#include "JukeboxStart.h"
#include "OS/Task.h"
#include "OS/Semaphore.h"
#include "Logger/Logger.h"
#include "KeyPad/KeyPadFactory.h"
#include "MassStorageDevice/MassStorageDeviceFactory.h"
#include "AudioPlayer/AudioPlayerFactory.h"
#include "AudioPlayer/Decoder/Mp3Decoder.h"

namespace {
	bool keyStateChanged(char key, ATE::Device::IKeyPad::KeyState state)
	{
		ATE::Logger::GetLogger().Log(ATE::Logger::LogLevel_DEBUG, "Received %c, state %d\r\n", key, state);
		return true;
	}


}

namespace ATE::Jukebox
{
	constexpr static char TASK_NAME[] = "JukeboxTask";

	class JukeboxTask : public OSAL::Task
	{
	public:
		JukeboxTask():
			Task(TASK_NAME, osPriorityRealtime, 4096)
		{

		}

		void massStorageDevCb(ATE::Device::IMassStorageDevice::Event event)
		{
			switch (event)
			{
			case ATE::Device::IMassStorageDevice::MSD_Ready:
				ATE::Logger::GetLogger().Log(ATE::Logger::LogLevel_DEBUG, "MSDCallback ready\r\n");
				usbSemaphore.Give();
				break;
			case ATE::Device::IMassStorageDevice::MSD_Removed:
				ATE::Logger::GetLogger().Log(ATE::Logger::LogLevel_DEBUG, "MSDCallback removed\r\n");
				break;
			}
		}

		virtual void Init() override
		{
			Device::IKeyPad &keypad = ATE::Device::KeyPadFactory::GetAnalogKeypad();
			keypad.Subscribe(keyStateChanged);
			Device::IMassStorageDevice& msd = Device::MassStorageDeviceFactory::GetUSBHostStorage();
			msd.Subscribe(std::bind(&JukeboxTask::massStorageDevCb, this, std::placeholders::_1));

			usbSemaphore.Take();

			ATE::Logger::GetLogger().Log(ATE::Logger::LogLevel_DEBUG, "Trying to mount\r\n");
			if (msd.Mount())
			{
				ATE::Logger::GetLogger().Log(ATE::Logger::LogLevel_DEBUG, "Device Mounted\r\n");

				auto dir = msd.OpenDir("/");
				Device::FileInfo info;
				do
				{
					info = dir->ReadNext();
					ATE::Logger::GetLogger().Log(ATE::Logger::LogLevel_DEBUG, "Found file %s\n", info.path);
				} while(info.type != Device::FileInfo::TYPE_NONE);

				std::uint8_t buffer[4];
				auto file = msd.OpenFile("/A1.mp3");
				file->Read(buffer, 3);
				buffer[3] = '\0';
				ATE::Logger::GetLogger().Log(ATE::Logger::LogLevel_DEBUG, "File Hdr %s\r\n", reinterpret_cast<char*>(buffer));
			}
			else
			{
				ATE::Logger::GetLogger().Log(ATE::Logger::LogLevel_DEBUG, "Mount failed\r\n");
			}

			Audio::IPlayer& player = Audio::PlayerFactory::GetI2SPlayer();

			player.Play(std::make_unique<ATE::Audio::Mp3Decoder>(msd.OpenFile("A1.mp3")));

		}
		virtual bool Run() override
		{
			Delay(1000);
			return true;
		}

	private:
		OSAL::Semaphore usbSemaphore;
	};
}

extern "C"
void JukeboxStart()
{
	osKernelInitialize(); // Initialize CMSIS-RTOS
	{
		static ATE::Jukebox::JukeboxTask task;
		osKernelStart();
	}
}
