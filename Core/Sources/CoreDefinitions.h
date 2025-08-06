#pragma once

#include "Defines/PlatformInfo.h"
#include "Defines/Preprocessors.h"
#include "Defines/Types.h"

#define CORE_CLASS_HEADER(ClassName)                                            \
class C##ClassName;                                                             \
using C##ClassName##Ptr = TSharedPtr<C##ClassName>;                             \
using C##ClassName##WeakPtr = TWeakPtr<C##ClassName>