#include "NSURLSessionDelegateImpl.h"

#include "NSURLAuthenticationChallenge.h"

using namespace NS;

@implementation NSURLSessionDelegateImpl
{
    std::shared_ptr<URLSessionDelegate> _cppDelegate;
}

- (instancetype)initWithDelegate:(const std::shared_ptr<URLSessionDelegate>&) InDelegate
{
    if (self = [super init])
    {
        _cppDelegate = InDelegate;
    }

    return self;
}

- (void) URLSession:(NSURLSession *) session didBecomeInvalidWithError:(NSError *) error
{
    if (_cppDelegate)
    {
        _cppDelegate->URLSessionDidBecomeInvalidWithError((URLSession*)session, (Error*)error);
    }
}

- (void) URLSessionDidFinishEventsForBackgroundURLSession:(NSURLSession *) session
{
    if (_cppDelegate)
    {
        _cppDelegate->URLSessionDidFinishEventsForBackgroundURLSession((URLSession*)session);
    }
}

- (void) URLSession:(NSURLSession *) session didReceiveChallenge:(NSURLAuthenticationChallenge *) challenge completionHandler:(void (^)(NSURLSessionAuthChallengeDisposition disposition, NSURLCredential * credential)) completionHandler
{
    if (_cppDelegate)
    {
        _cppDelegate->URLSessionDidReceiveChallenge((URLSession*)session, (URLAuthenticationChallenge*)challenge, [completionHandler](URLSessionAuthChallengeDisposition disposition, URLCredential* credential)
        {
            completionHandler((NSURLSessionAuthChallengeDisposition)disposition, (NSURLCredential*)credential);
        });
    }
}

@end