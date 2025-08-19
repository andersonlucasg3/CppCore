#pragma once

#include "NSObject.hpp"

namespace NS
{
    class AutoreleasePool : public Object
    {
    public:
        static AutoreleasePool* alloc();
        AutoreleasePool*        init();

        void                    drain();

        void                    addObject(Object* pObject);

        static void             showPools();
    };
}