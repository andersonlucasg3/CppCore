#pragma once

#include "NSObject.hpp"
#include "NSDefines.h"

namespace NS
{
    using TimeInterval = double;

    class Date : public Copying<Date>
    {
    public:
        static Date* dateWithTimeIntervalSinceNow(TimeInterval secs);
    };
}