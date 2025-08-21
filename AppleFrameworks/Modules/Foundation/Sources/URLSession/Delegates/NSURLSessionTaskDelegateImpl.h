#pragma once

#include "NSURLSessionDelegateImpl.h"

#include "URLSession/NSURLSessionTaskDelegate.h"

using namespace NS;

@interface NSURLSessionTaskDelegateImpl : NSURLSessionDelegateImpl <NSURLSessionTaskDelegate>
{
    @public URLSessionTaskDelegate* TaskDelegate;
}

- (instancetype)initWithDelegate:(URLSessionTaskDelegate*) InDelegate;

- (void)URLSession:(NSURLSession *)session didCreateTask:(NSURLSessionTask *)task;
- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task willBeginDelayedRequest:(NSURLRequest *)request completionHandler:(void (^)(NSURLSessionDelayedRequestDisposition disposition, NSURLRequest* newRequest))completionHandler;
- (void)URLSession:(NSURLSession *)session taskIsWaitingForConnectivity:(NSURLSessionTask *)task;
- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task willPerformHTTPRedirection:(NSHTTPURLResponse *)response newRequest:(NSURLRequest *)request completionHandler:(void (NS_SWIFT_SENDABLE ^)(NSURLRequest * _Nullable))completionHandler;
- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task didReceiveChallenge:(NSURLAuthenticationChallenge *)challenge completionHandler:(void (NS_SWIFT_SENDABLE ^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential * _Nullable credential))completionHandler;
- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task needNewBodyStream:(void (NS_SWIFT_SENDABLE ^)(NSInputStream * _Nullable bodyStream))completionHandler;
- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task needNewBodyStreamFromOffset:(int64_t)offset completionHandler:(void (NS_SWIFT_SENDABLE ^)(NSInputStream * _Nullable bodyStream))completionHandler;
- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task didSendBodyData:(int64_t)bytesSent totalBytesSent:(int64_t)totalBytesSent totalBytesExpectedToSend:(int64_t)totalBytesExpectedToSend;
- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task didReceiveInformationalResponse:(NSHTTPURLResponse *)response;
- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task didFinishCollectingMetrics:(NSURLSessionTaskMetrics *)metrics;
- (void)URLSession:(NSURLSession *)session task:(NSURLSessionTask *)task didCompleteWithError:(nullable NSError *)error;

@end