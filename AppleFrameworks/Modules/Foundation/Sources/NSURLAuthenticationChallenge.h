#pragma once

#include "NSDefines.h"
#include "NSObject.hpp"
#include "NSTypes.h"

namespace NS
{
    _NS_ENUM(Integer, URLSessionAuthChallengeDisposition)
    {
        URLSessionAuthChallengeUseCredential = 0,
        URLSessionAuthChallengePerformDefaultHandling = 1,
        URLSessionAuthChallengeCancelAuthenticationChallenge = 2,
        URLSessionAuthChallengeRejectProtectionSpace = 3,
    };

    // TODO: implement

    class URLAuthenticationChallenge : public Copying<URLAuthenticationChallenge>
    {
    public:
        
    };
}