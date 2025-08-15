#pragma once

struct SCriticalSection
{
    CORE_API virtual ~SCriticalSection() = default;

    CORE_API virtual void Lock() = 0;
    CORE_API virtual bool TryLock() = 0;
    CORE_API virtual void Unlock() = 0;
};