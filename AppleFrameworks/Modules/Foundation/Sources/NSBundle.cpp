#include "NSBundle.h"

_NS_PRIVATE_DEF_CONST(NS::NotificationName, BundleDidLoadNotification);
_NS_PRIVATE_DEF_CONST(NS::NotificationName, BundleResourceRequestLowDiskSpaceNotification);

namespace NS 
{
    String* LocalizedString(const String* pKey, const String*)
    {
        return Bundle::mainBundle()->localizedString(pKey, nullptr, nullptr);
    }

    String* LocalizedStringFromTable(const String* pKey, const String* pTbl, const String*)
    {
        return Bundle::mainBundle()->localizedString(pKey, nullptr, pTbl);
    }

    String* LocalizedStringFromTableInBundle(const String* pKey, const String* pTbl, const Bundle* pBdl, const String*)
    {
        return pBdl->localizedString(pKey, nullptr, pTbl);
    }

    String* LocalizedStringWithDefaultValue(const String* pKey, const String* pTbl, const Bundle* pBdl, const String* pVal, const String*)
    {
        return pBdl->localizedString(pKey, pVal, pTbl);
    }

    Bundle* Bundle::mainBundle()
    {
        return Object::sendMessage<Bundle*>(_NS_PRIVATE_CLS(NSBundle), _NS_PRIVATE_SEL(mainBundle));
    }

    Bundle* Bundle::bundle(const class String* pPath)
    {
        return Object::sendMessage<Bundle*>(_NS_PRIVATE_CLS(NSBundle), _NS_PRIVATE_SEL(bundleWithPath_), pPath);
    }

    Bundle* Bundle::bundle(const class URL* pURL)
    {
        return Object::sendMessage<Bundle*>(_NS_PRIVATE_CLS(NSBundle), _NS_PRIVATE_SEL(bundleWithURL_), pURL);
    }

    Array* Bundle::allBundles()
    {
        return Object::sendMessage<Array*>(_NS_PRIVATE_CLS(NSBundle), _NS_PRIVATE_SEL(allBundles));
    }

    Array* Bundle::allFrameworks()
    {
        return Object::sendMessage<Array*>(_NS_PRIVATE_CLS(NSBundle), _NS_PRIVATE_SEL(allFrameworks));
    }

    Bundle* Bundle::alloc()
    {
        return Object::sendMessage<Bundle*>(_NS_PRIVATE_CLS(NSBundle), _NS_PRIVATE_SEL(alloc));
    }

    Bundle* Bundle::init(const String* pPath)
    {
        return Object::sendMessage<Bundle*>(this, _NS_PRIVATE_SEL(initWithPath_), pPath);
    }

    Bundle* Bundle::init(const URL* pURL)
    {
        return Object::sendMessage<Bundle*>(this, _NS_PRIVATE_SEL(initWithURL_), pURL);
    }

    bool Bundle::load()
    {
        return Object::sendMessage<bool>(this, _NS_PRIVATE_SEL(load));
    }

    bool Bundle::unload()
    {
        return Object::sendMessage<bool>(this, _NS_PRIVATE_SEL(unload));
    }

    bool Bundle::isLoaded() const
    {
        return Object::sendMessage<bool>(this, _NS_PRIVATE_SEL(isLoaded));
    }

    bool Bundle::preflightAndReturnError(Error** pError) const
    {
        return Object::sendMessage<bool>(this, _NS_PRIVATE_SEL(preflightAndReturnError_), pError);
    }

    bool Bundle::loadAndReturnError(Error** pError)
    {
        return Object::sendMessage<bool>(this, _NS_PRIVATE_SEL(loadAndReturnError_), pError);
    }

    URL* Bundle::bundleURL() const
    {
        return Object::sendMessage<URL*>(this, _NS_PRIVATE_SEL(bundleURL));
    }

