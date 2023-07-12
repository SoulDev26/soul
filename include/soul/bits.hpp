#ifndef SOUL_BIT_PACKER_HPP
#define SOUL_BIT_PACKER_HPP

#include <fmt/core.h>
#include "stypes.hpp"

#define SOUL_BIT_MASK(startBit, bitsCount) (((1 << bitsCount) - 1) << startBit)

namespace soul 
{
    template <typename I, typename O>
    O read_bits(I val, u8 index, u8 count) 
    {
        O res = 0;
        I mask = SOUL_BIT_MASK(index, count);

        res = (val & mask) >> index;

        return res;
    }

    template <typename I, typename O>
    O read_bit(I val, u8 index) 
    {
        I mask = 1 << index;

        return (val & mask) >> index;
    }

    template <typename T>
    void write_bit(T& val, u8 index, bool bit)
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
    void write_bits(T& val, u8 index, T bits)
    {
        T mask = ~SOUL_BIT_MASK(index, sizeof(T) * 8);
        
        val = (val & mask) | (bits << index);
    }

    template <typename T>
    void write_bits(T& val, u8 index, T bits, u8 bitsCount)
    {
        T mask = ~SOUL_BIT_MASK(index, bitsCount);
        val = (val & mask) | (bits << index);
    }
}


#endif
