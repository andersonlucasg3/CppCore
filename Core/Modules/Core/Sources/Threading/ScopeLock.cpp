#include "ScopeLock.h"

SScopeLock::SScopeLock(SPlatformCriticalSection& Section) :
    Section(Section)
{
    Section.Lock();
}

SScopeLock::~SScopeLock()
{
    Section.Unlock();
}