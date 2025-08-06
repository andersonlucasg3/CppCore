#pragma once

#if PLATFORM_APPLE

#include "Memory/Memory.h"

class CAppleMemory : public CMemory
{
public:
    CAppleMemory() = default;
    ~CAppleMemory() override = default;
};

typedef CAppleMemory CPlatformMemory;

#endif // PLATFORM_APPLE