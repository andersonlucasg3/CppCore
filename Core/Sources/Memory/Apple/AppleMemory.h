#pragma once

#if PLATFORM_GROUP_APPLE

#include "Memory/Memory.h"

class CAppleMemory : public CMemory
{
public:
    CAppleMemory() = default;
    ~CAppleMemory() override = default;
};

typedef CAppleMemory CPlatformMemory;

#endif // PLATFORM_GROUP_APPLE