#include "MacHttpRequest.h"
#include "NSURLSession.h"

CMacHttpRequest::CMacHttpRequest(const CString& InEndpoint)
:   Super(InEndpoint)
{
    //
}

void CMacHttpRequest::Process()
{
    NS::URLSession* SharedSession = NS::URLSession::sharedSession();

    
}