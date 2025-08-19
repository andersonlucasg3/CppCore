#pragma once

#include "NSObject.hpp"
#include "NSDefines.h"

namespace NS
{
    class URL : public Copying<URL>
    {
    public:
        static URL* fileURLWithPath(const class String* pPath);

        static URL* alloc();
        URL*        init();
        URL*        init(const class String* pString);
        URL*        initFileURLWithPath(const class String* pPath);
        
        String*     path() const;

        const char* fileSystemRepresentation() const;
    };
}