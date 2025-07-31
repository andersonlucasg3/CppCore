#pragma once

#include "CoreDefinitions.h"

#if PLATFORM_WINDOWS

#include "Process/Process.h"

class CWindowsProcess : public IProcess
{
	static CWindowsProcess* GProcess;

	CString ExecutablePath;
	CString ExecutableContainerPath;
	TArray<CString> CommandLineArgs;

public:
	CORE_API CWindowsProcess();
	CORE_API ~CWindowsProcess() override = default;

	CORE_API void SetCommandLine(int argc, const char** argv);
	CORE_API const CString& GetExecutablePath() const override;
	CORE_API const CString& GetExecutableContainerPath() const override;
	CORE_API const TArray<CString>& GetCommandLineArgs() const override;

	CORE_API static CWindowsProcess* Get();
};

typedef CWindowsProcess CPlatformProcess;

#endif // PLATFORM_WINDOWS