#include "HttpRequestError.h"

#include "Defines/Asserts.h"

const char* ToString(CHttpRequestError::EHttpRequestError InError)
{
    switch (InError)
    {
        case CHttpRequestError::PlatformApiError: return "EHttpRequestError::PlatformApiError";
        case CHttpRequestError::PlatformError: return "EHttpRequestError::PlatformError";
        case CHttpRequestError::ConnectionError: return "EHttpRequestError::ConnectionError";
        case CHttpRequestError::NoResponseError: return "EHttpRequestError::NoResponseError";
        default:
            assertm(false, "Implement new cases");
            return "";
    }
}