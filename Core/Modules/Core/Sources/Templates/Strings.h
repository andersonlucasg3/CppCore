#pragma once

#include "Defines/Preprocessors.h"
#include "String/String.h"

#include "Defines/Preprocessors.h"

#if PLATFORM_GROUP_APPLE
#include COMPILE_PLATFORM_HEADER_FEATURE(Templates/String,StringConvertion.h)
#endif // PLATFORM_GROUP_APPLE