#ifndef SOUL_ID_GENERATOR_HPP
#define SOUL_ID_GENERATOR_HPP

#include "stypes.hpp"
#include "memory.hpp"


namespace soul 
{
    static u64 gen_uniq_id()
    {
        static size_t pageSize = get_page_size();
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
