#include "WindowsProcess.h"

#if PLATFORM_WINDOWS

#include "Filesystem/Path.h"

CWindowsProcess* CWindowsProcess::GProcess = nullptr;

CWindowsProcess::CWindowsProcess()
{
	GProcess = this;
}

void CWindowsProcess::SetCommandLine(int argc, const char** argv)
{
	ExecutablePath = argv[0];
	ExecutableContainerPath = IPath::Get()->RemoveLastPathComponent(ExecutablePath);

	for (int Index = 1; Index < argc; ++Index)
	{
		CommandLineArgs.Add(argv[Index]);
	}
}

const CString& CWindowsProcess::GetExecutablePath() const
{
	return ExecutablePath;
}

const CString& CWindowsProcess::GetExecutableContainerPath() const
{
	return ExecutableContainerPath;
}

const TArray<CString>& CWindowsProcess::GetCommandLineArgs() const
{
	return CommandLineArgs;
}

CWindowsProcess* CWindowsProcess::Get()
{
	return GProcess;
}

#endif // PLATFORM_WINDOWS