#pragma once

#include "CoreDefinitions.h"

#include <mutex>

struct SCriticalSection
{
    CORE_API void Lock();
    CORE_API bool TryLock();
    CORE_API void Unlock();

private:
    std::mutex Mutex;
};