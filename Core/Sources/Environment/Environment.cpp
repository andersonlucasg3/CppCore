#include "Environment.h"

#include "Defines/Preprocessors.h"

#include COMPILE_PLATFORM_HEADER(Environment.h)

CPlatformEnvironment GEnvironment;

IEnvironment* IEnvironment::Get()
{
    return &GEnvironment;
}

IEnvironment::~IEnvironment()
{
	//
}

const char* IEnvironment::NewLine()
{
	return Get()->NewLineInternal();
}
