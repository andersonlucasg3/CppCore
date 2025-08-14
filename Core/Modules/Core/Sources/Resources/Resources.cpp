#include "Resources.h"

#include "Defines/Preprocessors.h"

#include COMPILE_PLATFORM_HEADER(Resources.h)

static CPlatformResources GPlatformResources;
const CResources& GResources = GPlatformResources;