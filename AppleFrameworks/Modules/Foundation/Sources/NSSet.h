#pragma once

#include "NSObject.hpp"
#include "NSEnumerator.h"

namespace NS
{
    class Set : public Copying<Set>
    {
        public:
            UInteger count() const;
            Enumerator<Object>* objectEnumerator() const;

            static Set* alloc();

            Set* init();
            Set* init(const Object* const* pObjects, UInteger count);
            Set* init(const class Coder* pCoder);
    };
}