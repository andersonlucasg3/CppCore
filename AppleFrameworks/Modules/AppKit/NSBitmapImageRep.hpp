#pragma once

#include <Foundation/NSData.hpp>
#include <Foundation/NSObject.hpp>
#include <Foundation/NSPrivate.hpp>
#include <Foundation/NSTypes.hpp>

namespace NS
{
class BitmapImageRep : public Copying<BitmapImageRep>
{
public:
    static BitmapImageRep* alloc();

    BitmapImageRep* init(NS::Data* data);

    NS::Integer pixelsWide() const;
    NS::Integer pixelsHigh() const;
    NS::Integer bytesPerRow() const;
    unsigned char* bitmapData() const;
};

namespace Private
{
    namespace Class
    {
        _NS_PRIVATE_DEF_CLS(NSBitmapImageRep);
    }

    namespace Selector
    {
        _NS_PRIVATE_DEF_SEL(initWithData_, "initWithData:");
        _NS_PRIVATE_DEF_SEL(pixelsWide, "pixelsWide");
        _NS_PRIVATE_DEF_SEL(pixelsHigh, "pixelsHigh");
        _NS_PRIVATE_DEF_SEL(bytesPerRow, "bytesPerRow");
        _NS_PRIVATE_DEF_SEL(bitmapData, "bitmapData");
    }
}
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::BitmapImageRep* NS::BitmapImageRep::alloc()
{
    return Object::alloc<BitmapImageRep>(_NS_PRIVATE_CLS(NSBitmapImageRep));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::BitmapImageRep* NS::BitmapImageRep::init(NS::Data* data)
{
    return Object::sendMessage<BitmapImageRep*>(this, _NS_PRIVATE_SEL(initWithData_), data);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Integer NS::BitmapImageRep::pixelsWide() const
{
    return Object::sendMessage<Integer>(this, _NS_PRIVATE_SEL(pixelsWide));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Integer NS::BitmapImageRep::pixelsHigh() const
{
    return Object::sendMessage<Integer>(this, _NS_PRIVATE_SEL(pixelsHigh));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE NS::Integer NS::BitmapImageRep::bytesPerRow() const
{
    return Object::sendMessage<Integer>(this, _NS_PRIVATE_SEL(bytesPerRow));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

_NS_INLINE unsigned char* NS::BitmapImageRep::bitmapData() const
{
    return Object::sendMessage<unsigned char*>(this, _NS_PRIVATE_SEL(bitmapData));
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------