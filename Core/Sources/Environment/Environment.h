#pragma once

#include "CoreDefinitions.h"

class IEnvironment
{
    CORE_API static IEnvironment* Get();
    
protected:
	CORE_API virtual const char* NewLineInternal() const = 0;

public:
	CORE_API virtual ~IEnvironment();

	CORE_API static const char* NewLine();
};
