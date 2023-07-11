#include "../include/soul/valloc.hpp"



void* soul::valloc(size_t size)
{
#if defined(__linux__)
    return mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
#elif defined(_WIN32)
    fprintf(stderr, "valloc: virtual allocation for Windows is not yet implemented\n");
    exit(1);
#endif
}

void* soul::vrealloc(void* ptr, size_t oldSize, size_t newSize)
{
#if defined(__linux__)
    return mremap(ptr, oldSize, newSize, MREMAP_MAYMOVE);
#elif define(_WIN32)
    fprintf(stderr, "vrealloc: virtual reallocation for Windows is not yet implemented\n");
    exit(1);
#endif
}

//void* soul::vrealloc(void* ptr, size_t oldSize, size_t newSize, std::function<void(void*, void*)> copyFunc)
//{
//#if defined(__linux__)
//    void* newPtr = mmap(ptr, newSize, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
//
//    if (ptr != newPtr)
//        copyFunc(ptr, newPtr);
//
//    munmap(ptr, oldSize);
//
//    return newPtr;
//#elif defined(_WIN32)
//    fprintf(stderr, "vrealloc: virtual reallocation for Windows is not yet implemented\n");
//    exit(1);
//#endif
//}
