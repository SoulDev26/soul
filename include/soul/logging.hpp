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

#define DEBUG_ERROR(...) raiseError(this, __FUNCTION__, fmt::format(__VA_ARGS__))
#define SOUL_PANIC(...) fmt::print(stderr, "{} {}[line {}]: ", fmt::styled("PANIC", fmt::fg(fmt::color::red)), __FILE__, __LINE__); \
    fmt::print(stderr, __VA_ARGS__); fmt::print(stderr, '\n'); \
    exit(1)

#ifdef DEBUG
    #define DEBUG_INFO(...) debugPrint(soul::DebugMsgType::Info, this, __FUNCTION__, fmt::format(__VA_ARGS__))
    #define DEBUG_WARNING(...) debugPrint(soul::DebugMsgType::Warning, this, __FUNCTION__, fmt::format(__VA_ARGS__))
#else
    #define DEBUG_INFO(...)
    #define DEBUG_WARNING(...)
#endif


namespace soul {
    enum DebugMsgType
    {
        Error,
        Info,
        Warning
    };
    class Debug {
    private:
        std::string className_;
        std::string namespace_;
    
    public:
        Debug(std::string className) : className_(className), namespace_()
        {}

        Debug(std::string className, std::string namespaceStr) : className_(className), namespace_(namespaceStr)
        {}

        void debugPrint(DebugMsgType msgType, const void *thisPtr, std::string funcName, std::string msg) const
        {
            std::string msgTypeStr; 

            switch (msgType)
            {
            case DebugMsgType::Error:
                msgTypeStr = fmt::format("{}", fmt::styled("ERROR", fmt::fg(fmt::color::red)));
                break;

            case DebugMsgType::Info:
                msgTypeStr = fmt::format("{}", fmt::styled("INFO", fmt::fg(fmt::color::cyan)));
                break;

            case DebugMsgType::Warning:
                msgTypeStr = fmt::format("{}", fmt::styled("WARNING", fmt::fg(fmt::color::orange)));
                break;
            }

            fmt::print("({}) [{}]({}::{}::{}): {}\n",
                    msgTypeStr,
                    fmt::ptr(thisPtr),
                    fmt::styled(namespace_, fmt::fg(fmt::color::lime)),
                    fmt::styled(className_, fmt::fg(fmt::color::blue_violet)),
                    fmt::styled(funcName, fmt::fg(fmt::color::orange)),
                    msg
            );
        }

        void raiseError(const void *thisPtr, std::string funcName, std::string msg) const
        {
            debugPrint(DebugMsgType::Error, thisPtr, funcName, msg);
            exit(1);
        }
    };
}


#endif // SOUL_DEBUG_HPP
