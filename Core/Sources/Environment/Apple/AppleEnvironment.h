#pragma once

#if PLATFORM_MACOS

#include "Environment/Environment.h"

class CAppleEnvironment : public IEnvironment
{
protected:
    CORE_API virtual const char* NewLineInternal() const override;

public:
    CORE_API ~CAppleEnvironment() override = default;
};

typedef CAppleEnvironment CPlatformEnvironment;

#endif