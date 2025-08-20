#pragma once

#include "NSObject.hpp"

namespace NS
{
    class URLSessionTask : Copying<URLSessionTask>
    {
    public:
        FOUNDATION_API void cancel();
        FOUNDATION_API void resume();
        FOUNDATION_API void suspend();
    };
}