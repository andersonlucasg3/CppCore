#pragma once

#include "Defines/Types.h"

#include "String/String.h"

class CHttpResponse
{
    Int32 _status;
    CString _responseString;
    TArray<UInt8> _responseData;

public:
    HTTP_API CHttpResponse() = default;
    HTTP_API virtual ~CHttpResponse() = default;

    HTTP_API void SetStatus(Int64 InStatus);
    HTTP_API void AppendResponse(const TArray<UInt8>& InResponseData);
    HTTP_API void FinishResponse();

    HTTP_API Int32 Status() const;
    HTTP_API CString ResponseString() const;
    HTTP_API const TArray<UInt8>& ResponseData() const;
};