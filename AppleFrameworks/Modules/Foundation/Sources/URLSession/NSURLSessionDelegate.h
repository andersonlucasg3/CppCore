#pragma once

#include "NSTypes.h"
#include "NSURLAuthenticationChallenge.h"

#include <functional>

namespace NS
{
    class URLSession;
    class URLCredential;
    class URLAuthenticationChallenge;
    class Error;
    enum URLSessionAuthChallengeDisposition : Integer;

    typedef std::function<void(URLSessionAuthChallengeDisposition, URLCredential*)> URLSessionChallengeCompletionHandler;

    class URLSessionDelegate
    {
    public:
        FOUNDATION_API URLSessionDelegate() = default;
        FOUNDATION_API virtual ~URLSessionDelegate() = default;

        FOUNDATION_API virtual void URLSessionDidBecomeInvalidWithError(URLSession* /* session */, Error* /* error */) {}
        FOUNDATION_API virtual void URLSessionDidFinishEventsForBackgroundURLSession(URLSession* /* session */) {}

        FOUNDATION_API virtual void URLSessionDidReceiveChallenge(URLSession* /* session */, URLAuthenticationChallenge* /* challenge */, const URLSessionChallengeCompletionHandler& completionHandler)
        {
            completionHandler(URLSessionAuthChallengePerformDefaultHandling, nullptr);
        }
    };
}