#include "DesktopCriticalSection.h"

void SDesktopCriticalSection::Lock()
{
    _mutex.lock();
}

bool SDesktopCriticalSection::TryLock()
{
    return _mutex.try_lock();
}

void SDesktopCriticalSection::Unlock()
{
    _mutex.unlock();
}