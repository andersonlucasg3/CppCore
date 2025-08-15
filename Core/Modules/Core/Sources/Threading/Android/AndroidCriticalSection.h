#pragma once

#include "Threading/CriticalSection.h"

#include <bits/pthread_types.h>

struct SAndroidCriticalSection : public SCriticalSection
{
    CORE_API SAndroidCriticalSection();
    CORE_API ~SAndroidCriticalSection() override;

    CORE_API void Lock() override;
    CORE_API bool TryLock() override;
    CORE_API void Unlock() override;

private:
    pthread_mutex_t _mutex;
};

typedef SAndroidCriticalSection SPlatformCriticalSection;