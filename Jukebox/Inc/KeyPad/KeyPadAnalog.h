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
#include "Utils/CircularBuffer.h"

#include <cstdint>

namespace ATE::Device
{
    class KeyPadAnalog: public OSAL::Task, public  IKeyPad
    {
    public:
        enum KeyPadRow : std::uint32_t
        {
            Row_First = 0,
            Row_Second,
            Row_Numeric,
            N_ROWS
        };

        KeyPadAnalog();
        char VoltageToCharacter(KeyPadRow, std::uint32_t);
        void UpdateRowState(KeyPadRow, char);
        char PerformReading(KeyPadRow);

    private:
        constexpr static std::uint32_t DEBOUNCE_LENGTH = 10;
        constexpr static std::uint32_t CHARACTERS_PER_ROW = 10;

        ADC_Dev &adc;
        const std::array<char, CHARACTERS_PER_ROW * N_ROWS> rowSymbols;
        std::array<Utils::CircularBuffer<char, DEBOUNCE_LENGTH>, N_ROWS> rowBuffers;
        std::array<char, N_ROWS> rowPrevStates;

        void Init() override;
        bool Run() override;
    };
}


#endif /* KEYPAD_KEYPADANALOG_H_ */
