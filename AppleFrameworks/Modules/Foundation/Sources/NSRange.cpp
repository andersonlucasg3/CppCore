#include "NSRange.h"

namespace NS
{
    Range::Range(UInteger loc, UInteger len)
    : location(loc)
    , length(len)
    {
    }

    Range Range::Make(UInteger loc, UInteger len)
    {
        return Range(loc, len);
    }

    bool Range::Equal(const Range& range) const
    {
        return (location == range.location) && (length == range.length);
    }

    bool Range::LocationInRange(UInteger loc) const
    {
        return (!(loc < location)) && ((loc - location) < length);
    }

    UInteger Range::Max() const
    {
        return location + length;
    }
}