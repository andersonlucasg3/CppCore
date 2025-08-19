#include "NSArray.h"
#include "NSPrivate.h"

namespace NS
{
    Array* Array::array()
    {
        return Object::sendMessage<Array*>(_NS_PRIVATE_CLS(NSArray), _NS_PRIVATE_SEL(array));
    }

    Array* Array::array(const Object* pObject)
    {
        return Object::sendMessage<Array*>(_NS_PRIVATE_CLS(NSArray), _NS_PRIVATE_SEL(arrayWithObject_), pObject);
    }

    Array* Array::array(const Object* const* pObjects, UInteger count)
    {
        return Object::sendMessage<Array*>(_NS_PRIVATE_CLS(NSArray), _NS_PRIVATE_SEL(arrayWithObjects_count_), pObjects, count);
    }

    Array* Array::alloc()
    {
        return Object::alloc<Array>(_NS_PRIVATE_CLS(NSArray));
    }

    Array* Array::init()
    {
        return Object::init<Array>();
    }

    Array* Array::init(const Object* const* pObjects, UInteger count)
    {
        return Object::sendMessage<Array*>(this, _NS_PRIVATE_SEL(initWithObjects_count_), pObjects, count);
    }

    Array* Array::init(const class Coder* pCoder)
    {
        return Object::sendMessage<Array*>(this, _NS_PRIVATE_SEL(initWithCoder_), pCoder);
    }

    UInteger Array::count() const
    {
        return Object::sendMessage<UInteger>(this, _NS_PRIVATE_SEL(count));
    }

    template <class _Object>
    _Object* Array::object(UInteger index) const
    {
        return Object::sendMessage<_Object*>(this, _NS_PRIVATE_SEL(objectAtIndex_), index);
    }

    Enumerator<Object>* Array::objectEnumerator() const
    {
        return Object::sendMessage<Enumerator<Object>*>(this, _NS_PRIVATE_SEL(objectEnumerator));
    }
}