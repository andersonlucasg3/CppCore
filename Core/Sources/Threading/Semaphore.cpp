#include "Semaphore.h"

#include "ScopeLock.h"

SSemaphore::SSemaphore(int32_t Count) :
    Count(Count)
{
    //
}

SSemaphore::~SSemaphore()
{
    //
}

void SSemaphore::NotifyOne()
{
    std::unique_lock<std::mutex> Lock(Mutex);
    ++Count;
    Condition.notify_one();
}

void SSemaphore::Wait()
{
    std::unique_lock<std::mutex> Lock(Mutex);
    Condition.wait(Lock, [this] { return Count > 0; });
    --Count;
}