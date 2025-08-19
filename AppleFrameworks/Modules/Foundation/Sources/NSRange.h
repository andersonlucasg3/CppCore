#pragma once

#include "NSDefines.h"
#include "NSTypes.h"

namespace NS
{
    struct Range
    {
        static Range Make(UInteger loc, UInteger len);

        Range(UInteger loc, UInteger len);

        bool     Equal(const Range& range) const;
        bool     LocationInRange(UInteger loc) const;
        UInteger Max() const;

        UInteger location;
        UInteger length;
    } _NS_PACKED;
}