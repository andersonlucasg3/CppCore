#include "Memory.h"

#include "Defines/Preprocessors.h"
#include "Defines/Types.h"

#include <cstdlib>
#include <cstring>

#include COMPILE_PLATFORM_HEADER(Memory.h)

static CPlatformMemory GPlatformMemory;
const CMemory& GMemory = GPlatformMemory;

void* CMemory::Alloc(size_t InSize) const
{
	return malloc(InSize);
}

void CMemory::Free(void* InPtr) const
{
	free(InPtr);
}

void* CMemory::Copy(const void* From, void* To, SizeT Size) const
{
	return memcpy(To, From, Size);
}

void* CMemory::Set(void* Ptr, int Val, SizeT Size) const
{
	return memset(Ptr, Val, Size);
}

bool CMemory::Equal(const void* Ptr1, UInt64 Ptr1Size, const void* Ptr2, UInt64 Ptr2Size) const
{
	if (Ptr1Size != Ptr2Size) return false;

	return memcmp(Ptr1, Ptr2, Ptr1Size) == 0; // equal
}