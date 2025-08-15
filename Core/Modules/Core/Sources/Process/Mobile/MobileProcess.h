#pragma once

#include "Process/Process.h"

class CMobileProcess : public CProcess
{
protected:
    CORE_API CMobileProcess() = default;

public:
    CORE_API virtual ~CMobileProcess() override = default;
};

extern const CMobileProcess& GMobileProcess;