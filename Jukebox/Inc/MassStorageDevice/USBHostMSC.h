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

#ifndef ATE_DEVICE_USBHOSTMSC_H_
#define ATE_DEVICE_USBHOSTMSC_H_

#include "IMassStorageDevice.h"

#include "usbh_def.h"
#include "ff.h"

namespace ATE::Device
{
	class USBHostMSC : public IMassStorageDevice
	{
	public:
		static USBHostMSC& GetInstance();

		void Initialize() override;
		bool Mount() override;
		bool Unmount() override;
		std::unique_ptr<IFile> OpenFile(char *path) override;
		std::unique_ptr<IDirReader> OpenDir(char *path) override;

	private:
		USBHostMSC();
		static void USBHostCallback(USBH_HandleTypeDef*, std::uint8_t);

		char USBHPath[5];
		FATFS FileSystem;

		bool initialized;
		OSAL::Mutex initializedMutex;
	};

}



#endif /* ATE_DEVICE_USBHOSTMSC_H_ */
