#include "DesktopProcess.h"

#if PLATFORM_TYPE_DESKTOP

#include "Defines/Preprocessors.h"

#include COMPILE_PLATFORM_HEADER_FEATURE(Process, Process.h)

static const CPlatformProcess GPlatformProcess;
const CDesktopProcess& GProcess = GPlatformProcess;

#endif