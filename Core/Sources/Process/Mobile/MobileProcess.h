#pragma once

#if PLATFORM_TYPE_MOBILE

#include "Process/Process.h"

class CMobileProcess : public CProcess
{
protected:
    CORE_API CMobileProcess() = default;

public:
    CORE_API virtual ~CMobileProcess() override = default;
};

extern const CMobileProcess& GProcess;

#endif