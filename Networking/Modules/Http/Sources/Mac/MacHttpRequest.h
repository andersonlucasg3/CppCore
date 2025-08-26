#pragma once

#include "HttpRequest.h"

#include "Object/ClassMacros.h"

#include "NSSharedPtr.hpp"

#include "URLSession/NSURLSessionDataDelegate.h"

DECLARE_CLASS_HEADER(MacHttpRequest);

using namespace NS;

class CMacHttpRequest : public CHttpRequest, public URLSessionDataDelegate
{
    using Super = CHttpRequest;

    SharedPtr<URLSession> _urlSession;

public:
    HTTP_API CMacHttpRequest() = default;
    HTTP_API ~CMacHttpRequest() override = default;

    HTTP_API void SetURLSession(const SharedPtr<class URLSession> InURLSession);

    HTTP_API void Process() override;

    friend class CMacHttpRequestManager;
};

typedef CMacHttpRequest CPlatformHttpRequest;