#include "DesktopProcess.h"

#include "Defines/Preprocessors.h"

#include COMPILE_PLATFORM_HEADER_FEATURE(Process, Process.h)

static CPlatformProcess GPlatformProcess;
CDesktopProcess& GDesktopProcess = GPlatformProcess;
CProcess& GProcess = GDesktopProcess;