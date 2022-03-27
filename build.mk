LOCAL_DIR := $(call current-dir)

include $(CLEAR_VARS)

LOCAL_NAME := jukebox_fw.elf

CROSS_COMPILE := arm-none-eabi-
CC := $(CROSS_COMPILE)gcc
CXX := $(CROSS_COMPILE)g++
AS := $(CROSS_COMPILE)as

LOCAL_CFLAGS := \
    -mcpu=cortex-m4 \
    -mfloat-abi=softfp \
    -mfpu=fpv4-sp-d16 \
    -mthumb \
    -specs=nosys.specs \
    -DUSE_HAL_DRIVER \
    -DSTM32F411xE \
    -I$(LOCAL_DIR)/Core/Inc \
    -I$(LOCAL_DIR)/FATFS/App \
    -I$(LOCAL_DIR)/FATFS/Target \
    -I$(LOCAL_DIR)/USB_HOST/App \
    -I$(LOCAL_DIR)/USB_HOST/Target \
    -I$(LOCAL_DIR)/Drivers/CMSIS/Include \
    -I$(LOCAL_DIR)/Drivers/CMSIS/Device/ST/STM32F4xx/Include \
    -I$(LOCAL_DIR)/Drivers/STM32F4xx_HAL_Driver/Inc \
    -I$(LOCAL_DIR)/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy \
    -I$(LOCAL_DIR)/Drivers/BSP/STM32F411E-Discovery/ \
    -I$(LOCAL_DIR)/Drivers/AudioDecoders \
    -I$(LOCAL_DIR)/Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc \
    -I$(LOCAL_DIR)/Middlewares/ST/STM32_USB_Host_Library/Core/Inc \
    -I$(LOCAL_DIR)/Middlewares/Third_Party/FatFs/src \
    -I$(LOCAL_DIR)/Middlewares/Third_Party/FreeRTOS/Source/include \
    -I$(LOCAL_DIR)/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 \
    -I$(LOCAL_DIR)/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F \
    -I$(LOCAL_DIR)/Jukebox/Inc \
    -Os \
    -g3 \
    -Wall \
    -ffunction-sections \
    -fdata-sections

LOCAL_CXXFLAGS := \
    $(LOCAL_CFLAGS) \
    -std=gnu++17 \
    -fno-exceptions \
    -fno-rtti

LOCAL_LDFLAGS := \
    -Wl,--gc-sections \
    -lc_nano \
    -lnosys \
    -l_mp3decoder_cortex_m4_v2.2.0 \
    -LDrivers/AudioDecoders

LOCAL_LINKER_FILE := \
    $(LOCAL_DIR)/STM32F411VETX_FLASH.ld

