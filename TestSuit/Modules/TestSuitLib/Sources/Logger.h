#pragma once

#include <format>
#include <iostream>

class CTestLogger
{
    static void WriteLog(std::string Log)
    {
#if PLATFORM_WINDOWS
        std::cout << Log << "\r\n";
#else
        std::cout << Log << "\n";
#endif
    }

    template<typename ... TArgs>
    static std::string GetFormattedString(const char* Format, TArgs&& ... Args)
    {
        return std::vformat(Format, std::make_format_args(Args...));
    }

public:
    template<typename ... TArgs>
    static void Log(const char* Format, TArgs&& ... Args)
    {
        WriteLog(GetFormattedString(Format, Args...));
    }

    template<typename ... TArgs>
    static void Warning(const char* Format, TArgs ... Args)
    {
        WriteLog("WARNING: " + GetFormattedString(Format, Args...));
    }

    template<typename ... TArgs>
    static void Error(const char* Format, TArgs ... Args)
    {
        WriteLog("ERROR: " + GetFormattedString(Format, Args...));
    }
};