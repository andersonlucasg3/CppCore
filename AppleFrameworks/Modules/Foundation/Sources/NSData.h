#pragma once

#include "NSObject.hpp"

namespace NS
{
    class Data : public Copying<Data>
    {
    public:
        void*    mutableBytes() const;
        UInteger length() const;
    };
}