#include "MobileProcess.h"

#if PLATFORM_TYPE_MOBILE

#include "Defines/Preprocessors.h"

#include COMPILE_PLATFORM_HEADER_FEATURE(Process, Process.h)

static const CPlatformProcess GPlatformProcess;
const CMobileProcess& GProcess = GPlatformProcess;

#endif