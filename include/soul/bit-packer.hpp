#ifndef SOUL_BIT_PACKER_HPP
#define SOUL_BIT_PACKER_HPP

#include "stypes.hpp"

namespace soul 
{
    template <typename I, typename O>
    O readBits(I val, u8 startI, u8 count) 
    {
        O res = 0;
        I mask = 1;

        for (u8 i = startI; i < count; i++)
        {
            res = res ^ (val & mask);
            mask <<= 1;
        }

        return res;
    }

    template <typename I, typename O>
    O readBit(I val, u8 index) 
    {
        I mask = 1 << index;

        return (val & mask) >> index;
    }

    template <typename T>
    void writeBit(T& val, u8 index, bool bit)
    {
        T mask = 1 << index;

        if (bit == 1)
        {
            val |= mask;
        }
        else
        {
            mask = ~mask;
            val &= mask;
        }
    }

    template <typename T>
    void writeBits(T& val, u8 index, T bits)
    {
        T mask = bits << index;

        for (u8 i = index; i < sizeof(T); i++)
        {
            bool bit = readBit<T, bool>(val, i);

            writeBit<T>(val, i, bit);
        }
    }

    template <typename T>
    void writeBits(T& val, u8 index, T bits, u8 bitsCount)
    {
        T mask = bits << index;

        for (u8 i = index; i < bitsCount; i++)
        {
            bool bit = readBit<T, bool>(val, i);

            writeBit<T>(val, i, bit);
        }
    }
}


#endif
