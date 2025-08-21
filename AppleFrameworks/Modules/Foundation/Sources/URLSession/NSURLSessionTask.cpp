#include "NSURLSessionTask.h"

#include "NSURLSessionTaskDelegate.h"

#include "NSPrivate.h"

namespace NS
{
    void URLSessionTask::cancel()
    {
        Object::sendMessage<void>(this, _NS_PRIVATE_SEL(cancel));
    }

    void URLSessionTask::resume()
    {
        Object::sendMessage<void>(this, _NS_PRIVATE_SEL(resume));
    }

    void URLSessionTask::suspend()
    {
        Object::sendMessage<void>(this, _NS_PRIVATE_SEL(suspend));
    }
}