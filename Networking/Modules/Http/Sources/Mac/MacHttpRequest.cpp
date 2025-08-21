#include "MacHttpRequest.h"

#include "HttpRequestError.h"

#include "NSData.h"
#include "String/Apple/AppleStringConvertion.h"

#include "NSURL.h"
#include "NSError.h"
#include "Templates/Array.h"
#include "URLSession/NSURLSession.h"
#include "URLSession/NSURLSessionDataTask.h"

using namespace NS;

void CMacHttpRequest::Process()
{
    URL* Url = URL::url(CStringToNSString(Endpoint()));

    URLSession* Session = URLSession::sharedSession();

    URLSessionDataTask* DataTask = Session->dataTask(Url);

    DataTask->setDelegate(this);

    DataTask->resume();
}

void CMacHttpRequest::URLSessionDidBecomeInvalidWithError(URLSession *, Error *Error)
{
    CHttpRequestError RequestError;

    RequestError.Error = CHttpRequestError::PlatformError;
    RequestError.ErrorCode = Error->code();
    RequestError.Message = NSStringToCString(Error->debugDescription());

    SendErrorCallback(RequestError);
}

void CMacHttpRequest::URLSessionTaskDidCompleteWithError(URLSession* session, URLSessionTask* task, Error* error)
{
    if (error != nullptr)
    {
        CHttpRequestError RequestError;
        RequestError.Error = CHttpRequestError::PlatformError;
        RequestError.ErrorCode = error->code();
        RequestError.Message = NSStringToCString(error->debugDescription());

        SendErrorCallback(RequestError);

        return;
    }

    _response.FinishResponse();

    SendSuccessCallback();
}

void CMacHttpRequest::URLSessionDataTaskDidReceiveData(URLSession* session, URLSessionDataTask* dataTask, Data* data)
{
    _response.AppendResponse(TArray<UInt8>(reinterpret_cast<UInt8*>(data->mutableBytes()), data->length()));
}

void CMacHttpRequest::URLSessionDataTaskDidReceiveResponse(URLSession* session, URLSessionDataTask* dataTask, URLResponse* response, const URLSessionDataTaskDidReceiveResponseCompletionHandler& completionHandler)
{
    
    completionHandler(URLSessionResponseAllow);
}

void CMacHttpRequest::URLSessionTaskDidReceiveInformationalResponse(URLSession* session, URLSessionTask* task, HTTPURLResponse* response)
{

}