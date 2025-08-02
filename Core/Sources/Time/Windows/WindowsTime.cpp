#include "WindowsTime.h"

#if PLATFORM_WINDOWS

#include <Windows.h>

Double CWindowsTime::GetTimeInSecondsInternal() const
{
	LARGE_INTEGER Frequency;
	QueryPerformanceFrequency(&Frequency);

	LARGE_INTEGER Counter;
	QueryPerformanceCounter(&Counter);

	return static_cast<Double>(Counter.QuadPart) / static_cast<Double>(Frequency.QuadPart);
}

#endif // PLATFORM_WINDOWS