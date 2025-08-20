#include "MacHttpRequest.h"

#include "HttpRequestError.h"

#include "NSURLSessionDataTask.h"
#include "String/Apple/AppleStringConvertion.h"

#include "NSURL.h"
#include "NSURLSession.h"
#include "NSURLSessionDelegate.h"

using namespace NS;

void CMacHttpRequest::Process()
{
    URL* Url = URL::url(CStringToNSString(Endpoint()));

    URLSession* Session = URLSession::sharedSession();

    URLSessionDataTask* DataTask = Session->dataTask(Url);

    DataTask->
}

void CMacHttpRequest::URLSessionDidBecomeInvalidWithError(URLSession *, Error *Error)
{
    CHttpRequestError RequestError;

    RequestError.Error = CHttpRequestError::PlatformError;
    RequestError.ErrorCode = Error->code();
    RequestError.Message = NSStringToCString(Error->debugDescription());

    SendErrorCallback(RequestError);
}