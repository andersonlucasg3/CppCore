#pragma once

#include "NSObject.hpp"
#include "NSEnumerator.h"

namespace NS
{
    class Dictionary : public NS::Copying<Dictionary>
    {
    public:
        static Dictionary* dictionary();
        static Dictionary* dictionary(const Object* pObject, const Object* pKey);
        static Dictionary* dictionary(const Object* const* pObjects, const Object* const* pKeys, UInteger count);

        static Dictionary* alloc();

        Dictionary*        init();
        Dictionary*        init(const Object* const* pObjects, const Object* const* pKeys, UInteger count);
        Dictionary*        init(const class Coder* pCoder);

        template <class _KeyType = Object>
        Enumerator<_KeyType>* keyEnumerator() const;

        template <class _Object = Object>
        _Object* object(const Object* pKey) const;
        UInteger count() const;
    };
}