#include "AppleTime.h"

#if PLATFORM_APPLE

#include <CoreFoundation/CoreFoundation.h>
#include <mach/mach_time.h> 

CORE_API SDouble CAppleTime::GetTimeInSecondsInternal() const
{
    UInt64 timeBase = mach_absolute_time();
    mach_timebase_info_data_t timebaseInfo;
    mach_timebase_info(&timebaseInfo);
    UInt64 nanoseconds = timeBase * timebaseInfo.numer / timebaseInfo.denom;
    SDouble seconds = static_cast<SDouble>(nanoseconds) / 1e9;
    return seconds;
}

#endif // PLATFORM_APPLE
