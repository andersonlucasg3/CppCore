#include "NSURLSessionTaskDelegateImpl.h"

#include "NSURLAuthenticationChallenge.h"
#include "URLSession/NSURLSession.h"

@implementation NSURLSessionTaskDelegateImpl
{
    std::shared_ptr<URLSessionTaskDelegate> _cppDelegate;
}

- (instancetype)initWithDelegate:(const std::shared_ptr<URLSessionTaskDelegate>&)InDelegate 
{
    if (self = [super initWithDelegate:InDelegate])
    {
        _cppDelegate = InDelegate;
    }

    return self;
}

- (void)URLSession:(NSURLSession *)session didCreateTask:(NSURLSessionTask *)task
{
    if (_cppDelegate)
    {
        _cppDelegate->URLSessionDidCreateTask((URLSession*)session, (URLSessionTask*)task);
    }
}

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task willBeginDelayedRequest:(NSURLRequest *)request completionHandler:(void (^)(NSURLSessionDelayedRequestDisposition disposition, NSURLRequest* newRequest))completionHandler
{
    if (_cppDelegate)
    {
        _cppDelegate->URLSessionTaskWillBeginDelayedRequest((URLSession*)session, (URLSessionTask*)task, (URLRequest*)request, [completionHandler](URLSessionDelayedRequestDisposition disposition, URLRequest* newRequest)
        {
            completionHandler((NSURLSessionDelayedRequestDisposition)disposition, (NSURLRequest*)newRequest);
        });
    }
}

- (void)URLSession:(NSURLSession *)session taskIsWaitingForConnectivity:(NSURLSessionTask *)task
{
    if (_cppDelegate)
    {
        _cppDelegate->URLSessionTaskIsWaitingForConnectivity((URLSession*)session, (URLSessionTask*)task);
    }
}

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task willPerformHTTPRedirection:(NSHTTPURLResponse *)response newRequest:(NSURLRequest *)request completionHandler:(void (NS_SWIFT_SENDABLE ^)(NSURLRequest * _Nullable))completionHandler
{
    if (_cppDelegate)
    {
        _cppDelegate->URLSessionTaskWillPerformHTTPRedirection((URLSession*)session, (URLSessionTask*)task, (URLResponse*)response, (URLRequest*)request, [completionHandler](URLRequest* newRequest)
        {
            completionHandler((NSURLRequest*)newRequest);
        });
    }
}

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task didReceiveChallenge:(NSURLAuthenticationChallenge *)challenge completionHandler:(void (NS_SWIFT_SENDABLE ^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential * _Nullable credential))completionHandler
{
    if (_cppDelegate)
    {
        _cppDelegate->URLSessionTaskDidReceiveChallenge((URLSession*)session, (URLSessionTask*)task, (URLAuthenticationChallenge*)challenge, [completionHandler](URLSessionAuthChallengeDisposition disposition, URLCredential* credential)
        {
            completionHandler((NSURLSessionAuthChallengeDisposition)disposition, (NSURLCredential*)credential);
        });
    }
}

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task needNewBodyStream:(void (NS_SWIFT_SENDABLE ^)(NSInputStream * _Nullable bodyStream))completionHandler
{
    if (_cppDelegate)
    {
        _cppDelegate->URLSessionTaskNeedNewBodyStream((URLSession*)session, (URLSessionTask*)task, [completionHandler](InputStream* bodyStream)
        {
            completionHandler((NSInputStream*)bodyStream);
        });
    }
}

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task needNewBodyStreamFromOffset:(int64_t)offset completionHandler:(void (NS_SWIFT_SENDABLE ^)(NSInputStream * _Nullable bodyStream))completionHandler
{
    if (_cppDelegate)
    {
        _cppDelegate->URLSessionTaskNeedNewBodyStreamFromOffset(session, task, offset, completionHandler);
    }
}

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task didSendBodyData:(int64_t)bytesSent totalBytesSent:(int64_t)totalBytesSent totalBytesExpectedToSend:(int64_t)totalBytesExpectedToSend
{
    if (_cppDelegate)
    {
        _cppDelegate->URLSessionTaskDidSendBodyData(session, task, bytesSent, totalBytesSent, totalBytesExpectedToSend);
    }
}

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task didReceiveInformationalResponse:(NSHTTPURLResponse *)response
{
    if (_cppDelegate)
    {
        _cppDelegate->URLSessionTaskDidReceiveInformationalResponse(session, task, response);
    }
}

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task didFinishCollectingMetrics:(NSURLSessionTaskMetrics *)metrics
{
    if (_cppDelegate)
    {
        _cppDelegate->URLSessionTaskDidFinishCollectingMetrics(session, task, metrics);
    }
}

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task didCompleteWithError:(nullable NSError *)error
{
    if (_cppDelegate)
    {
        _cppDelegate->URLSessionTaskDidCompleteWithError(session, task, error);
    }
}


@end