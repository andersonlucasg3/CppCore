#pragma once

#include "Defines/PlatformInfo.h"

#if PLATFORM_MACOS

#include "Filesystem/Apple/AppleFileReference.h"

typedef CAppleFileReference CPlatformFileReference;

#endif // PLATFORM_MACOS