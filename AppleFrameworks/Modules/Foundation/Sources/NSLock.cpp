#include "NSLock.h"

namespace NS 
{
    Condition* Condition::alloc()
    {
        return Object::alloc<Condition>(_NS_PRIVATE_CLS(NSCondition));
    }

    Condition* Condition::init()
    {
        return Object::init<Condition>();
    }

    void Condition::wait()
    {
        Object::sendMessage<void>(this, _NS_PRIVATE_SEL(wait));
    }

    bool Condition::waitUntilDate(Date* pLimit)
    {
        return Object::sendMessage<bool>(this, _NS_PRIVATE_SEL(waitUntilDate_), pLimit);
    }

    void Condition::signal()
    {
        Object::sendMessage<void>(this, _NS_PRIVATE_SEL(signal));
    }

    void Condition::broadcast()
    {
        Object::sendMessage<void>(this, _NS_PRIVATE_SEL(broadcast));
    }
}