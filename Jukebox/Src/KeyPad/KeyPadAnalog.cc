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

#include <algorithm>

namespace ATE::Device
{
	constexpr static char TASK_NAME[] = "KeyPadAnalog";
	constexpr static std::uint32_t N_ROWS = 10;

	KeyPadAnalog::KeyPadAnalog()
		: Task(TASK_NAME, osPriorityHigh, 1024),
		  adc(ADC_Dev::GetDevice(ADC_Dev::SOURCE_ADC1)),
		  rowSymbols({ 'K', 'J', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A',
					   'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'M', 'N', 'L',
	                   '0', '9', '8', '7', '6', '5', '4', '3', '2', '1'})
	{

	}

	void KeyPadAnalog::Init()
	{
		std::for_each(rowPrevStates.begin(), rowPrevStates.end(), [](char &c) { c = '\0'; });
	}

	char KeyPadAnalog::VoltageToCharacter(KeyPadRow row, std::uint32_t voltage)
	{
		std::uint32_t volt_step = adc.GetResolution() / CHARACTERS_PER_ROW;
		std::uint32_t index = (voltage + volt_step / 2) / volt_step;

		if (index == 0)
			return '\0';

		return rowSymbols[(index - 1) + CHARACTERS_PER_ROW * row];
	}

	char KeyPadAnalog::PerformReading(KeyPadRow row)
	{
		auto res = adc.PerformMeasurement();

		if (std::get<1>(res))
		{
			return VoltageToCharacter(row, std::get<0>(res));
		}

		return '\0';
	}

	void KeyPadAnalog::UpdateRowState(KeyPadRow row, char c)
	{
		Utils::CircularBuffer<char, DEBOUNCE_LENGTH> &buffer = rowBuffers[row];
		char &oldState = rowPrevStates[row];

		buffer.Push(c);

		for (std::size_t i = 0; i < DEBOUNCE_LENGTH; i++)
		{
			if (buffer[i] != c)
			{
				return;
			}
		}

		if (oldState != c)
		{
			if (oldState != '\0')
			{
				Notify(oldState, KEY_RELEASED);
			}

			if (c != '\0')
			{
				Notify(c, KEY_PRESSED);
			}
		}
		oldState = c;
	}

	bool KeyPadAnalog::Run()
	{
		for (std::uint32_t i = static_cast<std::uint32_t>(Row_First);
				i < static_cast<std::uint32_t>(N_ROWS); i++)
		{
			KeyPadRow row = static_cast<KeyPadRow>(i);

			char c = PerformReading(row);
			UpdateRowState(row, c);
		}

		Task::Delay(10);

		return true;
	}
}
