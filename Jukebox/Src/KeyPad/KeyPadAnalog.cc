/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: KeyPadAnalog.cc
 * Brief: AnalogKeyPad Implementation
 * Module: Device
 */
#include "KeyPad/KeyPadAnalog.h"
#include "Logger/Logger.h"

namespace ATE::Device
{
	constexpr static char TASK_NAME[] = "cool";
	KeyPadAnalog::KeyPadAnalog()
		: Task(TASK_NAME, osPriorityHigh, 1024),
		  adc(ADC_Dev::GetDevice(ADC_Dev::SOURCE_ADC1))
	{

	}

	void KeyPadAnalog::Init()
	{

	}

	char KeyPadAnalog::VoltageToCharacter(KeyPadRow row, std::uint32_t voltage)
	{
		std::uint32_t volt_step = 4096 / 10;
		std::uint32_t index = (voltage + volt_step / 2) / volt_step;

		if (index == 0) return '\0';

		switch (row)
		{
		case Row_First:
			return 'A' + index - 1;
		case Row_Second:
			return 'L' + index - 1;
		case Row_Numeric:
			if (index == 10) return '0';
			else return '0' + index;
		default:
			return '\0';
		}
	}

	char KeyPadAnalog::PerformReading(KeyPadRow row)
	{
		ADC_Dev::Channel ch;
		switch (row)
		{
		case Row_First:
			ch = ADC_Dev::Channel_14;
			break;
		case Row_Second:
			ch = ADC_Dev::Channel_15;
			break;
		case Row_Numeric:
			ch = ADC_Dev::Channel_8;
			break;
		default:
			ch = ADC_Dev::Channel_14;
			break;
		}
		auto res = adc.PerformMeasurement(ch);

		if (std::get<1>(res))
		{
			return VoltageToCharacter(row, std::get<0>(res));
		}

		return '\0';
	}

	bool KeyPadAnalog::Run()
	{
		char c = PerformReading(Row_First);

		if (c != '\0')
			Notify(c, KEY_PRESSED);

		Task::Delay(1000);

		return true;
	}
}
