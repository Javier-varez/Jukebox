/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: LedController.cc
 * Brief: Controller for the LEDs in the Jukebox
 * Module: LED
 */

#include "LED/LedController.h"

#include <cstdint>

#include "stm32f4xx_hal.h"

namespace ATE
{
	constexpr static char TASK_NAME[] = "LedController";

	LedController::LedController() :
		Task(TASK_NAME, osPriorityHigh, 1024)
	{

	}

	void LedController::Init()
	{
		GPIO_InitTypeDef GPIO_InitStruct = {0};
		
		/*Configure GPIO pin : PA6, PA7 */
		GPIO_InitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_7;
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	}

	bool LedController::Run()
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
		return true;
	}
}