LOCAL_SRC := \
    $(LOCAL_DIR)/Startup/startup_stm32f411vetx.s \
    $(LOCAL_DIR)/Core/Src/adc.c \
    $(LOCAL_DIR)/Core/Src/crc.c \
    $(LOCAL_DIR)/Core/Src/dma.c \
    $(LOCAL_DIR)/Core/Src/freertos.c \
    $(LOCAL_DIR)/Core/Src/gpio.c \
    $(LOCAL_DIR)/Core/Src/main.c \
    $(LOCAL_DIR)/Core/Src/stm32f4xx_hal_msp.c \
    $(LOCAL_DIR)/Core/Src/stm32f4xx_hal_timebase_tim.c \
    $(LOCAL_DIR)/Core/Src/stm32f4xx_it.c \
    $(LOCAL_DIR)/Core/Src/system_stm32f4xx.c \
    $(LOCAL_DIR)/Core/Src/usart.c \
    $(LOCAL_DIR)/Drivers/BSP/Components/cs43l22/cs43l22.c \
    $(LOCAL_DIR)/Drivers/BSP/STM32F411E-Discovery/stm32f411e_discovery.c \
    $(LOCAL_DIR)/Drivers/BSP/STM32F411E-Discovery/stm32f411e_discovery_audio.c \
    $(LOCAL_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c \
    $(LOCAL_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc.c \
    $(LOCAL_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc_ex.c \
    $(LOCAL_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c \
    $(LOCAL_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_crc.c \
    $(LOCAL_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c \
    $(LOCAL_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c \
    $(LOCAL_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c \
    $(LOCAL_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_hcd.c \
    $(LOCAL_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c.c \
    $(LOCAL_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c_ex.c \
    $(LOCAL_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2s.c \
    $(LOCAL_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2s_ex.c \
    $(LOCAL_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c \
    $(LOCAL_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c \
    $(LOCAL_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c \
    $(LOCAL_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c \
    $(LOCAL_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_spi.c \
    $(LOCAL_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c \
    $(LOCAL_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c \
    $(LOCAL_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c \
    $(LOCAL_DIR)/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usb.c \
    $(LOCAL_DIR)/FATFS/App/fatfs.c \
    $(LOCAL_DIR)/FATFS/Target/usbh_diskio.c \
    $(LOCAL_DIR)/Jukebox/Src/ADC/ADC_Dev.cc \
    $(LOCAL_DIR)/Jukebox/Src/AudioPlayer/AudioPlayerFactory.cc \
    $(LOCAL_DIR)/Jukebox/Src/AudioPlayer/Decoder/IDecoder.cc \
    $(LOCAL_DIR)/Jukebox/Src/AudioPlayer/Decoder/Mp3Decoder.cc \
    $(LOCAL_DIR)/Jukebox/Src/AudioPlayer/Decoder/WavDecoder.cc \
    $(LOCAL_DIR)/Jukebox/Src/AudioPlayer/I2SAudioPlayer.cc \
    $(LOCAL_DIR)/Jukebox/Src/AudioPlayer/IAudioPlayer.cc \
    $(LOCAL_DIR)/Jukebox/Src/JukeboxStart.cc \
    $(LOCAL_DIR)/Jukebox/Src/KeyPad/KeyPadAnalog.cc \
    $(LOCAL_DIR)/Jukebox/Src/KeyPad/KeyPadFactory.cc \
    $(LOCAL_DIR)/Jukebox/Src/Logger/Logger.cc \
    $(LOCAL_DIR)/Jukebox/Src/MassStorageDevice/FatFsDirReader.cc \
    $(LOCAL_DIR)/Jukebox/Src/MassStorageDevice/FatFsFile.cc \
    $(LOCAL_DIR)/Jukebox/Src/MassStorageDevice/FlashFile.cc \
    $(LOCAL_DIR)/Jukebox/Src/MassStorageDevice/IMassStorageDevice.cc \
    $(LOCAL_DIR)/Jukebox/Src/MassStorageDevice/MassStorageDeviceFactory.cc \
    $(LOCAL_DIR)/Jukebox/Src/MassStorageDevice/USBHostMSC.cc \
    $(LOCAL_DIR)/Jukebox/Src/OS/Mutex.cc \
    $(LOCAL_DIR)/Jukebox/Src/OS/Semaphore.cc \
    $(LOCAL_DIR)/Jukebox/Src/OS/Task.cc \
    $(LOCAL_DIR)/Jukebox/Src/OS/UniqueLock.cc \
    $(LOCAL_DIR)/Jukebox/Src/SM/KeyPadSM.cc \
    $(LOCAL_DIR)/Jukebox/Src/Utils/CircularBuffer.cc \
    $(LOCAL_DIR)/Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc.c \
    $(LOCAL_DIR)/Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_bot.c \
    $(LOCAL_DIR)/Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_scsi.c \
    $(LOCAL_DIR)/Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_core.c \
    $(LOCAL_DIR)/Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_ctlreq.c \
    $(LOCAL_DIR)/Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_ioreq.c \
    $(LOCAL_DIR)/Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_pipes.c \
    $(LOCAL_DIR)/Middlewares/Third_Party/FatFs/src/diskio.c \
    $(LOCAL_DIR)/Middlewares/Third_Party/FatFs/src/ff.c \
    $(LOCAL_DIR)/Middlewares/Third_Party/FatFs/src/ff_gen_drv.c \
    $(LOCAL_DIR)/Middlewares/Third_Party/FatFs/src/option/ccsbcs.c \
    $(LOCAL_DIR)/Middlewares/Third_Party/FatFs/src/option/syscall.c \
    $(LOCAL_DIR)/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/cmsis_os2.c \
    $(LOCAL_DIR)/Middlewares/Third_Party/FreeRTOS/Source/croutine.c \
    $(LOCAL_DIR)/Middlewares/Third_Party/FreeRTOS/Source/event_groups.c \
    $(LOCAL_DIR)/Middlewares/Third_Party/FreeRTOS/Source/list.c \
    $(LOCAL_DIR)/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.c \
    $(LOCAL_DIR)/Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_3.c \
    $(LOCAL_DIR)/Middlewares/Third_Party/FreeRTOS/Source/queue.c \
    $(LOCAL_DIR)/Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.c \
    $(LOCAL_DIR)/Middlewares/Third_Party/FreeRTOS/Source/tasks.c \
    $(LOCAL_DIR)/Middlewares/Third_Party/FreeRTOS/Source/timers.c \
    $(LOCAL_DIR)/USB_HOST/App/usb_host.c \
    $(LOCAL_DIR)/USB_HOST/Target/usbh_conf.c \
    $(LOCAL_DIR)/USB_HOST/Target/usbh_platform.c

include $(BUILD_BINARY)
