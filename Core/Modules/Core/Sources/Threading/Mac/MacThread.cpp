#include "MacThread.h"

#include "Templates/SmartPointer/MakeAndCasts.h"

#include "Threading/Thread.h"

void CMacThread::SetName(const CString &Name)
{
    ThreadName = Name;
}

const CString& CMacThread::Name() const
{
    return ThreadName;
}

void CMacThread::Start(const TFunction<void(const CThreadWeakPtr&)>& ThreadFunc)
{
    Super::Start(ThreadFunc);

    if (!Thread)
    {
        Thread = MakeShared<std::thread>([WeakThread = StaticCastWeakPtr<CMacThread>(AsWeak()), ThreadFunc]
        {
            pthread_setname_np(*WeakThread->ThreadName.SubString(0, 15));
            while(WeakThread->IsRunning())
            {
                @autoreleasepool
                {
                    ThreadFunc(WeakThread);
                }
            }
        });
    }
}

void CMacThread::Join()
{
    if (Thread && Thread->joinable())
    {
        Thread->join();
    }
}

CMacThreadPtr CMacThread::Create()
{
    return MakeShared<CMacThread>();
}