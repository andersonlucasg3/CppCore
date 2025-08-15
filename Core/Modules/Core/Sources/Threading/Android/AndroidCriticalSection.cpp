#include "AndroidCriticalSection.h"

#include <pthread.h>

// TODO: handle result of each of the pthread functions bellow

SAndroidCriticalSection::SAndroidCriticalSection()
{
    pthread_mutex_init(&_mutex, nullptr);
}

SAndroidCriticalSection::~SAndroidCriticalSection()
{
    pthread_mutex_destroy(&_mutex);
}

void SAndroidCriticalSection::Lock()
{
    pthread_mutex_lock(&_mutex);
}

bool SAndroidCriticalSection::TryLock()
{
    return pthread_mutex_trylock(&_mutex) == 0;
}

void SAndroidCriticalSection::Unlock()
{
    pthread_mutex_unlock(&_mutex);
}
