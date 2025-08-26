#include "MacHttpRequestManager.h"

#include "HttpRequest.h"
#include "Mac/MacHttpRequest.h"

#include "String/Apple/AppleStringConvertion.h"

#include "NSSharedPtr.hpp"

#include "NSData.h"

#include "NSError.h"
#include "URLSession/NSURLSession.h"
#include "URLSession/NSURLSessionDataTask.h"
#include "URLSession/NSURLSessionConfiguration.h"

CMacHttpRequestManager GMacHttpRequestManager;

void CMacHttpRequestManager::URLSessionDidBecomeInvalidWithError(URLSession *session, Error *error)
{
    CHttpRequestError RequestError;

    RequestError.Error = CHttpRequestError::PlatformError;
    RequestError.ErrorCode = error->code();
    RequestError.Message = NSStringToCString(error->debugDescription());

    // SendErrorCallback(RequestError);
}

void CMacHttpRequestManager::URLSessionTaskDidCompleteWithError(URLSession* session, URLSessionTask* task, Error* error)
{
    if (CMacHttpRequestPtr* RequestPtr = _requestsMap.Find(task->hash()))
    {
        CMacHttpRequestPtr Request = *RequestPtr;

        if (error != nullptr)
        {
            CHttpRequestError RequestError;
            RequestError.Error = CHttpRequestError::PlatformError;
            RequestError.ErrorCode = error->code();
            RequestError.Message = NSStringToCString(error->debugDescription());

            Request->SendErrorCallback(RequestError);

            return;
        }

        Request->_response.FinishResponse();

        Request->SendSuccessCallback();
    }
}

void CMacHttpRequestManager::URLSessionDataTaskDidReceiveData(URLSession* session, URLSessionDataTask* dataTask, Data* data)
{
    if (CMacHttpRequestPtr* RequestPtr = _requestsMap.Find(dataTask->hash()))
    {
        CMacHttpRequestPtr Request = *RequestPtr;

        Request->_response.AppendResponse(TArray<UInt8>(reinterpret_cast<UInt8*>(data->mutableBytes()), data->length()));
    }
}

void CMacHttpRequestManager::URLSessionDataTaskDidReceiveResponse(URLSession* session, URLSessionDataTask* dataTask, URLResponse* response, const URLSessionDataTaskDidReceiveResponseCompletionHandler& completionHandler)
{
    
    completionHandler(URLSessionResponseAllow);
}

void CMacHttpRequestManager::URLSessionTaskDidReceiveInformationalResponse(URLSession* session, URLSessionTask* task, HTTPURLResponse* response)
{
    
}

CMacHttpRequestManager::CMacHttpRequestManager()
:   Super()
{
    _urlSession = TransferPtr(URLSession::session(URLSessionConfiguration::defaultSessionConfiguration()));
    // TODO: _urlSession->setDelegate() here
}

CHttpRequestPtr CMacHttpRequestManager::CreateRequest()
{
    CMacHttpRequestPtr MacRequest = MakeShared<CMacHttpRequest>();
    MacRequest->SetURLSession(_urlSession);
    return MacRequest;
}

void CMacHttpRequestManager::AddRequest(URLSessionTask* InTask, const CMacHttpRequestPtr& InRequest)
{
    _requestsMap.Add(InTask->hash(), InRequest);
}