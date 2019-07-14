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

#ifndef KEYPAD_KEYPADANALOG_H_
#define KEYPAD_KEYPADANALOG_H_

#include "KeyPad/IKeyPad.h"
#include "OS/Task.h"

namespace ATE::Device
{
	class KeyPadAnalog: public OSAL::Task, public  IKeyPad
	{
	public:
		KeyPadAnalog();

	private:
		void Init() override;
		bool Run() override;
	};
}


#endif /* KEYPAD_KEYPADANALOG_H_ */
