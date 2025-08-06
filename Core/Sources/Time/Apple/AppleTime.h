#pragma once

#if PLATFORM_APPLE

#include "Time/Time.h"

class CAppleTime : public ITime
{
protected:
    CORE_API SDouble GetTimeInSecondsInternal() const override;

public:
    CORE_API ~CAppleTime() override = default;
};

typedef CAppleTime CPlatformTime;

#endif // PLATFORM_APPLE
