#pragma once

#include "NSObject.hpp"
#include "NSDictionary.h"

#include <functional>

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

namespace NS
{
    using NotificationName = class String*;

    class Notification : public NS::Referencing<Notification>
    {
    public:
        NS::String*     name() const;
        NS::Object*     object() const;
        NS::Dictionary* userInfo() const;
    };

    using ObserverBlock = void(^)(Notification*);
    using ObserverFunction = std::function<void(Notification*)>;

    class NotificationCenter : public NS::Referencing<NotificationCenter>
    {
        public:
            static class NotificationCenter* defaultCenter();
            Object* addObserver(NotificationName name, Object* pObj, void* pQueue, ObserverBlock block);
            Object* addObserver(NotificationName name, Object* pObj, void* pQueue, ObserverFunction &handler);
            void removeObserver(Object* pObserver);
    };
}