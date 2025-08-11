#pragma once

#if PLATFORM_TYPE_DESKTOP

#include "Process/Process.h"

class CDesktopProcess : public CProcess
{
    using Super = CProcess;

protected:
    CORE_API CDesktopProcess() = default;

public:
    CORE_API virtual ~CDesktopProcess() override = default;

    CORE_API virtual const CString& GetExecutablePath() const = 0;
    CORE_API virtual const CString& GetExecutableContainerPath() const = 0;
};

extern const CDesktopProcess& GProcess;

#endif