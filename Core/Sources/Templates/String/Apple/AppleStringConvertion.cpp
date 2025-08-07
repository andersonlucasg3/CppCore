#include "AppleStringConvertion.h"

#if PLATFORM_GROUP_APPLE

CString NSStringToCString(NS::String* InString)
{
    return CString(InString->utf8String(), InString->length());
}

NS::String* CStringToNSString(const CString& InString)
{
    return NS::String::string(*InString, NS::UTF8StringEncoding);
}

#endif // PLATFORM_GROUP_APPLE