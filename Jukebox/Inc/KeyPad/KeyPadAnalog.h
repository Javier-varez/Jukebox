/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: KeyPadAnalog.h
 * Brief: AnalogKeyPad Implementation
 * Module: Device
 */

#ifndef KEYPAD_KEYPADANALOG_H_
#define KEYPAD_KEYPADANALOG_H_

#include "KeyPad/IKeyPad.h"
#include "OS/Task.h"
#include "ADC/ADC_Dev.h"

#include <cstdint>

namespace ATE::Device
{
	class KeyPadAnalog: public OSAL::Task, public  IKeyPad
	{
	public:
		enum KeyPadRow : std::uint32_t
		{
			Row_First,
			Row_Second,
			Row_Numeric
		};

		KeyPadAnalog();
		char VoltageToCharacter(KeyPadRow, std::uint32_t);
		char PerformReading(KeyPadRow);

	private:
		ADC_Dev &adc;

		void Init() override;
		bool Run() override;
	};
}


#endif /* KEYPAD_KEYPADANALOG_H_ */
