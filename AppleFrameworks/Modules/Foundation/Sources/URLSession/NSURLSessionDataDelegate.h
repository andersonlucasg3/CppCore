#pragma once

#include "NSURLSession.h"
#include "NSURLSessionTaskDelegate.h"

namespace NS
{
    class Data;

    class URLSession;
    class URLResponse;
    class URLSessionDownloadTask;
    class URLSessionStreamTask;

    class CachedURLResponse;

    enum URLSessionResponseDisposition : Integer;

    typedef std::function<void(URLSessionResponseDisposition)> URLSessionDataTaskDidReceiveResponseCompletionHandler;
    typedef std::function<void(CachedURLResponse*)> URLSessionDataTaskWillCacheResponseCompletionHandler;

    class URLSessionDataDelegate : public URLSessionTaskDelegate
    {
    public:
        FOUNDATION_API URLSessionDataDelegate() = default;
        FOUNDATION_API ~URLSessionDataDelegate() override = default;
        
        FOUNDATION_API virtual void URLSessionDataTaskDidReceiveResponse(URLSession* /* session */, URLSessionDataTask* /* dataTask */, URLResponse* /* response */, const URLSessionDataTaskDidReceiveResponseCompletionHandler& completionHandler)
        {
            completionHandler(URLSessionResponseAllow);
        }

        FOUNDATION_API virtual void URLSessionDataTaskDidBecomeDownloadTask(URLSession* /* session */, URLSessionDataTask* /* dataTask */, URLSessionDownloadTask* /* downloadTask */) {}
        FOUNDATION_API virtual void URLSessionDataTaskDidBecomeStreamTask(URLSession* /* session */, URLSessionDataTask* /* dataTask */, URLSessionStreamTask* /* streamTask */) {}
        FOUNDATION_API virtual void URLSessionDataTaskDidReceiveData(URLSession* /* session */, URLSessionDataTask* /* dataTask */, Data* /* data */) {}

        FOUNDATION_API virtual void URLSessionDataTaskWillCacheResponse(URLSession* /* session */, URLSessionDataTask* /* dataTask */, CachedURLResponse* proposedResponse, const URLSessionDataTaskWillCacheResponseCompletionHandler& completionHandler)
        {
            completionHandler(proposedResponse);
        }
    };
}