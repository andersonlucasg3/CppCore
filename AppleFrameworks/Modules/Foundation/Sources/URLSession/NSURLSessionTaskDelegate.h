#pragma once

#include "NSURLSession.h"
#include "NSURLSessionDelegate.h"
#include "URL/NSURLAuthenticationChallenge.h"

namespace NS
{
    class InputStream;

    class HTTPURLResponse;

    class URLSession;
    class URLRequest;
    class URLSessionTask;
    class URLSessionTaskMetrics;

    enum URLSessionDelayedRequestDisposition : Integer;

    typedef std::function<void(URLSessionDelayedRequestDisposition, URLRequest*)> URLSessionTaskWillBeginDelayedRequestCompletionHandler;
    typedef std::function<void(URLRequest*)> URLSessionTaskWillPerformHTTPRedirectionCompletionHandler;
    typedef std::function<void(URLSessionAuthChallengeDisposition, URLCredential*)> URLSessionTaskDidReceiveChallengeCompletionHandler;
    typedef std::function<void(InputStream*)> URLSessionTaskNeedNewBodyStreamCompletionHandler;
    typedef std::function<void(InputStream*)> URLSessionTaskNeedNewBodyStreamFromOffsetCompletionHandler;

    class URLSessionTaskDelegate : public URLSessionDelegate
    {
    public:
        FOUNDATION_API URLSessionTaskDelegate() = default;
        FOUNDATION_API ~URLSessionTaskDelegate() override = default;
    
        FOUNDATION_API virtual void URLSessionDidCreateTask(URLSession* /* session */, URLSessionTask* /* task */) {}

        FOUNDATION_API virtual void URLSessionTaskWillBeginDelayedRequest(URLSession* /* session */, URLSessionTask* /* task */, URLRequest* request, const URLSessionTaskWillBeginDelayedRequestCompletionHandler& completionHandler) 
        {
            completionHandler(URLSessionDelayedRequestContinueLoading, request);
        }

        FOUNDATION_API virtual void URLSessionTaskIsWaitingForConnectivity(URLSession* /* session */, URLSessionTask* /* task */) {}
        FOUNDATION_API virtual void URLSessionTaskWillPerformHTTPRedirection(URLSession* /* session */, URLSessionTask* /* task */, HTTPURLResponse* /* response */, URLRequest* request, const URLSessionTaskWillPerformHTTPRedirectionCompletionHandler& completionHandler) 
        {
            completionHandler(request);
        }

        FOUNDATION_API virtual void URLSessionTaskDidReceiveChallenge(URLSession* /* session */, URLSessionTask* /* task */, URLAuthenticationChallenge* /* challenge */, const URLSessionTaskDidReceiveChallengeCompletionHandler& completionHandler) 
        {
            completionHandler(URLSessionAuthChallengePerformDefaultHandling, nullptr);
        }

        FOUNDATION_API virtual void URLSessionTaskNeedNewBodyStream(URLSession* /* session */, URLSessionTask* /* task */, const URLSessionTaskNeedNewBodyStreamCompletionHandler& completionHandler) 
        {
            completionHandler(nullptr);
        }

        FOUNDATION_API virtual void URLSessionTaskNeedNewBodyStreamFromOffset(URLSession* /* session */, URLSessionTask* /* task */, int64_t /* offset */, const URLSessionTaskNeedNewBodyStreamFromOffsetCompletionHandler& completionHandler)
        {
            completionHandler(nullptr);
        }

        FOUNDATION_API virtual void URLSessionTaskDidSendBodyData(URLSession* /* session */, URLSessionTask* /* task */, int64_t /* bytesSent */, int64_t /* totalBytesSent */, int64_t /* totalBytesExpectedToSend */) {}
        FOUNDATION_API virtual void URLSessionTaskDidReceiveInformationalResponse(URLSession* /* session */, URLSessionTask* /* task */, HTTPURLResponse* /* response */) {}
        FOUNDATION_API virtual void URLSessionTaskDidFinishCollectingMetrics(URLSession* /* session */, URLSessionTask* /* task */, URLSessionTaskMetrics* /* metrics */) {}
        FOUNDATION_API virtual void URLSessionTaskDidCompleteWithError(URLSession* /* session */, URLSessionTask* /* task */, Error* /* error */) {}
    };
}