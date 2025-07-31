#include "CriticalSection.h"

void SCriticalSection::Lock()
{
    Mutex.lock();
}

bool SCriticalSection::TryLock()
{
    return Mutex.try_lock();
}

void SCriticalSection::Unlock()
{
    Mutex.unlock();
}