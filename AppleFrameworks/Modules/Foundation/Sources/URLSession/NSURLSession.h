#pragma once

#include "NSObject.hpp"
#include "NSDefines.h"

namespace NS
{
    _NS_ENUM(Integer, URLSessionDelayedRequestDisposition)
    {
        URLSessionDelayedRequestContinueLoading = 0,
        URLSessionDelayedRequestUseNewRequest = 1,
        URLSessionDelayedRequestCancel = 2,
    };

    class URLSession : public Copying<URLSession>
    {
    public:
        FOUNDATION_API static URLSession* sharedSession();

        FOUNDATION_API class URLSessionDataTask* dataTask(class URL* url);
    };
}