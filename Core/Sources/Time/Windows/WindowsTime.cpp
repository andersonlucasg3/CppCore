#include "WindowsTime.h"

#if PLATFORM_WINDOWS

#include <Windows.h>

SDouble CWindowsTime::GetTimeInSecondsInternal() const
{
	LARGE_INTEGER Frequency;
	QueryPerformanceFrequency(&Frequency);

	LARGE_INTEGER Counter;
	QueryPerformanceCounter(&Counter);

	return static_cast<SDouble>(Counter.QuadPart) / static_cast<SDouble>(Frequency.QuadPart);
}

#endif // PLATFORM_WINDOWS