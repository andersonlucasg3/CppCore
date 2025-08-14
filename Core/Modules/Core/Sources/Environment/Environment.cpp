#include "Environment.h"

#include "Defines/Preprocessors.h"

#include COMPILE_PLATFORM_HEADER(Environment.h)

static const CPlatformEnvironment GPlatformEnvironment;
const CEnvironment& GEnvironment = GPlatformEnvironment;
