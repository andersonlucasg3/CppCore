#pragma once

#include "NSObject.hpp"

namespace NS
{
    class URLSessionTaskDelegate;

    class URLSessionTask : public Copying<URLSessionTask>
    {
    public:
        FOUNDATION_API void cancel();
        FOUNDATION_API void resume();
        FOUNDATION_API void suspend();

        FOUNDATION_API URLSessionTaskDelegate* delegate();
        FOUNDATION_API void setDelegate(URLSessionTaskDelegate* InDelegate);
    };
}