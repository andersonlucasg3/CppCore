#pragma once

#include "Templates/Queue.h"

#include "SmartPointer/SharedFromThis.h"

#include "Threading/Thread.h"
#include "Threading/CriticalSection.h"

#include "HttpRequest.h"

class CHttpRequestManager : public TSharedFromThis<CHttpRequestManager>
{
    CThreadPtr _httpThread;

    SCriticalSection _pendingRequestsCS;
    TQueue<CHttpRequestPtr> _pendingRequests;

    void ThreadWorker(const CThreadWeakPtr& Thread);

public:
    HTTP_API CHttpRequestManager();
    HTTP_API virtual ~CHttpRequestManager();

    HTTP_API void StartRequestWorker();
    HTTP_API void StopRequestWorker();

    HTTP_API void AddRequest(const CHttpRequestPtr& InRequest);
};

extern CHttpRequestManager& GHttpRequestManager;