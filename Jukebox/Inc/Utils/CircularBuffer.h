/*
 * Jukebox
 *
 * AllThingsEmbedded Jukebox Machine
 * https://AllThingsEmbedded.net
 *
 * File: CircularBuffer.h
 * Brief: Circular Buffer implementation
 * Module: Utils
 */

#ifndef ATE_UTILS_CIRCULAR_BUFFER_H_
#define ATE_UTILS_CIRCULAR_BUFFER_H_

#include <cstdint>

namespace ATE::Utils
{
    template<typename T, std::size_t nElements>
    class CircularBuffer
    {
    public:
        CircularBuffer()
        {
            index = 0;
        }

        T Push(const T& val)
        {
            T tmp = buffer[index];

            buffer[index] = val;
            index = (index + 1) % nElements;

            return tmp;
        }

        T& operator[](int i)
        {
            std::size_t realIndex = (index + i) % nElements;
            return buffer[realIndex];
        }

    private:
        std::array<T, nElements> buffer;
        std::size_t index;
    };
}


#endif /* ATE_UTILS_CIRCULAR_BUFFER_H_ */
