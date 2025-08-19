#pragma once

#include "NSURLSessionDelegate.h"

#include <Foundation/Foundation.h>

#include <__memory/shared_ptr.h>

@interface NSURLSessionDelegateObjc : NSObject<NSURLSessionDelegate>

- (instancetype)initWithDelegate:(const std::shared_ptr<NS::URLSessionDelegate>&) InDelegate;

- (void) URLSession:(NSURLSession *) session didBecomeInvalidWithError:(NSError *) error;
- (void) URLSessionDidFinishEventsForBackgroundURLSession:(NSURLSession *) session;
- (void) URLSession:(NSURLSession *) session didReceiveChallenge:(NSURLAuthenticationChallenge *) challenge completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential * credential)) completionHandler;

@end