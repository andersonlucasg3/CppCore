#include "Memory.h"

#include "Defines/Preprocessors.h"

#include COMPILE_PLATFORM_HEADER(Memory.h)

static CPlatformMemory GPlatformMemory;
const CMemory& GMemory = GPlatformMemory;