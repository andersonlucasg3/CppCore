#include "WindowsEnvironment.h"

#if PLATFORM_WINDOWS

const char* CWindowsEnvironment::NewLineInternal() const
{
	return "\r\n";
}

#endif