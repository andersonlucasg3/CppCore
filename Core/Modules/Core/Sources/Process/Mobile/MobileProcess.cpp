#include "MobileProcess.h"

#include "Defines/Preprocessors.h"

#include COMPILE_PLATFORM_HEADER_FEATURE(Process, Process.h)

static const CPlatformProcess GPlatformProcess;
const CMobileProcess& GMobileProcess = GPlatformProcess;
const CProcess& GProcess = GMobileProcess;