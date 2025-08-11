#pragma once

#include "Process/Desktop/DesktopProcess.h"

#include "Templates/Array.h"

#include "String/String.h"

class CWindowsProcess : public CDesktopProcess
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