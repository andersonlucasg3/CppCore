#pragma once

#include "Defines/PlatformInfo.h"

#if PLATFORM_MACOS

#include "Filesystem/Apple/AppleDirectoryReference.h"

typedef CAppleDirectoryReference CPlatformDirectoryReference;

#endif // PLATFORM_MACOS