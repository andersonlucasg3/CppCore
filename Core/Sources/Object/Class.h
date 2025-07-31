#pragma once

#include "CoreDefinitions.h"
#include "Templates/SmartPointer/SharedPointer.h"
#include "Templates/SmartPointer/WeakPointer.h"
#include "Templates/SmartPointer/MakeAndCasts.h"

#include <type_traits>

CORE_CLASS_HEADER(Object);
CORE_CLASS_HEADER(Class);

class CClass
{
    /** this one is to be called internally */
    virtual CObject* CreateRaw() const = 0;

    /** this is the one that should be used in the New implementation */
    template<typename TObject, typename ... TArgs>
    TObject* CreateRaw(TArgs ... Args) const
    {
        // calls the constructor manually
        return new (CreateRaw()) TObject(std::forward<TArgs>(Args)...);
    }

    template<typename ... TArgs>
    friend CObjectPtr New(const CClassPtr& Class, TArgs ... Args);
    template<typename TObject, typename ... TArgs>
    friend TSharedPtr<TObject> New(const CClassPtr& Class, TArgs ... Args);
    template<typename TObject, typename ... TArgs>
    friend TSharedPtr<TObject> New(TArgs ... Args);
};

template<class TObject>
class TClass : public CClass
{
    static_assert(std::is_base_of_v<CObject, TObject>);

    CObject* CreateRaw() const override
    {
        return static_cast<CObject*>(operator new(sizeof(TObject)));
    }

    template<typename ... TArgs>
    friend CObjectPtr New(const CClassPtr& Class, TArgs ... Args);
    template<typename TOtherObject, typename ... TArgs>
    friend TSharedPtr<TOtherObject> New(const CClassPtr& Class, TArgs ... Args);
    template<typename TOtherObject, typename ... TArgs>
    friend TSharedPtr<TOtherObject> New(TArgs ... Args);
};

template<typename TType>
CClassPtr GetClass()
{
    return MakeShared<TClass<TType>>();
}