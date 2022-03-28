/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: ADC.h
 * Brief: Analog to Digital Converter module
 * Module: Device
 */

#ifndef ATE_DEVICE_ADC_H_
#define ATE_DEVICE_ADC_H_

#include <cstdint>
#include <tuple>

#include "OS/Semaphore.h"
#include "adc.h"

extern "C" void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc);

namespace ATE::Device
{
    class ADC_Dev
    {
    public:
        enum Source
        {
            SOURCE_ADC1
        };

        enum Channel
        {
            Channel_0 = 0,
            Channel_1,
            Channel_2,
            Channel_3,
            Channel_4,
            Channel_5,
            Channel_6,
            Channel_7,
            Channel_8,
            Channel_9,
            Channel_10,
            Channel_11,
            Channel_12,
            Channel_13,
            Channel_14,
            Channel_15,
        };

        static ADC_Dev& GetDevice(Source);

        bool SelectChannel(ADC_Dev::Channel ch);
        std::uint32_t GetResolution();
        std::tuple<std::uint32_t, bool> PerformMeasurement();

    private:
        ADC_HandleTypeDef *hadc;
        OSAL::Semaphore conversionSemaphore;

        ADC_Dev(Source);
        bool StartConversion();

        friend void ::HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc);
    };

}

#endif /* ATE_DEVICE_ADC_H_ */
