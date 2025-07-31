#pragma once

#include "CoreDefinitions.h"

#include "CriticalSection.h"

struct SScopeLock
{
    CORE_API SScopeLock(SCriticalSection& Section);
    CORE_API ~SScopeLock();

private:
    SCriticalSection& Section;
};