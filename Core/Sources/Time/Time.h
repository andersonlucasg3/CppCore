#pragma once

#include "CoreDefinitions.h"

using namespace Core::Types;

class ITime
{
	CORE_API static ITime* GetTime();

	CORE_API virtual Double GetTimeInSecondsInternal() const = 0;

public:
	CORE_API virtual ~ITime() = default;

	CORE_API static Double GetTimeInSeconds();
};
