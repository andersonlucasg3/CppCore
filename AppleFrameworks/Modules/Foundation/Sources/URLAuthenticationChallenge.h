#pragma once

#include "NSDefines.h"
#include "NSObject.hpp"
#include "NSTypes.h"

namespace NS
{
    _NS_ENUM(Integer, URLSessionAuthChallengeDisposition)
    {
        NSURLSessionAuthChallengeUseCredential = 0,
        NSURLSessionAuthChallengePerformDefaultHandling = 1,
        NSURLSessionAuthChallengeCancelAuthenticationChallenge = 2,
        NSURLSessionAuthChallengeRejectProtectionSpace = 3,
    };

    // TODO: implement

    class URLAuthenticationChallenge : public Copying<URLAuthenticationChallenge>
    {
    public:
        
    };
}