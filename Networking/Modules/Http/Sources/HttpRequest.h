#pragma once

#include "String/String.h"
#include "Templates/Map.h"
 
#include "Object/ClassMacros.h"

DECLARE_CLASS_HEADER(HttpRequest);

class CHttpRequest
{
    CString _endpoint;
    TMap<CString, CString> _headers;

public:
    HTTP_API CHttpRequest(const CString& InEndpoint);
    HTTP_API virtual ~CHttpRequest() = default;

    HTTP_API void SetHeader(const CString& InKey, const CString& InValue);

    HTTP_API const CString& Endpoint() const;
    HTTP_API const TMap<CString, CString>& Headers() const;
};