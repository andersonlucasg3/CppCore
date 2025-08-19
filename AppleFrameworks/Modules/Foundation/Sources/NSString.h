#pragma once

#include "NSObject.hpp"
#include "NSDefines.h"
#include "NSObjCRuntime.h"
#include "NSRange.h"

namespace NS
{
    _NS_ENUM(NS::UInteger, StringEncoding) {
        ASCIIStringEncoding = 1,
        NEXTSTEPStringEncoding = 2,
        JapaneseEUCStringEncoding = 3,
        UTF8StringEncoding = 4,
        ISOLatin1StringEncoding = 5,
        SymbolStringEncoding = 6,
        NonLossyASCIIStringEncoding = 7,
        ShiftJISStringEncoding = 8,
        ISOLatin2StringEncoding = 9,
        UnicodeStringEncoding = 10,
        WindowsCP1251StringEncoding = 11,
        WindowsCP1252StringEncoding = 12,
        WindowsCP1253StringEncoding = 13,
        WindowsCP1254StringEncoding = 14,
        WindowsCP1250StringEncoding = 15,
        ISO2022JPStringEncoding = 21,
        MacOSRomanStringEncoding = 30,

        UTF16StringEncoding = UnicodeStringEncoding,

        UTF16BigEndianStringEncoding = 0x90000100,
        UTF16LittleEndianStringEncoding = 0x94000100,

        UTF32StringEncoding = 0x8c000100,
        UTF32BigEndianStringEncoding = 0x98000100,
        UTF32LittleEndianStringEncoding = 0x9c000100
    };

    _NS_OPTIONS(NS::UInteger, StringCompareOptions) {
        CaseInsensitiveSearch = 1,
        LiteralSearch = 2,
        BackwardsSearch = 4,
        AnchoredSearch = 8,
        NumericSearch = 64,
        DiacriticInsensitiveSearch = 128,
        WidthInsensitiveSearch = 256,
        ForcedOrderingSearch = 512,
        RegularExpressionSearch = 1024
    };

    using unichar = unsigned short;

    class String : public Copying<String>
    {
    public:
        static String*   string();
        static String*   string(const String* pString);
        static String*   string(const char* pString, StringEncoding encoding);

        static String*   alloc();
        String*          init();
        String*          init(const String* pString);
        String*          init(const char* pString, StringEncoding encoding);
        String*          init(void* pBytes, UInteger len, StringEncoding encoding, bool freeBuffer);

        unichar          character(UInteger index) const;
        UInteger         length() const;

        const char*      cString(StringEncoding encoding) const;
        const char*      utf8String() const;
        UInteger         maximumLengthOfBytes(StringEncoding encoding) const;
        UInteger         lengthOfBytes(StringEncoding encoding) const;

        bool             isEqualToString(const String* pString) const;
        Range            rangeOfString(const String* pString, StringCompareOptions options) const;

        const char*      fileSystemRepresentation() const;
        
        String*          stringByResolvingSymlinksInPath() const;
        String*          stringByAppendingString(const String* pString) const;
        ComparisonResult caseInsensitiveCompare(const String* pString) const;
    };

    /// Create an NS::String* from a string literal.
    #define MTLSTR(literal) (NS::String*)__builtin___CFStringMakeConstantString("" literal "")

    template <std::size_t _StringLen>
    [[deprecated("please use MTLSTR(str)")]] constexpr const String* MakeConstantString(const char (&str)[_StringLen])
    {
        return reinterpret_cast<const String*>(__CFStringMakeConstantString(str));
    }
}

