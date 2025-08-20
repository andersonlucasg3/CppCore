#pragma once

#include "URLSession/NSURLSessionDelegate.h"

#include <Foundation/Foundation.h>

#include <__memory/shared_ptr.h>

using namespace NS;

@interface NSURLSessionDelegateImpl : NSObject<NSURLSessionDelegate>

- (instancetype)initWithDelegate:(const std::shared_ptr<URLSessionDelegate>&) InDelegate;

- (void) URLSession:(NSURLSession *) session didBecomeInvalidWithError:(NSError *) error;
- (void) URLSessionDidFinishEventsForBackgroundURLSession:(NSURLSession *) session;
- (void) URLSession:(NSURLSession *) session didReceiveChallenge:(NSURLAuthenticationChallenge *) challenge completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential * credential)) completionHandler;

@end