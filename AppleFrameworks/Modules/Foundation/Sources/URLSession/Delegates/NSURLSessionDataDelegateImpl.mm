#include "NSURLSessionDataDelegateImpl.h"

#include "URLSession/NSURLSession.h"

#include "NSData.h"

@implementation NSURLSessionDataDelegateImpl

- (instancetype)initWithDelegate:(URLSessionDataDelegate*) InDelegate 
{
    if (self = [super initWithDelegate:InDelegate])
    {
        DataDelegate = InDelegate;
    }

    return self;
}

- (void)dealloc
{
    DataDelegate = nullptr;
    
    [super dealloc];
}

- (void)URLSession:(NSURLSession *)session dataTask:(NSURLSessionDataTask *)dataTask didReceiveResponse:(NSURLResponse *)response completionHandler:(void (NS_SWIFT_SENDABLE ^)(NSURLSessionResponseDisposition disposition))completionHandler
{
    if (DataDelegate)
    {
        DataDelegate->URLSessionDataTaskDidReceiveResponse((URLSession*)session, (URLSessionDataTask*)dataTask, (URLResponse*)response, [completionHandler](URLSessionResponseDisposition disposition)
        {
            completionHandler((NSURLSessionResponseDisposition)disposition);
        });
    }
}

- (void)URLSession:(NSURLSession *)session dataTask:(NSURLSessionDataTask *)dataTask didBecomeDownloadTask:(NSURLSessionDownloadTask *)downloadTask
{
    if (DataDelegate)
    {
        DataDelegate->URLSessionDataTaskDidBecomeDownloadTask((URLSession*)session, (URLSessionDataTask*)dataTask, (URLSessionDownloadTask*)downloadTask);
    }
}

- (void)URLSession:(NSURLSession *)session dataTask:(NSURLSessionDataTask *)dataTask didBecomeStreamTask:(NSURLSessionStreamTask *)streamTask
{
    if (DataDelegate)
    {
        DataDelegate->URLSessionDataTaskDidBecomeStreamTask((URLSession*)session, (URLSessionDataTask*)dataTask, (URLSessionStreamTask*)streamTask);
    }
}

- (void)URLSession:(NSURLSession *)session dataTask:(NSURLSessionDataTask *)dataTask didReceiveData:(NSData *)data
{
    if (DataDelegate)
    {
        DataDelegate->URLSessionDataTaskDidReceiveData((URLSession*)session, (URLSessionDataTask*)dataTask, (Data*)data);
    }
}

- (void)URLSession:(NSURLSession *)session dataTask:(NSURLSessionDataTask *)dataTask willCacheResponse:(NSCachedURLResponse *)proposedResponse completionHandler:(void (NS_SWIFT_SENDABLE ^)(NSCachedURLResponse * _Nullable cachedResponse))completionHandler
{
    if (DataDelegate)
    {
        DataDelegate->URLSessionDataTaskWillCacheResponse((URLSession*)session, (URLSessionDataTask*)dataTask, (CachedURLResponse*)proposedResponse, [completionHandler](CachedURLResponse* cachedResponse)
        {
            completionHandler((NSCachedURLResponse *)cachedResponse);
        });
    }
}

@end