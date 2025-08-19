#pragma once

#include "NSObject.hpp"
#include "NSDefines.h"
#include "NSNotification.h"

namespace NS
{
    _NS_CONST(NotificationName, BundleDidLoadNotification);
    _NS_CONST(NotificationName, BundleResourceRequestLowDiskSpaceNotification);

    class String* LocalizedString(const String* pKey, const String*);
    class String* LocalizedStringFromTable(const String* pKey, const String* pTbl, const String*);
    class String* LocalizedStringFromTableInBundle(const String* pKey, const String* pTbl, const class Bundle* pBdle, const String*);
    class String* LocalizedStringWithDefaultValue(const String* pKey, const String* pTbl, const class Bundle* pBdle, const String* pVal, const String*);

    class Bundle : public Referencing<Bundle>
    {
    public:
        static Bundle*      mainBundle();

        static Bundle*      bundle(const class String* pPath);
        static Bundle*      bundle(const class URL* pURL);

        static class Array* allBundles();
        static class Array* allFrameworks();

        static Bundle*      alloc();

        Bundle*             init(const class String* pPath);
        Bundle*             init(const class URL* pURL);

        bool                load();
        bool                unload();

        bool                isLoaded() const;

        bool                preflightAndReturnError(class Error** pError) const;
        bool                loadAndReturnError(class Error** pError);

        class URL*          bundleURL() const;
        class URL*          resourceURL() const;
        class URL*          executableURL() const;
        class URL*          URLForAuxiliaryExecutable(const class String* pExecutableName) const;

        class URL*          privateFrameworksURL() const;
        class URL*          sharedFrameworksURL() const;
        class URL*          sharedSupportURL() const;
        class URL*          builtInPlugInsURL() const;
        class URL*          appStoreReceiptURL() const;

        class String*       bundlePath() const;
        class String*       resourcePath() const;
        class String*       executablePath() const;
        class String*       pathForAuxiliaryExecutable(const class String* pExecutableName) const;

        class String*       privateFrameworksPath() const;
        class String*       sharedFrameworksPath() const;
        class String*       sharedSupportPath() const;
        class String*       builtInPlugInsPath() const;

        class String*       bundleIdentifier() const;
        class Dictionary*   infoDictionary() const;
        class Dictionary*   localizedInfoDictionary() const;
        class Object*       objectForInfoDictionaryKey(const class String* pKey);

        class String*       localizedString(const class String* pKey, const class String* pValue = nullptr, const class String* pTableName = nullptr) const;
    };
}

_NS_PRIVATE_EXTERN_CONST(NS::NotificationName, BundleDidLoadNotification);
_NS_PRIVATE_EXTERN_CONST(NS::NotificationName, BundleResourceRequestLowDiskSpaceNotification);