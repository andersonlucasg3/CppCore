#pragma once

#include "NSObject.hpp"
#include "NSDefines.h"
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