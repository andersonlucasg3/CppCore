#pragma once

#if PLATFORM_WINDOWS

#include "Process/Process.h"

class CWindowsProcess : public CProcess
{
	CString ExecutablePath;
	CString ExecutableContainerPath;
	TArray<CString> CommandLineArgs;

public:
	CORE_API CWindowsProcess() = default;
	CORE_API ~CWindowsProcess() override = default;

	CORE_API void SetCommandLine(int argc, const char** argv) override;
	CORE_API const CString& GetExecutablePath() const override;
	CORE_API const CString& GetExecutableContainerPath() const override;
	CORE_API const TArray<CString>& GetCommandLineArgs() const override;
};

typedef CWindowsProcess CPlatformProcess;

#endif // PLATFORM_WINDOWS