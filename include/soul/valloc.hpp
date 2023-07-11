#ifndef GOARRAY_VALLOC_HPP
#define GOARRAY_VALLOC_HPP

#include <cstddef>
#include <unistd.h>
#include <sys/mman.h>
#include <cstdio>
#include <cstring>
#include <functional>


namespace soul
{
    /*
     * Allocates virtual memory with some size
     */
    void* valloc(size_t size);

    /*
     * Reallocates virtual memory with new size
     * (ptr can be nullptr)
     *
     * oldSize is needed if you need to copy data during reallocation
     */
    void* vrealloc(void* ptr, size_t oldSize, size_t newSize);

    /*
     * Reallocates virtual memory with new size.
     * (ptr can be nullptr)
     *
     * oldSize is needed if you need to copy data during reallocation.
     */
    //void* vrealloc(void* ptr, size_t oldSize, size_t newSize, std::function<void(void*, void*)> copyFunc);


    inline size_t getPageSize()
    {
    #if defined(__linux__)
        return sysconf(_SC_PAGESIZE);
    #elif defined(_WIN32);
    #endif
    }
}


#endif // GOARRAY_VALLOC_HPP
