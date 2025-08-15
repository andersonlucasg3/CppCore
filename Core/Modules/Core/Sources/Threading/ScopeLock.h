#pragma once

#include "Defines/Preprocessors.h"

#include COMPILE_PLATFORM_HEADER(CriticalSection.h)

struct SScopeLock
{
    CORE_API SScopeLock(SPlatformCriticalSection& Section);
    CORE_API ~SScopeLock();

private:
    SPlatformCriticalSection& Section;
};