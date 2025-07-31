#pragma once

#include "CoreDefinitions.h"

#include <cstddef>

using namespace Core::Types;

class CMemory
{
protected:
	CORE_API CMemory() = default;
	CORE_API virtual ~CMemory() = default;

public:
	CORE_API inline virtual void* Alloc(size_t InSize) const;
	CORE_API inline virtual void Free(void* InPtr) const;
	CORE_API inline virtual void* Copy(const void* From, void* To, SSizeT Size) const;
	CORE_API inline virtual void* Set(void* Ptr, int Val, SSizeT Size) const;
	CORE_API inline virtual bool Equal(const void* Ptr1, UInt64 Ptr1Size, const void* Ptr2, UInt64 Ptr2Size) const;

	template<typename TPtr>
	TPtr* Alloc()
	{
		return (TPtr*)Alloc(sizeof(TPtr));
	}
};

extern const CMemory& GMemory;