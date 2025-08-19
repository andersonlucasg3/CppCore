#include "HttpRequestManager.h"

#include "HttpRequest.h"
#include "Threading/ScopeLock.h"
#include "Threading/Thread.h"

void CHttpRequestManager::ThreadWorker(const CThreadWeakPtr& Thread)
{
    SScopeLock ScopeLock(_pendingRequestsCS);

    if (_pendingRequests.IsEmpty())
    {
        // no need to keep the thread running if there are no requests to process
        Thread->Exit();

        return;
    }

    CHttpRequestPtr Request;
    while (_pendingRequests.Dequeue(Request))
    {
        Request->Process();
    }
}

CHttpRequestManager::CHttpRequestManager()
:   _httpThread(CThread::Create())
{
    //
}

CHttpRequestManager::~CHttpRequestManager()
{
    StopRequestWorker();
}

void CHttpRequestManager::StartRequestWorker()
{
    if (_httpThread->IsRunning()) return;

    _httpThread->Start([WeakThis = AsWeak()](const CThreadWeakPtr& Thread)
    {
        if (!WeakThis)
        {
            Thread->Exit();

            return;
        }

        WeakThis->ThreadWorker(Thread);
    });
}

void CHttpRequestManager::StopRequestWorker()
{
    if (!_httpThread->IsRunning()) return;

    _httpThread->Exit();
    _httpThread->Join();
}

void CHttpRequestManager::AddRequest(const CHttpRequestPtr& InRequest)
{
    SScopeLock ScopeLock(_pendingRequestsCS);
    
    _pendingRequests.Enqueue(InRequest);

    StartRequestWorker();
}