#include "MobileProcess.h"

#include "Defines/Preprocessors.h"

#include COMPILE_PLATFORM_HEADER_FEATURE(Process, Process.h)

static CPlatformProcess GPlatformProcess;
CMobileProcess& GMobileProcess = GPlatformProcess;
CProcess& GProcess = GMobileProcess;