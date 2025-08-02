#pragma once

#include "CoreDefinitions.h"

#if PLATFORM_WINDOWS

#include "Time/Time.h"

class CWindowsTime : public ITime
{
protected:
	CORE_API Double GetTimeInSecondsInternal() const override;

public:
	CORE_API ~CWindowsTime() override = default;
};

typedef CWindowsTime CPlatformTime;

#endif