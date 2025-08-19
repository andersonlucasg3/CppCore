#include "NSURLSession.h"

#include "NSObject.hpp"
#include "NSPrivate.h"

#include "NSURLSessionDelegateObjc.h"

namespace NS 
{
    URLSession* URLSession::sharedSession()
    {
        return Object::sendMessage<URLSession*>(_NS_PRIVATE_CLS(NSURLSession), _NS_PRIVATE_SEL(sharedSession));
    }

    void URLSession::setDelegate(const std::shared_ptr<URLSessionDelegate>& InDelegate)
    {
        NSURLSessionDelegateObjc* ObjcDelegate = [[NSURLSessionDelegateObjc alloc] initWithDelegate:InDelegate];

        return Object::sendMessage<void>(_NS_PRIVATE_CLS(NSURLSession), _NS_PRIVATE_SEL(setDelegate_), ObjcDelegate);
    }
}