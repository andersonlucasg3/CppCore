#include "AppleLogger.h"

#if PLATFORM_GROUP_APPLE

#include <Foundation/Foundation.h>

CORE_API void CAppleLogger::WriteLogLine(const std::string &LogLine) const
{
    // Write to Apple's logging system
    NSLog(@"%s", LogLine.c_str());
}

#endif // PLATFORM_GROUP_APPLE