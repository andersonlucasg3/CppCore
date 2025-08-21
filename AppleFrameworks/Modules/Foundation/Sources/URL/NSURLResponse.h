#pragma once

#include "NSObject.hpp"
#include "NSTypes.h"

#include <cstdint>

namespace NS
{
    class URL;

    class URLResponse : public Copying<URLResponse>
    {
    public:
        FOUNDATION_API static URLResponse* alloc();
        FOUNDATION_API URLResponse* init(URL* URL, String* MIMEType, Integer expectedContentLength, String* textEncodingName);

        FOUNDATION_API URL* URL() const;
        FOUNDATION_API int64_t expectedContentLength() const;
        FOUNDATION_API String* suggestedFilename() const;
        FOUNDATION_API String* MIMEType() const;
        FOUNDATION_API String* textEncodingName() const;
    };
}