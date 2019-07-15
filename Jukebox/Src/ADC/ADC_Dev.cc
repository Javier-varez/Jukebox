/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: ADC.cc
 * Brief: Analog to Digital Converter module
 * Module: Device
 */

#include <ADC/ADC_Dev.h>
#include "Logger/Logger.h"
#include "OS/Task.h"

extern "C"
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	if (hadc == &hadc1)
	{
		ATE::Device::ADC_Dev::GetDevice(ATE::Device::ADC_Dev::SOURCE_ADC1).conversionSemaphore.Give();
	}
}

namespace ATE::Device
{
	ADC_Dev& ADC_Dev::GetDevice(ADC_Dev::Source source)
	{
		static ADC_Dev adc1(ADC_Dev::SOURCE_ADC1);

		switch (source)
		{
		case SOURCE_ADC1:
			return adc1;
			break;
		}

		return adc1;
	}

	ADC_Dev::ADC_Dev(ADC_Dev::Source source)
	{
		switch(source)
		{
		case SOURCE_ADC1:
			hadc = &::hadc1;
			break;
		default:
			ATE::Logger::GetLogger().Log(
					ATE::Logger::LogLevel_ERROR,
					"%s: Can't find specified ADC %d\r\n",
					__func__, source);
			break;
		}
	}

	bool ADC_Dev::SelectChannel(ADC_Dev::Channel ch)
	{
		ADC_ChannelConfTypeDef sConfig =
		{
			Channel : ch,
			Rank : 1,
			SamplingTime : ADC_SAMPLETIME_480CYCLES,
			Offset : 0
		};

		if (HAL_ADC_ConfigChannel(hadc, &sConfig) != HAL_OK)
		{
			ATE::Logger &logger = ATE::Logger::GetLogger();
			logger.Log(ATE::Logger::LogLevel_ERROR, "%s: Couldn't set configuration channel\r\n", __func__);
			return false;
		}
		return true;
	}

	bool ADC_Dev::StartConversion()
	{
		if (HAL_ADC_Start(hadc) != HAL_OK)
		{
			ATE::Logger &logger = ATE::Logger::GetLogger();
			logger.Log(ATE::Logger::LogLevel_ERROR, "%s: Couldn't start conversion", __func__);
			return false;
		}
		HAL_ADC_PollForConversion(hadc, 10);
		return true;

	}

	std::tuple<std::uint32_t, bool> ADC_Dev::PerformMeasurement(ADC_Dev::Channel ch)
	{
		std::uint32_t value = 0;

		if (!SelectChannel(ch))
		{
			goto fail;
		}
		if (!StartConversion())
		{
			goto fail;
		}

		//conversionSemaphore.Take();

		value = HAL_ADC_GetValue(hadc);
		return std::make_tuple(value, true);
	fail:
		return std::make_tuple(value, false);
	}

	std::uint32_t ADC_Dev::GetResolution()
	{
		return 4096;
	}

}
