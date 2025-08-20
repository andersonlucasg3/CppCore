#pragma once

#include "NSObjcURLSesssionTaskDelegate.h"

#include "NSURLSessionDataDelegate.h"

using namespace NS;

@interface NSObjcURLSessionDataDelegate : NSObjcURLSessionTaskDelegate

- (instancetype)initWithDelegate:(const std::shared_ptr<URLSessionDataDelegate>&)InDelegate;

- (void)URLSession:(NSURLSession *)session dataTask:(NSURLSessionDataTask *)dataTask didReceiveResponse:(NSURLResponse *)response completionHandler:(void (NS_SWIFT_SENDABLE ^)(NSURLSessionResponseDisposition disposition))completionHandler;
- (void)URLSession:(NSURLSession *)session dataTask:(NSURLSessionDataTask *)dataTask didBecomeDownloadTask:(NSURLSessionDownloadTask *)downloadTask;
- (void)URLSession:(NSURLSession *)session dataTask:(NSURLSessionDataTask *)dataTask didBecomeStreamTask:(NSURLSessionStreamTask *)streamTask;
- (void)URLSession:(NSURLSession *)session dataTask:(NSURLSessionDataTask *)dataTask didReceiveData:(NSData *)data;
- (void)URLSession:(NSURLSession *)session dataTask:(NSURLSessionDataTask *)dataTask willCacheResponse:(NSCachedURLResponse *)proposedResponse completionHandler:(void (NS_SWIFT_SENDABLE ^)(NSCachedURLResponse * _Nullable cachedResponse))completionHandler;

@end