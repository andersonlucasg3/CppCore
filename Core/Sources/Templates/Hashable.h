#pragma once

#include "Defines/Types.h"

using namespace Core::Types;

class CHashable
{
public:
    virtual SSizeT Hash() const = 0;
};