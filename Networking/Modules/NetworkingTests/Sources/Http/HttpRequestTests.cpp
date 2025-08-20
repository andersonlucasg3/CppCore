#include "HttpRequestTests.h"

#include "Threading/Semaphore.h"

#include "TestSuit.h"

#include "HttpRequest.h"
#include "HttpRequestError.h"
#include "HttpRequestManager.h"

REGISTER_TEST_CLASS(HttpRequestTests);

class CRequestCallbacks : public CHttpRequestCallbacks
{
    SSemaphore* _semaphore;

public:
    CRequestCallbacks(SSemaphore* InSemaphore) : _semaphore(InSemaphore) 
    { 
        //
    }

    ~CRequestCallbacks() override = default;

    void HttpRequestFailedWithError(const CHttpRequestPtr& InRequest, const CHttpRequestError& InError) override
    {
        GLogger.Log("Request Error: {}, Message: {}", ToString(InError.Error), *InError.Message);

        _semaphore->NotifyOne();
    }

    
    void HttpRequestSucceeded(const CHttpRequestPtr& InRequest, const CString& InResponseString) override 
    {
        GLogger.Log("{}", *InResponseString);
        
        _semaphore->NotifyOne();
    }
};

void CHttpRequestTests::TestCase()
{
    GHttpRequestManager.StartRequestWorker();

    SSemaphore RequestSemaphore;

    CHttpRequestPtr Request = CHttpRequest::Create();
    Request->SetEndpoint("www.google.com")
        .SetMethod(EHttpRequestMethod::Get)
        .SetCallbacks(MakeShared<CRequestCallbacks>(&RequestSemaphore));

    GHttpRequestManager.AddRequest(Request);

    RequestSemaphore.Wait();

    GHttpRequestManager.StopRequestWorker();
}