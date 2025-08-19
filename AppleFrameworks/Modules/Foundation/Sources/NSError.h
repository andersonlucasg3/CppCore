#pragma once

#include "NSObject.hpp"
#include "NSDefines.h"

namespace NS
{
    using ErrorDomain = class String*;

    _NS_CONST(ErrorDomain, CocoaErrorDomain);
    _NS_CONST(ErrorDomain, POSIXErrorDomain);
    _NS_CONST(ErrorDomain, OSStatusErrorDomain);
    _NS_CONST(ErrorDomain, MachErrorDomain);

    using ErrorUserInfoKey = class String*;

    _NS_CONST(ErrorUserInfoKey, UnderlyingErrorKey);
    _NS_CONST(ErrorUserInfoKey, LocalizedDescriptionKey);
    _NS_CONST(ErrorUserInfoKey, LocalizedFailureReasonErrorKey);
    _NS_CONST(ErrorUserInfoKey, LocalizedRecoverySuggestionErrorKey);
    _NS_CONST(ErrorUserInfoKey, LocalizedRecoveryOptionsErrorKey);
    _NS_CONST(ErrorUserInfoKey, RecoveryAttempterErrorKey);
    _NS_CONST(ErrorUserInfoKey, HelpAnchorErrorKey);
    _NS_CONST(ErrorUserInfoKey, DebugDescriptionErrorKey);
    _NS_CONST(ErrorUserInfoKey, LocalizedFailureErrorKey);
    _NS_CONST(ErrorUserInfoKey, StringEncodingErrorKey);
    _NS_CONST(ErrorUserInfoKey, URLErrorKey);
    _NS_CONST(ErrorUserInfoKey, FilePathErrorKey);

    class Error : public Copying<Error>
    {
    public:
        static Error*     error(ErrorDomain domain, Integer code, class Dictionary* pDictionary);

        static Error*     alloc();
        Error*            init();
        Error*            init(ErrorDomain domain, Integer code, class Dictionary* pDictionary);

        Integer           code() const;
        ErrorDomain       domain() const;
        class Dictionary* userInfo() const;

        class String*     localizedDescription() const;
        class Array*      localizedRecoveryOptions() const;
        class String*     localizedRecoverySuggestion() const;
        class String*     localizedFailureReason() const;
    };
}

_NS_PRIVATE_EXTERN_CONST(NS::ErrorDomain, CocoaErrorDomain);
_NS_PRIVATE_EXTERN_CONST(NS::ErrorDomain, POSIXErrorDomain);
_NS_PRIVATE_EXTERN_CONST(NS::ErrorDomain, OSStatusErrorDomain);
_NS_PRIVATE_EXTERN_CONST(NS::ErrorDomain, MachErrorDomain);

_NS_PRIVATE_EXTERN_CONST(NS::ErrorUserInfoKey, UnderlyingErrorKey);
_NS_PRIVATE_EXTERN_CONST(NS::ErrorUserInfoKey, LocalizedDescriptionKey);
_NS_PRIVATE_EXTERN_CONST(NS::ErrorUserInfoKey, LocalizedFailureReasonErrorKey);
_NS_PRIVATE_EXTERN_CONST(NS::ErrorUserInfoKey, LocalizedRecoverySuggestionErrorKey);
_NS_PRIVATE_EXTERN_CONST(NS::ErrorUserInfoKey, LocalizedRecoveryOptionsErrorKey);
_NS_PRIVATE_EXTERN_CONST(NS::ErrorUserInfoKey, RecoveryAttempterErrorKey);
_NS_PRIVATE_EXTERN_CONST(NS::ErrorUserInfoKey, HelpAnchorErrorKey);
_NS_PRIVATE_EXTERN_CONST(NS::ErrorUserInfoKey, DebugDescriptionErrorKey);
_NS_PRIVATE_EXTERN_CONST(NS::ErrorUserInfoKey, LocalizedFailureErrorKey);
_NS_PRIVATE_EXTERN_CONST(NS::ErrorUserInfoKey, StringEncodingErrorKey);
_NS_PRIVATE_EXTERN_CONST(NS::ErrorUserInfoKey, URLErrorKey);
_NS_PRIVATE_EXTERN_CONST(NS::ErrorUserInfoKey, FilePathErrorKey);