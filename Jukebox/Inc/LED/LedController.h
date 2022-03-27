/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: LedController.h
 * Brief: Controller for the LEDs in the Jukebox
 * Module: LED
 */

#ifndef ATE_LED_LED_CONTROLLER_H_
#define ATE_LED_LED_CONTROLLER_H_

#include "OS/Task.h"
#include "OS/Mutex.h"
#include "OS/Queue.h"

namespace ATE
{
	class LedController : public OSAL::Task
	{
	public:
		LedController();

	private:
		void Init() override;
		bool Run() override;
	};
}

#endif /* ATE_LED_LED_CONTROLLER_H_ */
