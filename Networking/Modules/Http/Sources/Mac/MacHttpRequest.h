#pragma once

#include "HttpRequest.h"

#include "Object/ClassMacros.h"

#include "URLSession/NSURLSessionDelegate.h"

DECLARE_CLASS_HEADER(MacHttpRequest);

using namespace NS;

class CMacHttpRequest : public CHttpRequest, public URLSessionDataDelegate
{
    using Super = CHttpRequest;

protected:
    HTTP_API void URLSessionDidBecomeInvalidWithError(URLSession* Session, Error* Error) override;

public:
    HTTP_API CMacHttpRequest() = default;
    HTTP_API ~CMacHttpRequest() override = default;

    HTTP_API void Process() override;
};

typedef CMacHttpRequest CPlatformHttpRequest;