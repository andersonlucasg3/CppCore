#pragma once

#include <mutex>

struct SCriticalSection
{
    CORE_API SCriticalSection() = default;
    CORE_API virtual ~SCriticalSection() = default;

    CORE_API virtual void Lock();
    CORE_API virtual bool TryLock();
    CORE_API virtual void Unlock();

private:
    std::mutex _mutex;
};