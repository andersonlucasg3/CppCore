#pragma once

#include "NSObject.hpp"

namespace NS
{
    struct FastEnumerationState
    {
        unsigned long  state;
        Object**       itemsPtr;
        unsigned long* mutationsPtr;
        unsigned long  extra[5];
    } _NS_PACKED;

    class FastEnumeration : public Referencing<FastEnumeration>
    {
    public:
        NS::UInteger countByEnumerating(FastEnumerationState* pState, Object** pBuffer, NS::UInteger len);
    };

    template <class _ObjectType>
    class Enumerator : public Referencing<Enumerator<_ObjectType>, FastEnumeration>
    {
    public:
        _ObjectType* nextObject();
        class Array* allObjects();
    };
}