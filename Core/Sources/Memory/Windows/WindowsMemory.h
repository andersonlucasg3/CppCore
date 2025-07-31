#pragma once

#include "CoreDefinitions.h"

#if PLATFORM_WINDOWS

#include "Memory/Memory.h"

class CWindowsMemory : public CMemory
{
public:
	CWindowsMemory() = default;
	~CWindowsMemory() override = default;
};

typedef CWindowsMemory CPlatformMemory;

#endif // PLATFORM_WINDOWS