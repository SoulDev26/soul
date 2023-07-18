#ifndef SOUL_DEBUG_HPP
#define SOUL_DEBUG_HPP


#include <string>
//#include <fmt/format.h>
//#include <fmt/core.h>
//#include <fmt/color.h>
//#include <fmt/chrono.h>
#include <fmt/core.h>
#include <fmt/format.h>
#include <fmt/color.h>


#ifdef DEBUG
    #define SOUL_PANIC(...) fmt::print(stderr, "{} {}[line {}]: ", fmt::styled("PANIC", fmt::fg(fmt::color::red)), __FILE__, __LINE__); \
        fmt::print(stderr, __VA_ARGS__); fmt::print(stderr, "\n"); \
        exit(1)

    #define SOUL_LOG_INFO(...) fmt::print(stderr, "{} {}[line {}]: ", fmt::styled("INFO", fmt::fg(fmt::color::blue)), __FILE__, __LINE__); \
        fmt::print(stderr, __VA_ARGS__); fmt::print(stderr, "\n")

    #define SOUL_LOG_WARN(...) fmt::print(stderr, "{} {}[line {}]: ", fmt::styled("WARN", fmt::fg(fmt::color::orange)), __FILE__, __LINE__); \
        fmt::print(stderr, __VA_ARGS__); fmt::print(stderr, "\n")

#else
    #define SOUL_PANIC(...) fmt::print(stderr, "[{}] ", fmt::styled("PANIC", fmt::fg(fmt::color::red))); \
        fmt::print(stderr, __VA_ARGS__); fmt::print(stderr, "\n"); \
        exit(1)

    #define SOUL_LOG_INFO(...) fmt::print(stderr, "[{}] ", fmt::styled("INFO", fmt::fg(fmt::color::blue))); \
        fmt::print(stderr, __VA_ARGS__); fmt::print(stderr, "\n")

    #define SOUL_LOG_WARN(...) fmt::print(stderr, "[{}] ", fmt::styled("WARN", fmt::fg(fmt::color::orange))); \
        fmt::print(stderr, __VA_ARGS__); fmt::print(stderr, "\n")
#endif
    

#endif // SOUL_DEBUG_HPP
