/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: USBHostMSC.h
 * Brief: Usb host mass storage class device implementation
 * Module: Device
 */

#include "MassStorageDevice/USBHostMSC.h"
#include "MassStorageDevice/FatFsFile.h"
#include "MassStorageDevice/FatFsDirReader.h"

#include "Logger/Logger.h"

#include "stm32f4xx_hal.h"
#include "usbh_core.h"
#include "usbh_msc.h"

#include "ff.h"
#include "ff_gen_drv.h"
#include "usbh_diskio.h"

extern "C"
{
	extern USBH_HandleTypeDef hUSB_Host;
}

namespace ATE::Device
{
	USBHostMSC& USBHostMSC::GetInstance()
	{
		static USBHostMSC instance;
		return instance;
	}

	void USBHostMSC::USBHostCallback(USBH_HandleTypeDef*, std::uint8_t state)
	{
		USBHostMSC& usb = GetInstance();
		switch(state)
		{
			case HOST_USER_DISCONNECTION:
				usb.SetAvailable(false);
				usb.SetMounted(false);
				break;

			case HOST_USER_CLASS_ACTIVE:
				usb.SetAvailable(true);
				break;

			case HOST_USER_CONNECTION:
				break;

			default:
				break;
		}
	}

	bool USBHostMSC::Mount()
	{
		if (!IsAvailable())
		{
			return false;
		}
		else if (IsMounted())
		{
			return true;
		}

		if (f_mount(&FileSystem, USBHPath, 1) == FR_OK)
		{
			SetMounted(true);
			return true;
		}
		return false;
	}

	bool USBHostMSC::Unmount()
	{
		if (!IsAvailable())
		{
			return false;
		}
		else if (!IsMounted())
		{
			return true;
		}

		if (f_mount(nullptr, USBHPath, 1) == FR_OK)
		{
			SetMounted(false);
			return true;
		}
		return false;
	}

	std::unique_ptr<IFile> USBHostMSC::OpenFile(char *path)
	{
		std::unique_ptr<FatFsFile> file = std::make_unique<FatFsFile>(path);
		return file;
	}

	std::unique_ptr<IDirReader> USBHostMSC::OpenDir(char *path)
	{
		std::unique_ptr<FatFsDirReader> dirReader = std::make_unique<FatFsDirReader>(path);
		return dirReader;
	}

	void USBHostMSC::Initialize()
	{
		OSAL::UniqueLock l (initializedMutex);
		if (initialized) return;

		FATFS_LinkDriver(&USBH_Driver, USBHPath);
		USBHPath[4] = '\0';

		Logger::GetLogger().Log(
				Logger::LogLevel_DEBUG,
				"Registered USB MSC as Drive %s\n",
				USBHPath
			);

		if (USBH_Init(&hUSB_Host, USBHostMSC::USBHostCallback, HOST_FS) != USBH_OK)
		{
			Logger::GetLogger().Log(
					Logger::LogLevel_ERROR,
					"Unable to initialize USB FS\n");
			return;
		}
		if (USBH_RegisterClass(&hUSB_Host, USBH_MSC_CLASS) != USBH_OK)
		{
			Logger::GetLogger().Log(
					Logger::LogLevel_ERROR,
					"Unable to register MSC Class\n");
			return;
		}
		if (USBH_Start(&hUSB_Host) != USBH_OK)
		{
			Logger::GetLogger().Log(
					Logger::LogLevel_ERROR,
					"Unable to start USB Host operation\n");
			return;
		}

		initialized = true;
	}

	USBHostMSC::USBHostMSC()
	{

	}

}

