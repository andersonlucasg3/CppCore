#include "ScopeLock.h"

SScopeLock::SScopeLock(SCriticalSection& Section) 
:   _section(Section)
{
    Section.Lock();
}

SScopeLock::~SScopeLock()
{
    _section.Unlock();
}