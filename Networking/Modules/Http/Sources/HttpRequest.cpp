#include "HttpRequest.h"

CHttpRequest::CHttpRequest(const CString& InEndpoint)
:   _endpoint(InEndpoint)
{
    //
}

void CHttpRequest::SetHeader(const CString& InKey, const CString& InValue)
{
    _headers.Set(InKey, InValue);
}

const CString& CHttpRequest::Endpoint() const
{
    return _endpoint;
}

const TMap<CString, CString>& CHttpRequest::Headers() const
{
    return _headers;
}