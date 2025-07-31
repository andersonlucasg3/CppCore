#include "AppleEnvironment.h"

#if PLATFORM_MACOS

CORE_API const char* CAppleEnvironment::NewLineInternal() const
{
    return "\n";
}

#endif