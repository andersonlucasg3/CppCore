#include "ScopeLock.h"

SScopeLock::SScopeLock(SCriticalSection& Section) :
    Section(Section)
{
    Section.Lock();
}

SScopeLock::~SScopeLock()
{
    Section.Unlock();
}