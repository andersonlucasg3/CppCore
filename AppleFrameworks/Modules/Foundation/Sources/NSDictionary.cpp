#include "NSDictionary.h"

namespace NS 
{
    Dictionary* Dictionary::dictionary()
    {
        return Object::sendMessage<Dictionary*>(_NS_PRIVATE_CLS(NSDictionary), _NS_PRIVATE_SEL(dictionary));
    }

    Dictionary* Dictionary::dictionary(const Object* pObject, const Object* pKey)
    {
        return Object::sendMessage<Dictionary*>(_NS_PRIVATE_CLS(NSDictionary), _NS_PRIVATE_SEL(dictionaryWithObject_forKey_), pObject, pKey);
    }

    Dictionary* Dictionary::dictionary(const Object* const* pObjects, const Object* const* pKeys, UInteger count)
    {
        return Object::sendMessage<Dictionary*>(_NS_PRIVATE_CLS(NSDictionary), _NS_PRIVATE_SEL(dictionaryWithObjects_forKeys_count_),
            pObjects, pKeys, count);
    }

    Dictionary* Dictionary::alloc()
    {
        return Object::alloc<Dictionary>(_NS_PRIVATE_CLS(NSDictionary));
    }

    Dictionary* Dictionary::init()
    {
        return Object::init<Dictionary>();
    }

    Dictionary* Dictionary::init(const Object* const* pObjects, const Object* const* pKeys, UInteger count)
    {
        return Object::sendMessage<Dictionary*>(this, _NS_PRIVATE_SEL(initWithObjects_forKeys_count_), pObjects, pKeys, count);
    }

    Dictionary* Dictionary::init(const class Coder* pCoder)
    {
        return Object::sendMessage<Dictionary*>(this, _NS_PRIVATE_SEL(initWithCoder_), pCoder);
    }

    template <class _KeyType>
    Enumerator<_KeyType>* Dictionary::keyEnumerator() const
    {
        return Object::sendMessage<Enumerator<_KeyType>*>(this, _NS_PRIVATE_SEL(keyEnumerator));
    }

    template <class _Object>
    _Object* Dictionary::object(const Object* pKey) const
    {
        return Object::sendMessage<_Object*>(this, _NS_PRIVATE_SEL(objectForKey_), pKey);
    }

    UInteger Dictionary::count() const
    {
        return Object::sendMessage<UInteger>(this, _NS_PRIVATE_SEL(count));
    }
}