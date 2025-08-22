#include "NSURLResponse.h"

#include "NSPrivate.h"

#include "NSURL.h"

namespace NS
{
    URLResponse* URLResponse::alloc()
    {
        return Object::alloc<URLResponse>(_NS_PRIVATE_CLS(NSURLResponse));
    }

    URLResponse* URLResponse::init(class URL* URL, String* MIMEType, Integer expectedContentLength, String* textEncodingName)
    {
        return Object::sendMessage<URLResponse*>(this, _NS_PRIVATE_SEL(initWithURL_MIMEType_expectedContentLength_textEncodingName_), URL, MIMEType, expectedContentLength, textEncodingName);
    }
}