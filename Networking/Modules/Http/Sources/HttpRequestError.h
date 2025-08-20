#pragma once

#include "String/String.h"

struct CHttpRequestError
{
    enum EHttpRequestError
    {
        PlatformApiError,
        PlatformError,
        ConnectionError,
        NoResponseError,

        // if you add new cases update ToString() implementation
    };

    EHttpRequestError Error;
    UInt64 ErrorCode;
    CString Message;

    HTTP_API CHttpRequestError() = default;
    HTTP_API ~CHttpRequestError() = default;
};

HTTP_API const char* ToString(CHttpRequestError::EHttpRequestError InError);