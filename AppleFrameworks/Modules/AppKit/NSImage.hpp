#pragma once

#include <Foundation/NSData.hpp>
#include <Foundation/NSDefines.hpp>
#include <Foundation/NSPrivate.hpp>
#include <Foundation/NSObject.hpp>

namespace NS
{
class Image : public Copying<Image>
{
public:
    static Image* alloc();

    Image* init();
    Image* init(NS::String* filepath);

    NS::Data* TIFFRepresentation() const;
};

namespace Private
{
    namespace Class
    {
        _NS_PRIVATE_DEF_CLS(NSImage);
    }

    namespace Selector
    {
        _NS_PRIVATE_DEF_SEL(initWithContentsOfFile_, "initWithContentsOfFile:");
        _NS_PRIVATE_DEF_SEL(TIFFRepresentation, "TIFFRepresentation");
    }
}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Image* NS::Image::alloc()
{
    return Object::alloc<Image>(_NS_PRIVATE_CLS(NSImage));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Image* NS::Image::init()
{
    return Object::init<Image>();
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Image* NS::Image::init(NS::String* filepath)
{
    return Object::sendMessage<Image*>(this, _NS_PRIVATE_SEL(initWithContentsOfFile_), filepath);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Data* NS::Image::TIFFRepresentation() const
{
    return Object::sendMessage<Data*>(this, _NS_PRIVATE_SEL(TIFFRepresentation));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------