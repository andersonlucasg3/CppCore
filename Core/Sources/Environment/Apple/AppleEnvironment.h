#pragma once

#if PLATFORM_MACOS

#include "Environment/Environment.h"

class CAppleEnvironment : public CEnvironment
{
public:
    CORE_API ~CAppleEnvironment() override = default;

    CORE_API const char* NewLine() const override;
};

typedef CAppleEnvironment CPlatformEnvironment;

#endif