#pragma once

#include "HttpRequest.h"

class CMacHttpRequest : public CHttpRequest
{
    using Super = CHttpRequest;

public:
    HTTP_API CMacHttpRequest(const CString& InEndpoint);
    HTTP_API ~CMacHttpRequest() override = default;

    HTTP_API void Process() override;
};