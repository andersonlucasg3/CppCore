#include "NSURLSession.h"

#include "NSObject.hpp"
#include "NSPrivate.h"

namespace NS 
{
    URLSession* URLSession::sharedSession()
    {
        return Object::sendMessage<URLSession*>(_NS_PRIVATE_CLS(NSURLSession), _NS_PRIVATE_SEL(sharedSession));
    }

    URLSessionDataTask* URLSession::dataTask(URL* url)
    {
        return Object::sendMessage<URLSessionDataTask*>(this, _NS_PRIVATE_SEL(dataTaskWithURL_), url);
    }
}