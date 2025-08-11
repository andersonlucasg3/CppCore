#include "MacProcess.h"

#include "Filesystem/Path.h"

void CMacProcess::SetCommandLine(int argc, const char* argv[])
{
    ExecutablePath = argv[0];
    ExecutableContainerPath = GPath.RemoveLastPathComponent(ExecutablePath);
    for (int Index = 1; Index < argc; ++Index)
    {
        CommandLineArgs.Add(argv[Index]);
    }
}

const CString& CMacProcess::GetExecutablePath() const
{
    return ExecutablePath;
}

const CString& CMacProcess::GetExecutableContainerPath() const
{
    return ExecutableContainerPath;
}

const TArray<CString>& CMacProcess::GetCommandLineArgs() const
{
    return CommandLineArgs;
}

bool CMacProcess::IsRunningOnAppBundle() const
{
    return ExecutableContainerPath.EndsWith(".app");
}