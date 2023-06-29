#ifndef GOARRAY_VALLOC_HPP
#define GOARRAY_VALLOC_HPP

#include <cstddef>
#include <unistd.h>
#include <sys/mman.h>
#include <cstdio>


namespace soul
{
    void* valloc(size_t size)
    {
    #ifdef __linux__
        return mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    #elifdef _WIN32
        fprintf(stderr, "valloc: virtual allocation for Windows is not yet implemented\n");
        exit(1);
    #endif
    }

    void* vrealloc(void* ptr, size_t newSize)
    {
    #ifdef __linux__
        return mmap(ptr, newSize, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    #elifdef _WIN32
        fprintf(stderr, "vrealloc: virtual reallocation for Windows is not yet implemented\n");
        exit(1);
    #endif
    }

    size_t getPageSize()
    {
    #ifdef __linux__
        return sysconf(_SC_PAGESIZE);
    #elifdef _WIN32
    #endif
    }
}


#endif // GOARRAY_VALLOC_HPP
