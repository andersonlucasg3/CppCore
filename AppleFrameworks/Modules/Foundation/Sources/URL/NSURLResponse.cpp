#include "NSURLResponse.h"

#include "NSPrivate.h"

#include "NSURL.h"

namespace NS
{
    URLResponse* URLResponse::alloc()
    {
        return Object::alloc<URLResponse>(_NS_PRIVATE_CLS(NSURLResponse));
    }

    URLResponse* URLResponse::init(URL* URL, String* MIMEType, Integer expectedContentLength, String* textEncodingName)
    {
        
    }
}