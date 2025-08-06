#pragma once

#include "Class.h"

CORE_CLASS_HEADER(Object);

class CObject
{	
public:
	CORE_API CObject() = default;
	CORE_API virtual ~CObject() = default;

	template<typename TOther>
	bool IsA()
	{
		return dynamic_cast<TOther*>(this) != nullptr;
	}
};