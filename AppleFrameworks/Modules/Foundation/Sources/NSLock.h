#pragma once

#include "NSObject.hpp"
#include "NSDefines.h"
#include "NSDate.h"

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace NS
{
    template <class _Class, class _Base = class Object>
    class Locking : public _Base
    {
    public:
        void lock();
        void unlock();
    };

    class Condition : public Locking<Condition>
    {
    public:
        static Condition* alloc();

        Condition*        init();

        void              wait();
        bool              waitUntilDate(Date* pLimit);
        void              signal();
        void              broadcast();
    };

    template<class _Class, class _Base /* = NS::Object */>
    _NS_INLINE void NS::Locking<_Class, _Base>::lock()
    {
        NS::Object::sendMessage<void>(this, _NS_PRIVATE_SEL(lock));
    }
    
    template<class _Class, class _Base /* = NS::Object */>
    _NS_INLINE void NS::Locking<_Class, _Base>::unlock()
    {
        NS::Object::sendMessage<void>(this, _NS_PRIVATE_SEL(unlock));
    }
}