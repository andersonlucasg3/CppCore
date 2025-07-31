#pragma once

#include "CoreDefinitions.h"

#if PLATFORM_APPLE

#include "Process/Process.h"

class CAppleProcess : public CProcess
{
    CString ExecutablePath;
    CString ExecutableContainerPath;
    TArray<CString> CommandLineArgs;
    
public:
    CORE_API CAppleProcess() = default;
    CORE_API ~CAppleProcess() override = default;

    CORE_API void SetCommandLine(int argc, const char* argv[]) override;
    CORE_API const CString& GetExecutablePath() const override;
    CORE_API const CString& GetExecutableContainerPath() const override;
    CORE_API const TArray<CString>& GetCommandLineArgs() const override;
    
    CORE_API bool IsRunningOnAppBundle() const;

    CORE_API static CAppleProcess& Get();
};

#endif // PLATFORM_APPLE