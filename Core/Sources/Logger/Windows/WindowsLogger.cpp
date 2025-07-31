#include "WindowsLogger.h"

#if PLATFORM_WINDOWS

#include "Process/Process.h"

#include <Windows.h>
#include <iostream>

void CWindowsLogger::WriteLogLine(const std::string& LogLine) const
{
	std::string Line = LogLine + IEnvironment::NewLine();

	Super::WriteLogLine(Line);

	std::cout << Line << IEnvironment::NewLine();

	OutputDebugStringA(Line.c_str());
}

CWindowsLogger::CWindowsLogger() :
	Super()
{
	if (AttachConsole(ATTACH_PARENT_PROCESS)) 
	{
		FILE* f_out;
		freopen_s(&f_out, "CONOUT$", "w", stdout);  // Redirect stdout to console
		freopen_s(&f_out, "CONOUT$", "w", stderr);  // Redirect stderr to console
	}
}

#endif