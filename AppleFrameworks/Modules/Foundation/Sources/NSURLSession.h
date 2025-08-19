#pragma once

#include "NSObject.hpp"
#include "NSURLSessionDelegate.h"
#include <memory>

namespace NS
{
    class URLSession : public Copying<URLSession>
    {
    public:
        FOUNDATION_API static URLSession* sharedSession();

        FOUNDATION_API void setDelegate(const std::shared_ptr<URLSessionDelegate>& InDelegate);
    };
}