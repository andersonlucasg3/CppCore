#pragma once

#include "NSObject.hpp"

namespace NS
{
    class URL : public Copying<URL>
    {
    public:
        FOUNDATION_API static URL* url(const class String* urlString);
        FOUNDATION_API static URL* fileURLWithPath(const class String* pPath);

        FOUNDATION_API static URL* alloc();
        FOUNDATION_API URL*        init();
        FOUNDATION_API URL*        init(const class String* pString);
        FOUNDATION_API URL*        initFileURLWithPath(const class String* pPath);
        
        FOUNDATION_API String*     path() const;

        FOUNDATION_API const char* fileSystemRepresentation() const;
    };
}