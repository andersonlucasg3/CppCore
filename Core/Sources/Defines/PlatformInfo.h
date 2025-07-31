#pragma once

#ifndef PLATFORM_NAME
#define PLATFORM_NAME #error "Platform not defined"
#endif

#ifndef PLATFORM_GROUP_NAME
#define PLATFORM_GROUP_NAME #error "Platform group not defined"
#endif

#ifndef PLATFORM_WINDOWS
#define PLATFORM_WINDOWS 0
#endif

#ifndef PLATFORM_ANDROID
#define PLATFORM_ANDROID 0
#endif

#ifndef PLATFORM_APPLE
#define PLATFORM_APPLE 0
#endif

#ifndef PLATFORM_MACOS
#define PLATFORM_MACOS 0
#endif

#ifndef PLATFORM_IOS
#define PLATFORM_IOS 0
#endif

#ifndef PLATFORM_TVOS
#define PLATFORM_TVOS 0
#endif

#ifndef PLATFORM_IPADOS
#define PLATFORM_IPADOS 0
#endif

#if defined(WIN32) || defined(_WIN32)

#undef PLATFORM_NAME
#undef PLATFORM_GROUP_NAME
#undef PLATFORM_WINDOWS

#define PLATFORM_NAME Windows
#define PLATFORM_GROUP_NAME Microsoft
#define PLATFORM_WINDOWS 1

#elif defined(__APPLE__)

#include <TargetConditionals.h>

#undef PLATFORM_NAME
#undef PLATFORM_GROUP_NAME
#undef PLATFORM_APPLE

#define PLATFORM_NAME Mac
#define PLATFORM_GROUP_NAME Apple
#define PLATFORM_APPLE 1

#if TARGET_OS_MAC

#undef PLATFORM_MACOS
#define PLATFORM_MACOS 1

#elif TARGET_OS_IPHONE

#undef PLATFORM_IOS
#define PLATFORM_IOS 1

#elif TARGET_OS_TV

#undef PLATFORM_TVOS
#define PLATFORM_TVOS 1

#elif TARGET_OS_IPAD

#undef PLATFORM_IPADOS
#define PLATFORM_IPADOS 1

#endif

#endif

#ifdef WITH_DEBUG
#undef WITH_DEBUG
#define WITH_DEBUG          1
#else
#define WITH_DEBUG          0
#endif // WITH_DEBUG

#ifdef WITH_EDITOR
#undef WITH_EDITOR
#define WITH_EDITOR         1
#else
#define WITH_EDITOR         0
#endif