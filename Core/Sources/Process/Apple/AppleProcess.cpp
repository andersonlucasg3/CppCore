#include "AppleProcess.h"

#if PLATFORM_GROUP_APPLE

#include "Filesystem/Path.h"

void CAppleProcess::SetCommandLine(int argc, const char* argv[])
{
    ExecutablePath = argv[0];
    ExecutableContainerPath = GPath.RemoveLastPathComponent(ExecutablePath);
    for (int Index = 1; Index < argc; ++Index)
    {
        CommandLineArgs.Add(argv[Index]);
    }
}

const CString& CAppleProcess::GetExecutablePath() const
{
    return ExecutablePath;
}

const CString& CAppleProcess::GetExecutableContainerPath() const
{
    return ExecutableContainerPath;
}

const TArray<CString>& CAppleProcess::GetCommandLineArgs() const
{
    return CommandLineArgs;
}

bool CAppleProcess::IsRunningOnAppBundle() const
{
    return ExecutableContainerPath.EndsWith(".app");
}

CAppleProcess& CAppleProcess::Get()
{
    return static_cast<CAppleProcess&>(GProcess);
}

#endif // PLATFORM_GROUP_APPLE