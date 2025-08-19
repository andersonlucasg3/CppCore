#include "NSEnumerator.h"

namespace NS 
{
    UInteger FastEnumeration::countByEnumerating(FastEnumerationState* pState, Object** pBuffer, UInteger len)
    {
        return Object::sendMessage<UInteger>(this, _NS_PRIVATE_SEL(countByEnumeratingWithState_objects_count_), pState, pBuffer, len);
    }

    template <class _ObjectType>
    _ObjectType* Enumerator<_ObjectType>::nextObject()
    {
        return Object::sendMessage<_ObjectType*>(this, _NS_PRIVATE_SEL(nextObject));
    }

    template <class _ObjectType>
    Array* Enumerator<_ObjectType>::allObjects()
    {
        return Object::sendMessage<Array*>(this, _NS_PRIVATE_SEL(allObjects));
    }
}