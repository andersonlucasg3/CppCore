#include "NSError.h"

_NS_PRIVATE_DEF_CONST(NS::ErrorDomain, CocoaErrorDomain);
_NS_PRIVATE_DEF_CONST(NS::ErrorDomain, POSIXErrorDomain);
_NS_PRIVATE_DEF_CONST(NS::ErrorDomain, OSStatusErrorDomain);
_NS_PRIVATE_DEF_CONST(NS::ErrorDomain, MachErrorDomain);

_NS_PRIVATE_DEF_CONST(NS::ErrorUserInfoKey, UnderlyingErrorKey);
_NS_PRIVATE_DEF_CONST(NS::ErrorUserInfoKey, LocalizedDescriptionKey);
_NS_PRIVATE_DEF_CONST(NS::ErrorUserInfoKey, LocalizedFailureReasonErrorKey);
_NS_PRIVATE_DEF_CONST(NS::ErrorUserInfoKey, LocalizedRecoverySuggestionErrorKey);
_NS_PRIVATE_DEF_CONST(NS::ErrorUserInfoKey, LocalizedRecoveryOptionsErrorKey);
_NS_PRIVATE_DEF_CONST(NS::ErrorUserInfoKey, RecoveryAttempterErrorKey);
_NS_PRIVATE_DEF_CONST(NS::ErrorUserInfoKey, HelpAnchorErrorKey);
_NS_PRIVATE_DEF_CONST(NS::ErrorUserInfoKey, DebugDescriptionErrorKey);
_NS_PRIVATE_DEF_CONST(NS::ErrorUserInfoKey, LocalizedFailureErrorKey);
_NS_PRIVATE_DEF_CONST(NS::ErrorUserInfoKey, StringEncodingErrorKey);
_NS_PRIVATE_DEF_CONST(NS::ErrorUserInfoKey, URLErrorKey);
_NS_PRIVATE_DEF_CONST(NS::ErrorUserInfoKey, FilePathErrorKey);

namespace NS 
{
    Error* Error::error(ErrorDomain domain, Integer code, class Dictionary* pDictionary)
    {
        return Object::sendMessage<Error*>(_NS_PRIVATE_CLS(NSError), _NS_PRIVATE_SEL(errorWithDomain_code_userInfo_), domain, code, pDictionary);
    }

    Error* Error::alloc()
    {
        return Object::alloc<Error>(_NS_PRIVATE_CLS(NSError));
    }

    Error* Error::init()
    {
        return Object::init<Error>();
    }

    Error* Error::init(ErrorDomain domain, Integer code, class Dictionary* pDictionary)
    {
        return Object::sendMessage<Error*>(this, _NS_PRIVATE_SEL(initWithDomain_code_userInfo_), domain, code, pDictionary);
    }

    Integer Error::code() const
    {
        return Object::sendMessage<Integer>(this, _NS_PRIVATE_SEL(code));
    }

    ErrorDomain Error::domain() const
    {
        return Object::sendMessage<ErrorDomain>(this, _NS_PRIVATE_SEL(domain));
    }

    Dictionary* Error::userInfo() const
    {
        return Object::sendMessage<Dictionary*>(this, _NS_PRIVATE_SEL(userInfo));
    }

    String* Error::localizedDescription() const
    {
        return Object::sendMessage<String*>(this, _NS_PRIVATE_SEL(localizedDescription));
    }

    Array* Error::localizedRecoveryOptions() const
    {
        return Object::sendMessage<Array*>(this, _NS_PRIVATE_SEL(localizedRecoveryOptions));
    }

    String* Error::localizedRecoverySuggestion() const
    {
        return Object::sendMessage<String*>(this, _NS_PRIVATE_SEL(localizedRecoverySuggestion));
    }

    String* Error::localizedFailureReason() const
    {
        return Object::sendMessage<String*>(this, _NS_PRIVATE_SEL(localizedFailureReason));
    }
}