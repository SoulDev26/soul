#ifndef SOUL_ID_GENERATOR_HPP
#define SOUL_ID_GENERATOR_HPP

#include "stypes.hpp"
#include "valloc.hpp"


namespace soul 
{
    static u64 genUniqId()
    {
        static size_t pageSize = getPageSize();
        static byte* page = nullptr;
        static byte* usedPtr = nullptr;


        if (page == nullptr || usedPtr == page + pageSize)
        {
            page = static_cast<byte*>(valloc(pageSize));
            usedPtr = page;
        }

        return (u64)usedPtr++;
    }
}


#endif // SOUL_ID_GENERATOR_HPP
