cmake_minimum_required(VERSION 3.16)
enable_language(C CXX ASM)

set(CMAKE_SYSTEM_NAME, Generic)
set(CMAKE_SYSTEM_PROCESSOR, arm)

set(APPLICATION_NAME Jukebox.elf)

project(Jukebox)

# Postform dependency
include(FetchContent)

FetchContent_Declare(
  postform
    GIT_REPOSITORY https://github.com/Javier-varez/Postform
    GIT_TAG 0.5.0)

FetchContent_MakeAvailable(postform)

add_executable(
    ${APPLICATION_NAME}
    ${CMAKE_CURRENT_SOURCE_DIR}/Startup/startup_stm32f411vetx.s
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/adc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/crc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/dma.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/freertos.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/gpio.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/main.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/stm32f4xx_hal_msp.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/stm32f4xx_hal_timebase_tim.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/stm32f4xx_it.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/system_stm32f4xx.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Src/usart.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/BSP/Components/cs43l22/cs43l22.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/BSP/STM32F411E-Discovery/stm32f411e_discovery.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/BSP/STM32F411E-Discovery/stm32f411e_discovery_audio.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc_ex.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_crc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_hcd.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c_ex.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2s.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2s_ex.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_spi.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usb.c
    ${CMAKE_CURRENT_SOURCE_DIR}/FATFS/App/fatfs.c
    ${CMAKE_CURRENT_SOURCE_DIR}/FATFS/Target/usbh_diskio.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Jukebox/Src/ADC/ADC_Dev.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Jukebox/Src/AudioPlayer/AudioPlayerFactory.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Jukebox/Src/AudioPlayer/Decoder/IDecoder.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Jukebox/Src/AudioPlayer/Decoder/Mp3Decoder.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Jukebox/Src/AudioPlayer/Decoder/WavDecoder.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Jukebox/Src/AudioPlayer/I2SAudioPlayer.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Jukebox/Src/AudioPlayer/IAudioPlayer.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Jukebox/Src/JukeboxStart.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Jukebox/Src/KeyPad/KeyPadAnalog.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Jukebox/Src/KeyPad/KeyPadFactory.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Jukebox/Src/Logger/Logger.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Jukebox/Src/MassStorageDevice/FatFsDirReader.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Jukebox/Src/MassStorageDevice/FatFsFile.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Jukebox/Src/MassStorageDevice/FlashFile.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Jukebox/Src/MassStorageDevice/IMassStorageDevice.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Jukebox/Src/MassStorageDevice/MassStorageDeviceFactory.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Jukebox/Src/MassStorageDevice/USBHostMSC.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Jukebox/Src/OS/Mutex.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Jukebox/Src/OS/Semaphore.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Jukebox/Src/OS/Task.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Jukebox/Src/OS/UniqueLock.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Jukebox/Src/SM/KeyPadSM.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Jukebox/Src/Utils/CircularBuffer.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_bot.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Src/usbh_msc_scsi.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_core.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_ctlreq.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_ioreq.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_pipes.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/Third_Party/FatFs/src/diskio.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/Third_Party/FatFs/src/ff.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/Third_Party/FatFs/src/ff_gen_drv.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/Third_Party/FatFs/src/option/ccsbcs.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/Third_Party/FatFs/src/option/syscall.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/cmsis_os2.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/Third_Party/FreeRTOS/Source/croutine.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/Third_Party/FreeRTOS/Source/event_groups.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/Third_Party/FreeRTOS/Source/list.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_3.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/Third_Party/FreeRTOS/Source/queue.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/Third_Party/FreeRTOS/Source/tasks.c
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/Third_Party/FreeRTOS/Source/timers.c
    ${CMAKE_CURRENT_SOURCE_DIR}/USB_HOST/App/usb_host.c
    ${CMAKE_CURRENT_SOURCE_DIR}/USB_HOST/Target/usbh_conf.c
    ${CMAKE_CURRENT_SOURCE_DIR}/USB_HOST/Target/usbh_platform.c)

target_include_directories(
    ${APPLICATION_NAME}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/FATFS/App
    ${CMAKE_CURRENT_SOURCE_DIR}/FATFS/Target
    ${CMAKE_CURRENT_SOURCE_DIR}/USB_HOST/App
    ${CMAKE_CURRENT_SOURCE_DIR}/USB_HOST/Target
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/CMSIS/Include
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/CMSIS/Device/ST/STM32F4xx/Include
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/BSP/STM32F411E-Discovery/
    ${CMAKE_CURRENT_SOURCE_DIR}/Drivers/AudioDecoders
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/ST/STM32_USB_Host_Library/Class/MSC/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/ST/STM32_USB_Host_Library/Core/Inc
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/Third_Party/FatFs/src
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/Third_Party/FreeRTOS/Source/include
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2
    ${CMAKE_CURRENT_SOURCE_DIR}/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F
    ${CMAKE_CURRENT_SOURCE_DIR}/Jukebox/Inc)

target_compile_definitions(
    ${APPLICATION_NAME}
    PRIVATE
    USE_HAL_DRIVER
    STM32F411xE)

target_compile_options(
    ${APPLICATION_NAME}
    PRIVATE
    -Os
    -g3
    -Wall
    -Wextra
    -Wno-psabi
    -Wno-unused-parameter
    $<$<COMPILE_LANGUAGE:C>:-Wno-int-conversion>
    -Wno-unused-variable
    -Wno-unused-const-variable
    -Wno-implicit-fallthrough
    $<$<COMPILE_LANGUAGE:CXX>:-Wno-volatile>)

target_compile_features(
    ${APPLICATION_NAME}
    PRIVATE
    cxx_std_20)

target_link_libraries(
    ${APPLICATION_NAME}
    PRIVATE
    _mp3decoder_cortex_m4_v2.2.0
    postform)

target_link_options(
    ${APPLICATION_NAME}
    PRIVATE
    "SHELL:-Wl,-T ${CMAKE_CURRENT_SOURCE_DIR}/STM32F411VETX_FLASH.ld"
    "-Wl,-Map=${CMAKE_CURRENT_BINARY_DIR}/${APPLICATION_NAME}.map"
    "-L${CMAKE_CURRENT_SOURCE_DIR}/Drivers/AudioDecoders"
    )

set_target_properties(
    ${APPLICATION_NAME}
    PROPERTIES
    LINK_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/STM32F411VETX_FLASH.ld)

set(CHIP_NAME STM32F411VETx)

add_custom_target(
    run
    COMMAND postform_rtt --chip ${CHIP_NAME} ${CMAKE_BINARY_DIR}/${APPLICATION_NAME}
    DEPENDS ${APPLICATION_NAME}
    USES_TERMINAL)

add_custom_target(
    attach
    COMMAND postform_rtt --attach --chip ${CHIP_NAME} ${CMAKE_BINARY_DIR}/${APPLICATION_NAME}
    DEPENDS ${APPLICATION_NAME}
    USES_TERMINAL)
