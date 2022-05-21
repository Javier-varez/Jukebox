/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: ws2812.h
 * Brief: 
 * Module: LED
 */

#ifndef ATE_LED_WS2812_H_
#define ATE_LED_WS2812_H_

#include "stm32f4xx_hal.h"

namespace ATE::LED
{

template<size_t NUM_LEDS>
class Ws2812l {
public:
    struct Color {
        uint8_t red;
        uint8_t green;
        uint8_t blue;
    };

    Ws2812l(GPIO_TypeDef* bank, uint32_t gpio_pin) : bank(bank), pin(gpio_pin) {
        GPIO_InitTypeDef GPIO_InitStruct {
            .Pin = gpio_pin,
            .Mode = GPIO_MODE_OUTPUT_PP,
            .Pull = GPIO_NOPULL,
            .Speed = GPIO_SPEED_FREQ_LOW,
            .Alternate = 0u,
        };
        HAL_GPIO_Init(bank, &GPIO_InitStruct);

        Reset();

        memset(&leds[0], 0, sizeof(leds));

        Flush();
    }

    void SetLed(unsigned int index, Color color) {
        leds[index] = color;
    }
    
    void Flush() {
        // Send the colors to the HW
        for (const Color& color : leds) {
            SendByte(color.green);
            SendByte(color.red);
            SendByte(color.blue);
        }
    }

private:
    GPIO_TypeDef* bank;
    int pin;

    Color leds[NUM_LEDS];

    void SendByte(uint8_t data) const {
        for (int32_t i = 7; i >= 0; i--) {
            const bool value = (data & (1 << i)) != 0;
            if (value) {
                Send0();
            } else {
                Send1();
            }
        }
    }

    inline void SetPin(bool val) const {
        const uint32_t offset = val ? 0: 16;
        bank->BSRR = 1u << (offset + pin);
    }

    inline void Send0() const {
        HAL_GPIO_WritePin(bank, pin, GPIO_PIN_SET);
        WaitFor<350>();
        HAL_GPIO_WritePin(bank, pin, GPIO_PIN_RESET);
        WaitFor<800>();
        HAL_GPIO_WritePin(bank, pin, GPIO_PIN_SET);
    }
    
    inline void Send1() const {
        HAL_GPIO_WritePin(bank, pin, GPIO_PIN_SET);
        WaitFor<700>();
        HAL_GPIO_WritePin(bank, pin, GPIO_PIN_RESET);
        WaitFor<600>();
        HAL_GPIO_WritePin(bank, pin, GPIO_PIN_SET);
    }

    void Reset() const {
        HAL_GPIO_WritePin(bank, pin, GPIO_PIN_RESET);
        WaitFor<50'000>();
        HAL_GPIO_WritePin(bank, pin, GPIO_PIN_SET);
    }

    constexpr static uint32_t MAX_COUNT = 96'000;

    static uint32_t SystickCount() {
        return MAX_COUNT - SysTick->VAL - 1;
    }

    static uint32_t TicksSince(uint32_t ticks) {
        const uint32_t now = SystickCount();
        if (now < ticks) {
            return now + MAX_COUNT - ticks;
        }
        return now - ticks;
    }

    template<uint64_t nanoseconds>
    static void WaitFor() {
        // System clk is hardcoded to 96'000'000
        // Clk overflows at 96'000 to achieve 1kHz
        constexpr static uint64_t SYSTEM_CLK = 96'000'000;
        constexpr static uint64_t waitCycles = nanoseconds * SYSTEM_CLK / 1'000'000'000ull;
        static_assert(waitCycles <= 0xFFFFFFFFU);
        const uint32_t entry = SystickCount();

        while (TicksSince(entry) < waitCycles);
    }
};

}

#endif /* ATE_LED_WS2812_H_ */
