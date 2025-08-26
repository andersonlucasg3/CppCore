#include "NSURLSessionConfiguration.h"

#include "NSPrivate.h"

#if __OBJC__
#include <Foundation/NSURLSession.h>
#endif // __OBJC__

namespace NS
{
    URLSessionConfiguration* URLSessionConfiguration::defaultSessionConfiguration()
    {
        #if __OBJC__
        return (URLSessionConfiguration*)[NSURLSessionConfiguration defaultSessionConfiguration];
        #endif // __OBJC__
        return nullptr;
    }

    URLSessionConfiguration* URLSessionConfiguration::ephemeralSessionConfiguration()
    {
        #if __OBJC__
        return (URLSessionConfiguration*)[NSURLSessionConfiguration ephemeralSessionConfiguration];
        #endif // __OBJC__
        return nullptr;
    }
}