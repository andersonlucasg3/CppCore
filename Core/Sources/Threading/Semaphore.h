#pragma once

#include <mutex>

struct SSemaphore
{
    CORE_API SSemaphore(int32_t Count = 0);
    CORE_API ~SSemaphore();

    CORE_API void NotifyOne();
    CORE_API void Wait();

private:
    std::mutex Mutex;
    std::condition_variable Condition;
    int32_t Count;
};