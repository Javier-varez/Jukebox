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
				LOG_DEBUG(Logger::GetLogger(), "USB Disconnected");
				usb.SetAvailable(false);
				usb.SetMounted(false);
				break;

			case HOST_USER_CLASS_ACTIVE:
				LOG_DEBUG(Logger::GetLogger(), "USB Available");
				usb.SetAvailable(true);
				break;

			case HOST_USER_CONNECTION:
				LOG_DEBUG(Logger::GetLogger(), "USB Connected");
				break;

			default:
				break;
		}
	}

	bool USBHostMSC::Mount()
	{
		if (!IsAvailable())
		{
			LOG_WARNING(Logger::GetLogger(), "Cannot mount, it is not available");
			return false;
		}
		else if (IsMounted())
		{
			LOG_WARNING(Logger::GetLogger(), "It is already mounted");
			return true;
		}

		if (f_mount(&FileSystem, USBHPath, 1) == FR_OK)
		{
			LOG_WARNING(Logger::GetLogger(), "Mount success");
			SetMounted(true);
			return true;
		}
		LOG_WARNING(Logger::GetLogger(), "Mount error");
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

	std::unique_ptr<IFile> USBHostMSC::OpenFile(const char *path)
	{
		std::unique_ptr<FatFsFile> file = std::make_unique<FatFsFile>(path);
		return file;
	}

	std::unique_ptr<IDirReader> USBHostMSC::OpenDir(const char *path)
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

		LOG_DEBUG(Logger::GetLogger(),
				"Registered USB MSC as Drive %s",
				USBHPath
			);

		if (USBH_Init(&hUSB_Host, USBHostMSC::USBHostCallback, HOST_FS) != USBH_OK)
		{
			LOG_ERROR(Logger::GetLogger(),
					"Unable to initialize USB FS");
			return;
		}
		if (USBH_RegisterClass(&hUSB_Host, USBH_MSC_CLASS) != USBH_OK)
		{
			LOG_ERROR(Logger::GetLogger(),
					"Unable to register MSC Class");
			return;
		}
		if (USBH_Start(&hUSB_Host) != USBH_OK)
		{
			LOG_ERROR(Logger::GetLogger(),
					"Unable to start USB Host operation");
			return;
		}

		initialized = true;
	}

	USBHostMSC::USBHostMSC()
	{

	}

}

