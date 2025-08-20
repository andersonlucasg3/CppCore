#include "NSObjcURLSessionDataDelegate.h"

#include "NSURLSessionDataDelegate.h"

@implementation NSObjcURLSessionDataDelegate
{
    std::shared_ptr<NS::URLSessionDataDelegate> _cppDelegate;
}

- (instancetype)initWithDelegate:(const std::shared_ptr<URLSessionDataDelegate> &)InDelegate 
{
    if (self = [super initWithDelegate:InDelegate])
    {
        _cppDelegate = InDelegate;
    }

    return self;
}

- (void)URLSession:(NSURLSession *)session dataTask:(NSURLSessionDataTask *)dataTask didReceiveResponse:(NSURLResponse *)response completionHandler:(void (^)(NSURLSessionResponseDisposition))completionHandler 
{

}

@end