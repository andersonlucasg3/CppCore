#pragma once

#include "NSDefines.h"
#include "NSTypes.h"

namespace NS
{
    _NS_ENUM(Integer, ComparisonResult) {
        OrderedAscending = -1L,
        OrderedSame,
        OrderedDescending
    };

    const Integer NotFound = IntegerMax;
}
