#include "NSURLSessionTaskDelegateImpl.h"

#include "URL/NSURLAuthenticationChallenge.h"
#include "URLSession/NSURLSession.h"
#include "URLSession/NSURLSessionTask.h"

@implementation NSURLSessionTaskDelegateImpl

- (instancetype)initWithDelegate:(URLSessionTaskDelegate*) InDelegate 
{
    if (self = [super initWithDelegate:InDelegate])
    {
        TaskDelegate = InDelegate;
    }

    return self;
}

- (void)dealloc
{
    TaskDelegate = nullptr;
    
    [super dealloc];
}

- (void)URLSession:(NSURLSession *)session didCreateTask:(NSURLSessionTask *)task
{
    if (TaskDelegate)
    {
        TaskDelegate->URLSessionDidCreateTask((URLSession*)session, (URLSessionTask*)task);
    }
}

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task willBeginDelayedRequest:(NSURLRequest *)request completionHandler:(void (^)(NSURLSessionDelayedRequestDisposition disposition, NSURLRequest* newRequest))completionHandler
{
    if (TaskDelegate)
    {
        TaskDelegate->URLSessionTaskWillBeginDelayedRequest((URLSession*)session, (URLSessionTask*)task, (URLRequest*)request, [completionHandler](URLSessionDelayedRequestDisposition disposition, URLRequest* newRequest)
        {
            completionHandler((NSURLSessionDelayedRequestDisposition)disposition, (NSURLRequest*)newRequest);
        });
    }
}

- (void)URLSession:(NSURLSession *)session taskIsWaitingForConnectivity:(NSURLSessionTask *)task
{
    if (TaskDelegate)
    {
        TaskDelegate->URLSessionTaskIsWaitingForConnectivity((URLSession*)session, (URLSessionTask*)task);
    }
}

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task willPerformHTTPRedirection:(NSHTTPURLResponse *)response newRequest:(NSURLRequest *)request completionHandler:(void (NS_SWIFT_SENDABLE ^)(NSURLRequest * _Nullable))completionHandler
{
    if (TaskDelegate)
    {
        TaskDelegate->URLSessionTaskWillPerformHTTPRedirection((URLSession*)session, (URLSessionTask*)task, (HTTPURLResponse*)response, (URLRequest*)request, [completionHandler](URLRequest* newRequest)
        {
            completionHandler((NSURLRequest*)newRequest);
        });
    }
}

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task didReceiveChallenge:(NSURLAuthenticationChallenge *)challenge completionHandler:(void (NS_SWIFT_SENDABLE ^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential * _Nullable credential))completionHandler
{
    if (TaskDelegate)
    {
        TaskDelegate->URLSessionTaskDidReceiveChallenge((URLSession*)session, (URLSessionTask*)task, (URLAuthenticationChallenge*)challenge, [completionHandler](URLSessionAuthChallengeDisposition disposition, URLCredential* credential)
        {
            completionHandler((NSURLSessionAuthChallengeDisposition)disposition, (NSURLCredential*)credential);
        });
    }
}

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task needNewBodyStream:(void (NS_SWIFT_SENDABLE ^)(NSInputStream * _Nullable bodyStream))completionHandler
{
    if (TaskDelegate)
    {
        TaskDelegate->URLSessionTaskNeedNewBodyStream((URLSession*)session, (URLSessionTask*)task, [completionHandler](InputStream* bodyStream)
        {
            completionHandler((NSInputStream*)bodyStream);
        });
    }
}

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task needNewBodyStreamFromOffset:(int64_t)offset completionHandler:(void (NS_SWIFT_SENDABLE ^)(NSInputStream * _Nullable bodyStream))completionHandler
{
    if (TaskDelegate)
    {
        TaskDelegate->URLSessionTaskNeedNewBodyStreamFromOffset((URLSession*)session, (URLSessionTask*)task, offset, [completionHandler](InputStream* bodyStream)
        {
            completionHandler((NSInputStream*)bodyStream);
        });
    }
}

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task didSendBodyData:(int64_t)bytesSent totalBytesSent:(int64_t)totalBytesSent totalBytesExpectedToSend:(int64_t)totalBytesExpectedToSend
{
    if (TaskDelegate)
    {
        TaskDelegate->URLSessionTaskDidSendBodyData((URLSession*)session, (URLSessionTask*)task, bytesSent, totalBytesSent, totalBytesExpectedToSend);
    }
}

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task didReceiveInformationalResponse:(NSHTTPURLResponse *)response
{
    if (TaskDelegate)
    {
        TaskDelegate->URLSessionTaskDidReceiveInformationalResponse((URLSession*)session, (URLSessionTask*)task, (HTTPURLResponse*)response);
    }
}

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task didFinishCollectingMetrics:(NSURLSessionTaskMetrics *)metrics
{
    if (TaskDelegate)
    {
        TaskDelegate->URLSessionTaskDidFinishCollectingMetrics((URLSession*)session, (URLSessionTask*)task, (URLSessionTaskMetrics*)metrics);
    }
}

- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task didCompleteWithError:(nullable NSError *)error
{
    if (TaskDelegate)
    {
        TaskDelegate->URLSessionTaskDidCompleteWithError((URLSession*)session, (URLSessionTask*)task, (Error*)error);
    }
}

@end

namespace NS
{
    URLSessionTaskDelegate* URLSessionTask::delegate()
    {
        NSURLSessionTask* ObjcTask = (NSURLSessionTask*)this;

        NSURLSessionTaskDelegateImpl* ObjcDelegate = ObjcTask.delegate;

        return ObjcDelegate->TaskDelegate;
    }

    void URLSessionTask::setDelegate(URLSessionTaskDelegate* InDelegate)
    {
        NSURLSessionTaskDelegateImpl* ObjcDelegate = [[[NSURLSessionTaskDelegateImpl alloc] initWithDelegate:InDelegate] autorelease];

        NSURLSessionTask* ObjcTask = (NSURLSessionTask*)this;

        ObjcTask.delegate = ObjcDelegate;
    }
}