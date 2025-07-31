#pragma once

#include "CoreDefinitions.h"

#if PLATFORM_MACOS

#include "Process/Apple/AppleProcess.h"

typedef CAppleProcess CPlatformProcess;

#endif // PLATFORM_MACOS