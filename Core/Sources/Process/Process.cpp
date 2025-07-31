#include "Process.h"

#include "Defines/Preprocessors.h"

#include <exception>

#include COMPILE_PLATFORM_HEADER(Process.h)

static CPlatformProcess GPlatformProcess;
CProcess& GProcess = GPlatformProcess;

CProcess::CProcess()
{
    std::set_terminate([] 
    {
        CLogger::LogException();
    });
}