#pragma once

#include "SmartPointer/SharedPointer.h"

#define DECLARE_CLASS_HEADER(ClassName)                                         \
class C##ClassName;                                                             \
using C##ClassName##Ptr = TSharedPtr<C##ClassName>;                             \
using C##ClassName##WeakPtr = TWeakPtr<C##ClassName>