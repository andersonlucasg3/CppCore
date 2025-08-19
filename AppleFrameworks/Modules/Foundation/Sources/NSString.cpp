#include "NSString.h"

#include "NSPrivate.h"

namespace NS
{
    String* String::string()
    {
        return Object::sendMessage<String*>(_NS_PRIVATE_CLS(NSString), _NS_PRIVATE_SEL(string));
    }

    String* String::string(const String* pString)
    {
        return Object::sendMessage<String*>(_NS_PRIVATE_CLS(NSString), _NS_PRIVATE_SEL(stringWithString_), pString);
    }

    String* String::string(const char* pString, StringEncoding encoding)
    {
        return Object::sendMessage<String*>(_NS_PRIVATE_CLS(NSString), _NS_PRIVATE_SEL(stringWithCString_encoding_), pString, encoding);
    }

    String* String::alloc()
    {
        return Object::alloc<String>(_NS_PRIVATE_CLS(NSString));
    }

    String* String::init()
    {
        return Object::init<String>();
    }

    String* String::init(const String* pString)
    {
        return Object::sendMessage<String*>(this, _NS_PRIVATE_SEL(initWithString_), pString);
    }

    String* String::init(const char* pString, StringEncoding encoding)
    {
        return Object::sendMessage<String*>(this, _NS_PRIVATE_SEL(initWithCString_encoding_), pString, encoding);
    }

    String* String::init(void* pBytes, UInteger len, StringEncoding encoding, bool freeBuffer)
    {
        return Object::sendMessage<String*>(this, _NS_PRIVATE_SEL(initWithBytesNoCopy_length_encoding_freeWhenDone_), pBytes, len, encoding, freeBuffer);
    }

    unichar String::character(UInteger index) const
    {
        return Object::sendMessage<unichar>(this, _NS_PRIVATE_SEL(characterAtIndex_), index);
    }

    UInteger String::length() const
    {
        return Object::sendMessage<UInteger>(this, _NS_PRIVATE_SEL(length));
    }

    const char* String::cString(StringEncoding encoding) const
    {
        return Object::sendMessage<const char*>(this, _NS_PRIVATE_SEL(cStringUsingEncoding_), encoding);
    }

    const char* String::utf8String() const
    {
        return Object::sendMessage<const char*>(this, _NS_PRIVATE_SEL(UTF8String));
    }

    UInteger String::maximumLengthOfBytes(StringEncoding encoding) const
    {
        return Object::sendMessage<UInteger>(this, _NS_PRIVATE_SEL(maximumLengthOfBytesUsingEncoding_), encoding);
    }

    UInteger String::lengthOfBytes(StringEncoding encoding) const
    {
        return Object::sendMessage<UInteger>(this, _NS_PRIVATE_SEL(lengthOfBytesUsingEncoding_), encoding);
    }

    bool String::isEqualToString(const String* pString) const
    {
        return Object::sendMessage<bool>(this, _NS_PRIVATE_SEL(isEqualToString_), pString);
    }

    Range String::rangeOfString(const String* pString, StringCompareOptions options) const
    {
        return Object::sendMessage<Range>(this, _NS_PRIVATE_SEL(rangeOfString_options_), pString, options);
    }

    const char* String::fileSystemRepresentation() const
    {
        return Object::sendMessage<const char*>(this, _NS_PRIVATE_SEL(fileSystemRepresentation));
    }

    String* String::stringByResolvingSymlinksInPath() const
    {
        return Object::sendMessage<String*>(this, _NS_PRIVATE_SEL(stringByResolvingSymlinksInPath));
    }

    String* String::stringByAppendingString(const String* pString) const
    {
        return Object::sendMessage<String*>(this, _NS_PRIVATE_SEL(stringByAppendingString_), pString);
    }

    ComparisonResult String::caseInsensitiveCompare(const String* pString) const
    {
        return Object::sendMessage<ComparisonResult>(this, _NS_PRIVATE_SEL(caseInsensitiveCompare_), pString);
    }
}