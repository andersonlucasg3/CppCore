#include "NSData.h"

namespace NS 
{
    void* Data::mutableBytes() const
    {
        return Object::sendMessage<void*>(this, _NS_PRIVATE_SEL(mutableBytes));
    }

    UInteger Data::length() const
    {
        return Object::sendMessage<UInteger>(this, _NS_PRIVATE_SEL(length));
    }
}