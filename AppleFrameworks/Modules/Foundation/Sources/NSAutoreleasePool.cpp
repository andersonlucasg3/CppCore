#include "NSAutoreleasePool.h"

namespace NS 
{
    NS::AutoreleasePool* NS::AutoreleasePool::alloc()
    {
        return NS::Object::alloc<AutoreleasePool>(_NS_PRIVATE_CLS(NSAutoreleasePool));
    }

    NS::AutoreleasePool* NS::AutoreleasePool::init()
    {
        return NS::Object::init<AutoreleasePool>();
    }

    void NS::AutoreleasePool::drain()
    {
        Object::sendMessage<void>(this, _NS_PRIVATE_SEL(drain));
    }

    void NS::AutoreleasePool::addObject(Object* pObject)
    {
        Object::sendMessage<void>(this, _NS_PRIVATE_SEL(addObject_), pObject);
    }

    void NS::AutoreleasePool::showPools()
    {
        Object::sendMessage<void>(_NS_PRIVATE_CLS(NSAutoreleasePool), _NS_PRIVATE_SEL(showPools));
    }
}