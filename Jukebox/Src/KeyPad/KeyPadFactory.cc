/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: KeyPadFactory.cc
 * Brief: Provides implementations for the interface IKeyPad
 * Module: Device
 */

#include "KeyPad/KeyPadFactory.h"
#include "KeyPad/KeyPadAnalog.h"

namespace ATE::Device
{
	IKeyPad& KeyPadFactory::GetAnalogKeypad()
	{
		static KeyPadAnalog analog;
		return analog;
	}
}
