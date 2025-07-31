#include "Time.h"

#include "Defines/Preprocessors.h"

#include COMPILE_PLATFORM_HEADER(Time.h)

CPlatformTime GTime;

ITime* ITime::GetTime()
{
	return &GTime;
}

SDouble ITime::GetTimeInSeconds()
{
	return GetTime()->GetTimeInSecondsInternal();
}
