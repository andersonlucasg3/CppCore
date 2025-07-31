#pragma once

#include "CoreDefinitions.h"

#if PLATFORM_WINDOWS

#include "Environment/Environment.h"

class CWindowsEnvironment : public IEnvironment
{
protected:
	CORE_API virtual const char* NewLineInternal() const override;

public:
	CORE_API ~CWindowsEnvironment() override = default;
};

typedef CWindowsEnvironment CPlatformEnvironment;

#endif