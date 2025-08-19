#include "CriticalSection.h"

void SCriticalSection::Lock()
{
    _mutex.lock();
}

bool SCriticalSection::TryLock()
{
    return _mutex.try_lock();
}

void SCriticalSection::Unlock()
{
    _mutex.unlock();
}