#pragma once

#include "Defines/PlatformInfo.h"
#include "Defines/Preprocessors.h"
#include "Defines/Types.h"

#if PLATFORM_WINDOWS

#ifdef BUILDING_CORE_MODULE
#define CORE_API __declspec(dllexport)
#else
#define CORE_API __declspec(dllimport)
#endif

#else // PLATFORM_WINDOWS

#define CORE_API

#endif // PLATFORM_WINDOWS

#define CORE_CLASS_HEADER(ClassName)                                            \
class C##ClassName;                                                             \
using C##ClassName##Ptr = TSharedPtr<C##ClassName>;                             \
using C##ClassName##WeakPtr = TWeakPtr<C##ClassName>