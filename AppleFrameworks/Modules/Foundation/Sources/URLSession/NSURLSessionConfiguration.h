#pragma once

#include "NSObject.hpp"

namespace NS
{
    class URLSessionConfiguration : Copying<URLSessionConfiguration>
    {
    public:
        FOUNDATION_API static URLSessionConfiguration* defaultSessionConfiguration();
        FOUNDATION_API static URLSessionConfiguration* ephemeralSessionConfiguration();
    };
}