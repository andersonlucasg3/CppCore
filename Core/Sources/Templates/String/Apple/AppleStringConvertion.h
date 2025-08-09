#pragma once

#include "String/String.h"

#include <Foundation/NSString.hpp>

extern CString NSStringToCString(NS::String* InString);

extern NS::String* CStringToNSString(const CString& InString);