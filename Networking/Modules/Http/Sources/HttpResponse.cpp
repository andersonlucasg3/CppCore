#include "HttpResponse.h"

void CHttpResponse::SetStatus(Int64 InStatus)
{
    _status = InStatus;
}

void CHttpResponse::AppendResponse(const TArray<UInt8>& InResponseData)
{
    _responseData.Add(InResponseData);
}

void CHttpResponse::FinishResponse()
{
    _responseString = CString(_responseData.GetData<const char>(), _responseData.Num());
}

Int32 CHttpResponse::Status() const
{
    return _status;
}

CString CHttpResponse::ResponseString() const
{
    return _responseString;
}

const TArray<UInt8>& CHttpResponse::ResponseData() const
{
    return _responseData;
}

