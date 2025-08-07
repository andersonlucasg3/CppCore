#pragma once

#if PLATFORM_GROUP_APPLE

#include "Templates/String/String.h"

#include <Foundation/NSString.hpp>

extern CString NSStringToCString(NS::String* InString);

extern NS::String* CStringToNSString(const CString& InString);

#endif // PLATFORM_GROUP_APPLE