    URL* Bundle::resourceURL() const
    {
        return Object::sendMessage<URL*>(this, _NS_PRIVATE_SEL(resourceURL));
    }

    URL* Bundle::executableURL() const
    {
        return Object::sendMessage<URL*>(this, _NS_PRIVATE_SEL(executableURL));
    }

    URL* Bundle::URLForAuxiliaryExecutable(const String* pExecutableName) const
    {
        return Object::sendMessage<URL*>(this, _NS_PRIVATE_SEL(URLForAuxiliaryExecutable_), pExecutableName);
    }

    URL* Bundle::privateFrameworksURL() const
    {
        return Object::sendMessage<URL*>(this, _NS_PRIVATE_SEL(privateFrameworksURL));
    }

    URL* Bundle::sharedFrameworksURL() const
    {
        return Object::sendMessage<URL*>(this, _NS_PRIVATE_SEL(sharedFrameworksURL));
    }

    URL* Bundle::sharedSupportURL() const
    {
        return Object::sendMessage<URL*>(this, _NS_PRIVATE_SEL(sharedSupportURL));
    }

    URL* Bundle::builtInPlugInsURL() const
    {
        return Object::sendMessage<URL*>(this, _NS_PRIVATE_SEL(builtInPlugInsURL));
    }

    URL* Bundle::appStoreReceiptURL() const
    {
        return Object::sendMessage<URL*>(this, _NS_PRIVATE_SEL(appStoreReceiptURL));
    }

    String* Bundle::bundlePath() const
    {
        return Object::sendMessage<String*>(this, _NS_PRIVATE_SEL(bundlePath));
    }

    String* Bundle::resourcePath() const
    {
        return Object::sendMessage<String*>(this, _NS_PRIVATE_SEL(resourcePath));
    }

    String* Bundle::executablePath() const
    {
        return Object::sendMessage<String*>(this, _NS_PRIVATE_SEL(executablePath));
    }

    String* Bundle::pathForAuxiliaryExecutable(const String* pExecutableName) const
    {
        return Object::sendMessage<String*>(this, _NS_PRIVATE_SEL(pathForAuxiliaryExecutable_), pExecutableName);
    }

    String* Bundle::privateFrameworksPath() const
    {
        return Object::sendMessage<String*>(this, _NS_PRIVATE_SEL(privateFrameworksPath));
    }

    String* Bundle::sharedFrameworksPath() const
    {
        return Object::sendMessage<String*>(this, _NS_PRIVATE_SEL(sharedFrameworksPath));
    }

    String* Bundle::sharedSupportPath() const
    {
        return Object::sendMessage<String*>(this, _NS_PRIVATE_SEL(sharedSupportPath));
    }

    String* Bundle::builtInPlugInsPath() const
    {
        return Object::sendMessage<String*>(this, _NS_PRIVATE_SEL(builtInPlugInsPath));
    }

    String* Bundle::bundleIdentifier() const
    {
        return Object::sendMessage<String*>(this, _NS_PRIVATE_SEL(bundleIdentifier));
    }

    Dictionary* Bundle::infoDictionary() const
    {
        return Object::sendMessage<Dictionary*>(this, _NS_PRIVATE_SEL(infoDictionary));
    }

    Dictionary* Bundle::localizedInfoDictionary() const
    {
        return Object::sendMessage<Dictionary*>(this, _NS_PRIVATE_SEL(localizedInfoDictionary));
    }

    Object* Bundle::objectForInfoDictionaryKey(const String* pKey)
    {
        return Object::sendMessage<Object*>(this, _NS_PRIVATE_SEL(objectForInfoDictionaryKey_), pKey);
    }

    String* Bundle::localizedString(const String* pKey, const String* pValue /* = nullptr */, const String* pTableName /* = nullptr */) const
    {
        return Object::sendMessage<String*>(this, _NS_PRIVATE_SEL(localizedStringForKey_value_table_), pKey, pValue, pTableName);
    }
}