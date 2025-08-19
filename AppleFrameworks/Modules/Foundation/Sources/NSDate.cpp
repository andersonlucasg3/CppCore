#include "NSDate.h"

namespace NS 
{
    Date* Date::dateWithTimeIntervalSinceNow(TimeInterval secs)
    {
        return Object::sendMessage<Date*>(_NS_PRIVATE_CLS(NSDate), _NS_PRIVATE_SEL(dateWithTimeIntervalSinceNow_), secs);
    }
}