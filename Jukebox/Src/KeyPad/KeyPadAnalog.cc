/*
 * KeyPadAnalog.cc
 *
 *  Created on: Jul 14, 2019
 *      Author: javier
 */

#include "KeyPad/KeyPadAnalog.h"
#include "Logger/Logger.h"
#include "adc.h"

extern "C"
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc)
{
	std::uint32_t value = HAL_ADC_GetValue(hadc);
	ATE::Logger &logger = ATE::Logger::GetLogger();

	logger.Log(ATE::Logger::LogLevel_ERROR, "Value %d\r\n", value);
}

namespace ATE::Device
{
	constexpr static char TASK_NAME[] = "cool";
	KeyPadAnalog::KeyPadAnalog()
		: Task(TASK_NAME, osPriorityHigh, 400)
	{

	}

	void KeyPadAnalog::Init()
	{

	}
	bool KeyPadAnalog::Run()
	{
		ADC_ChannelConfTypeDef sConfig =
		{
			Channel : ADC_CHANNEL_14,
			Rank : 1,
			SamplingTime : ADC_SAMPLETIME_480CYCLES,
			Offset : 0
		};

		if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
		{

		}

		HAL_ADC_Start_IT(&hadc1);

		Task::Delay(1000);

		return true;
	}
}
