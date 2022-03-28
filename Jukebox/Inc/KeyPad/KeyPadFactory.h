/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: KeyPadFactory.h
 * Brief: Provides implementations for the interface IKeyPad
 * Module: Device
 */

#ifndef ATE_KEYPADFACTORY_H_
#define ATE_KEYPADFACTORY_H_

#include "KeyPad/IKeyPad.h"

namespace ATE::Device
{
    class KeyPadFactory
    {
    public:
        static IKeyPad& GetAnalogKeypad();
    };
}

#endif /* ATE_KEYPADFACTORY_H_ */
