#pragma once

#include "NSURLSessionDelegate.h"
#include "URLSession/NSURLSession.h"

namespace NS
{
    class InputStream;

    class URLSession;
    class URLRequest;
    class URLResponse;
    class URLSessionTask;

    enum URLSessionDelayedRequestDisposition : Integer;

    typedef std::function<void(URLSessionDelayedRequestDisposition, URLRequest*)> URLSessionTaskWillBeginDelayedRequestCompletionHandler;
    typedef std::function<void(URLRequest*)> URLSessionTaskWillPerformHTTPRedirectionCompletionHandler;
    typedef std::function<void(URLSessionAuthChallengeDisposition, URLCredential*)> URLSessionTaskDidReceiveChallengeCompletionHandler;
    typedef std::function<void(InputStream*)> URLSessionTaskNeedNewBodyStreamCompletionHandler;
    typedef std::function<void(InputStream*)> URLSessionTaskNeedNewBodyStreamFromOffsetCompletionHandler;

    class URLSessionTaskDelegate : public URLSessionDelegate
    {
    public:
        FOUNDATION_API virtual void URLSessionDidCreateTask(URLSession* /* session */, URLSessionTask* /* task */) {}

        FOUNDATION_API virtual void URLSessionTaskWillBeginDelayedRequest(URLSession* /* session */, URLSessionTask* /* task */, URLRequest* request, const URLSessionTaskWillBeginDelayedRequestCompletionHandler& completionHandler) 
        {
            completionHandler(URLSessionDelayedRequestContinueLoading, request);
        }

        FOUNDATION_API virtual void URLSessionTaskIsWaitingForConnectivity(URLSession* /* session */, URLSessionTask* /* task */) {}
        FOUNDATION_API virtual void URLSessionTaskWillPerformHTTPRedirection(URLSession* /* session */, URLSessionTask* /* task */, URLResponse* /* response */, URLRequest* /* request */, const URLSessionTaskWillPerformHTTPRedirectionCompletionHandler& /* completionHandler */) {}
        FOUNDATION_API virtual void URLSessionTaskDidReceiveChallenge(URLSession* /* session */, URLSessionTask* /* task */, URLAuthenticationChallenge* /* challenge */, const URLSessionTaskDidReceiveChallengeCompletionHandler& /* completionHandler */) {}
        FOUNDATION_API virtual void URLSessionTaskNeedNewBodyStream(URLSession* /* session */, URLSessionTask* /* task */, const URLSessionTaskNeedNewBodyStreamCompletionHandler& /* completionHandler */) {}
        FOUNDATION_API virtual void URLSessionTaskNeedNewBodyStreamFromOffset(URLSession* /* session */, URLSessionTask* /* task */, int64_t /* offset */, const URLSessionTaskNeedNewBodyStreamFromOffsetCompletionHandler& /* completionHandler */) {}
    };
}