#include "NSURL.h"

#include "NSPrivate.h"

namespace NS 
{
    URL* URL::url(const String* urlString)
    {
        return Object::sendMessage<URL*>(_NS_PRIVATE_CLS(NSURL), _NS_PRIVATE_SEL(URLWithString_), urlString);
    }

    URL* URL::fileURLWithPath(const String* pPath)
    {
        return Object::sendMessage<URL*>(_NS_PRIVATE_CLS(NSURL), _NS_PRIVATE_SEL(fileURLWithPath_), pPath);
    }

    URL* URL::alloc()
    {
        return Object::alloc<URL>(_NS_PRIVATE_CLS(NSURL));
    }

    URL* URL::init()
    {
        return Object::init<URL>();
    }

    URL* URL::init(const String* pString)
    {
        return Object::sendMessage<URL*>(this, _NS_PRIVATE_SEL(initWithString_), pString);
    }

    URL* URL::initFileURLWithPath(const String* pPath)
    {
        return Object::sendMessage<URL*>(this, _NS_PRIVATE_SEL(initFileURLWithPath_), pPath);
    }

    String* URL::path() const
    {
        return Object::sendMessage<String*>(this, _NS_PRIVATE_SEL(path));
    }

    const char* URL::fileSystemRepresentation() const
    {
        return Object::sendMessage<const char*>(this, _NS_PRIVATE_SEL(fileSystemRepresentation));
    }
}