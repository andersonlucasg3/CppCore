#pragma once

#include "HttpRequest.h"

#include "Object/ClassMacros.h"

#include "URLSession/NSURLSessionDataDelegate.h"

DECLARE_CLASS_HEADER(MacHttpRequest);

using namespace NS;

class CMacHttpRequest : public CHttpRequest, public URLSessionDataDelegate
{
    using Super = CHttpRequest;

protected:
    HTTP_API void URLSessionDidBecomeInvalidWithError(URLSession* Session, Error* Error) override;
    HTTP_API void URLSessionTaskDidCompleteWithError(URLSession* session, URLSessionTask* task, Error* error) override;
    HTTP_API void URLSessionDataTaskDidReceiveData(URLSession* session, URLSessionDataTask* dataTask, Data* data) override;
    HTTP_API void URLSessionDataTaskDidReceiveResponse(URLSession* session, URLSessionDataTask* dataTask, URLResponse* response, const URLSessionDataTaskDidReceiveResponseCompletionHandler& completionHandler) override;

public:
    HTTP_API CMacHttpRequest() = default;
    HTTP_API ~CMacHttpRequest() override = default;

    HTTP_API void Process() override;
};

typedef CMacHttpRequest CPlatformHttpRequest;