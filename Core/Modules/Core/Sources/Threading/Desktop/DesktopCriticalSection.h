#pragma once

#include "Threading/CriticalSection.h"

#include <mutex>

struct SDesktopCriticalSection : public SCriticalSection
{
    CORE_API SDesktopCriticalSection() = default;
    CORE_API ~SDesktopCriticalSection() override = default;

    CORE_API void Lock() override;
    CORE_API bool TryLock() override;
    CORE_API void Unlock() override;

private:
    std::mutex _mutex;
};