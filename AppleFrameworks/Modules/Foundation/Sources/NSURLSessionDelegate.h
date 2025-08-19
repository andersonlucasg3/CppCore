#pragma once

#include "NSError.h"
#include "NSURLCredential.h"
#include "URLAuthenticationChallenge.h"

#if __OBJC__
#include <Foundation/Foundation.h>
#include <__memory/shared_ptr.h>
#endif // __OBJC__

namespace NS
{
    class URLSession;

    typedef void (^URLSessionChallengeCompletionHandler)(URLSessionAuthChallengeDisposition disposition, URLCredential* credential);

    class URLSessionDelegate
    {
    public:
        FOUNDATION_API URLSessionDelegate() = default;
        FOUNDATION_API virtual ~URLSessionDelegate() = default;

        FOUNDATION_API virtual void URLSessionDidBecomeInvalidWithError(URLSession* Session, Error* Error) = 0;
        FOUNDATION_API virtual void URLSessionDidFinishEventsForBackgroundURLSession(URLSession* Session) = 0;
        FOUNDATION_API virtual void URLSessionDidReceiveChallenge(URLSession* Session, URLAuthenticationChallenge* Challenge, URLSessionChallengeCompletionHandler Handler);
    };
}