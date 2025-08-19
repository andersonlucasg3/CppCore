#include "NSSet.h"

namespace NS 
{
    UInteger Set::count() const
    {
        return Object::sendMessage<UInteger>(this, _NS_PRIVATE_SEL(count));
    }

    Enumerator<Object>* Set::objectEnumerator() const
    {
        return Object::sendMessage<Enumerator<Object>*>(this, _NS_PRIVATE_SEL(objectEnumerator));
    }

    Set* Set::alloc()
    {
        return Object::alloc<Set>(_NS_PRIVATE_CLS(NSSet));
    }

    Set* Set::init()
    {
        return Object::init<Set>();
    }

    Set* Set::init(const Object* const* pObjects, UInteger count)
    {
        return Object::sendMessage<Set*>(this, _NS_PRIVATE_SEL(initWithObjects_count_), pObjects, count);
    }

    Set* Set::init(const class Coder* pCoder)
    {
        return Object::sendMessage<Set*>(this, _NS_PRIVATE_SEL(initWithCoder_), pCoder);
    }
}