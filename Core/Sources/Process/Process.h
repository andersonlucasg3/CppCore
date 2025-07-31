#pragma once

#include "CoreDefinitions.h"

#include "Templates/String/String.h"

class CProcess
{
protected:
    CORE_API CProcess();

public:
    CORE_API virtual ~CProcess() = default;

    CORE_API virtual void SetCommandLine(int argc, const char* argv[]) = 0;
    CORE_API virtual const CString& GetExecutablePath() const = 0;
    CORE_API virtual const CString& GetExecutableContainerPath() const = 0;
    CORE_API virtual const TArray<CString>& GetCommandLineArgs() const = 0;
};

extern CProcess& GProcess;