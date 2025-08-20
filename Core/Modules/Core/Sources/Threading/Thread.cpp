#include "Thread.h"

#include "Defines/Preprocessors.h"

#include "ScopeLock.h"

#include COMPILE_PLATFORM_HEADER(Thread.h)

bool CThread::IsRunning()
{
    SScopeLock Lock(IsRunningSection);
    return bIsRunning;
}

void CThread::Start(const TFunction<void (const CThreadWeakPtr &)>&)
{
    SScopeLock Lock(IsRunningSection);
    bIsRunning = true;
}

void CThread::Exit()
{
    SScopeLock Lock(IsRunningSection);
    bIsRunning = false;
}

CThreadPtr CThread::Create()
{
    return MakeShared<CPlatformThread>();
}