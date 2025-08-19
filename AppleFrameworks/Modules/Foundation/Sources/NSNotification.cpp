#include "NSNotification.h"

namespace NS 
{
    String* Notification::name() const
    {
        return Object::sendMessage<String*>(this, _NS_PRIVATE_SEL(name));
    }

    Object* Notification::object() const
    {
        return Object::sendMessage<Object*>(this, _NS_PRIVATE_SEL(object));
    }

    Dictionary* Notification::userInfo() const
    {
        return Object::sendMessage<Dictionary*>(this, _NS_PRIVATE_SEL(userInfo));
    }

    NotificationCenter* NotificationCenter::defaultCenter()
    {
        return Object::sendMessage<NotificationCenter*>(_NS_PRIVATE_CLS(NSNotificationCenter), _NS_PRIVATE_SEL(defaultCenter));
    }

    Object* NotificationCenter::addObserver(NotificationName name, Object* pObj, void* pQueue, ObserverBlock block)
    {
        return Object::sendMessage<Object*>(this, _NS_PRIVATE_SEL(addObserverName_object_queue_block_), name, pObj, pQueue, block);
    }

    Object* NotificationCenter::addObserver(NotificationName name, Object* pObj, void* pQueue, ObserverFunction &handler)
    {
        __block ObserverFunction blockFunction = handler;

        return addObserver(name, pObj, pQueue, ^(Notification* pNotif) {blockFunction(pNotif);});
    }

    void NotificationCenter::removeObserver(Object* pObserver)
    {
        return Object::sendMessage<void>(this, _NS_PRIVATE_SEL(removeObserver_), pObserver);
    }
}