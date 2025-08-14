#include "AppleEnvironment.h"

#if PLATFORM_MACOS

const char* CAppleEnvironment::NewLine() const
{
    return "\n";
}

#endif