#pragma once

#include <objc/objc.h>

#ifdef METALCPP_SYMBOL_VISIBILITY_HIDDEN
#define _NS_PRIVATE_VISIBILITY __attribute__((visibility("hidden")))
#else
#define _NS_PRIVATE_VISIBILITY __attribute__((visibility("default")))
#endif // METALCPP_SYMBOL_VISIBILITY_HIDDEN

#define _NS_PRIVATE_IMPORT __attribute__((weak_import))

#ifdef __OBJC__
#define _NS_PRIVATE_OBJC_LOOKUP_CLASS(symbol) ((__bridge void*)objc_lookUpClass(#symbol))
#define _NS_PRIVATE_OBJC_GET_PROTOCOL(symbol) ((__bridge void*)objc_getProtocol(#symbol))
#else
#define _NS_PRIVATE_OBJC_LOOKUP_CLASS(symbol) objc_lookUpClass(#symbol)
#define _NS_PRIVATE_OBJC_GET_PROTOCOL(symbol) objc_getProtocol(#symbol)
#endif // __OBJC__

#define _NS_PRIVATE_DEF_CLS(symbol) void* s_k##symbol _NS_PRIVATE_VISIBILITY = _NS_PRIVATE_OBJC_LOOKUP_CLASS(symbol)
#define _NS_PRIVATE_DEF_PRO(symbol) void* s_k##symbol _NS_PRIVATE_VISIBILITY = _NS_PRIVATE_OBJC_GET_PROTOCOL(symbol)
#define _NS_PRIVATE_DEF_SEL(accessor, symbol) SEL s_k##accessor _NS_PRIVATE_VISIBILITY = sel_registerName(symbol)

#if defined(__MAC_15_0) || defined(__IPHONE_18_0) || defined(__TVOS_18_0)
#define _NS_PRIVATE_DEF_CONST(type, symbol)              \
    _NS_EXTERN type const NS##symbol _NS_PRIVATE_IMPORT; \
    type const                       NS::symbol = (nullptr != &NS##symbol) ? NS##symbol : type()
#else
#define _NS_PRIVATE_DEF_CONST(type, symbol) \
    _NS_EXTERN type const MTL##symbol _NS_PRIVATE_IMPORT; \
    type const             NS::symbol = Private::LoadSymbol<type>("NS" #symbol)
#endif

#define _NS_PRIVATE_CLS(symbol) (Private::Class::s_k##symbol)
#define _NS_PRIVATE_SEL(accessor) (Private::Selector::s_k##accessor)

#define _NS_PRIVATE_EXTERN_CLS(symbol) extern void* s_k##symbol
#define _NS_PRIVATE_EXTERN_PRO(symbol) extern void* s_k##symbol
#define _NS_PRIVATE_EXTERN_SEL(accessor, symbol) extern SEL s_k##accessor
#define _NS_PRIVATE_EXTERN_CONST(type, symbol) extern type const NS::symbol

namespace NS::Private
{
    namespace Class
    {
        _NS_PRIVATE_EXTERN_CLS(NSURL);
        _NS_PRIVATE_EXTERN_CLS(NSArray);
        _NS_PRIVATE_EXTERN_CLS(NSAutoreleasePool);
        _NS_PRIVATE_EXTERN_CLS(NSBundle);
        _NS_PRIVATE_EXTERN_CLS(NSCondition);
        _NS_PRIVATE_EXTERN_CLS(NSDate);
        _NS_PRIVATE_EXTERN_CLS(NSDictionary);
        _NS_PRIVATE_EXTERN_CLS(NSError);
        _NS_PRIVATE_EXTERN_CLS(NSNotificationCenter);
        _NS_PRIVATE_EXTERN_CLS(NSNumber);
        _NS_PRIVATE_EXTERN_CLS(NSObject);
        _NS_PRIVATE_EXTERN_CLS(NSProcessInfo);
        _NS_PRIVATE_EXTERN_CLS(NSSet);
        _NS_PRIVATE_EXTERN_CLS(NSValue);
        _NS_PRIVATE_EXTERN_CLS(NSString);
        _NS_PRIVATE_EXTERN_CLS(NSFileManager);
    }

    namespace Selector
    {
        _NS_PRIVATE_EXTERN_SEL(defaultManager, "defaultManager");
        _NS_PRIVATE_EXTERN_SEL(urlForDirectory_inDomain_appropriateForURL_create_error_, "URLForDirectory:inDomain:appropriateForURL:create:error:");
        _NS_PRIVATE_EXTERN_SEL(createDirectoryAtPath_withIntermediateDirectories_attributes_error_, "createDirectoryAtPath:withIntermediateDirectories:attributes:error:");
        _NS_PRIVATE_EXTERN_SEL(createDirectoryAtURL_withIntermediateDirectories_attributes_error_, "createDirectoryAtURL:withIntermediateDirectories:attributes:error:");
        _NS_PRIVATE_EXTERN_SEL(removeItemAtPath_error_, "removeItemAtPath:error:");
        _NS_PRIVATE_EXTERN_SEL(removeItemAtURL_error_, "removeItemAtURL:error:");
        _NS_PRIVATE_EXTERN_SEL(fileExistsAtPath_, "fileExistsAtPath:");
        _NS_PRIVATE_EXTERN_SEL(fileExistsAtPath_isDirectory_, "fileExistsAtPath:isDirectory:");
        _NS_PRIVATE_EXTERN_SEL(initFileURLWithPath_, "initFileURLWithPath:");
        _NS_PRIVATE_EXTERN_SEL(path, "path");
        _NS_PRIVATE_EXTERN_SEL(array, "array");
        _NS_PRIVATE_EXTERN_SEL(arrayWithObject_, "arrayWithObject:");
        _NS_PRIVATE_EXTERN_SEL(arrayWithObjects_count_, "arrayWithObjects:count:");
        _NS_PRIVATE_EXTERN_SEL(initWithObjects_count_, "initWithObjects:count:");
        _NS_PRIVATE_EXTERN_SEL(count, "count");
        _NS_PRIVATE_EXTERN_SEL(addObject_, "addObject:");
        _NS_PRIVATE_EXTERN_SEL(addObserverName_object_queue_block_, "addObserverForName:object:queue:usingBlock:");
        _NS_PRIVATE_EXTERN_SEL(activeProcessorCount, "activeProcessorCount");
        _NS_PRIVATE_EXTERN_SEL(allBundles, "allBundles");
        _NS_PRIVATE_EXTERN_SEL(allFrameworks, "allFrameworks");
        _NS_PRIVATE_EXTERN_SEL(allObjects, "allObjects");
        _NS_PRIVATE_EXTERN_SEL(alloc, "alloc");
        _NS_PRIVATE_EXTERN_SEL(appStoreReceiptURL, "appStoreReceiptURL");
        _NS_PRIVATE_EXTERN_SEL(arguments, "arguments");
        _NS_PRIVATE_EXTERN_SEL(automaticTerminationSupportEnabled, "automaticTerminationSupportEnabled");
        _NS_PRIVATE_EXTERN_SEL(autorelease, "autorelease");
        _NS_PRIVATE_EXTERN_SEL(beginActivityWithOptions_reason_, "beginActivityWithOptions:reason:");
        _NS_PRIVATE_EXTERN_SEL(boolValue, "boolValue");
        _NS_PRIVATE_EXTERN_SEL(broadcast, "broadcast");
        _NS_PRIVATE_EXTERN_SEL(builtInPlugInsPath, "builtInPlugInsPath");
        _NS_PRIVATE_EXTERN_SEL(builtInPlugInsURL, "builtInPlugInsURL");
        _NS_PRIVATE_EXTERN_SEL(bundleIdentifier, "bundleIdentifier");
        _NS_PRIVATE_EXTERN_SEL(bundlePath, "bundlePath");
        _NS_PRIVATE_EXTERN_SEL(bundleURL, "bundleURL");
        _NS_PRIVATE_EXTERN_SEL(bundleWithPath_, "bundleWithPath:");
        _NS_PRIVATE_EXTERN_SEL(bundleWithURL_, "bundleWithURL:");
        _NS_PRIVATE_EXTERN_SEL(caseInsensitiveCompare_, "caseInsensitiveCompare:");
        _NS_PRIVATE_EXTERN_SEL(characterAtIndex_, "characterAtIndex:");
        _NS_PRIVATE_EXTERN_SEL(charValue, "charValue");
        _NS_PRIVATE_EXTERN_SEL(countByEnumeratingWithState_objects_count_, "countByEnumeratingWithState:objects:count:");
        _NS_PRIVATE_EXTERN_SEL(cStringUsingEncoding_, "cStringUsingEncoding:");
        _NS_PRIVATE_EXTERN_SEL(code, "code");
        _NS_PRIVATE_EXTERN_SEL(compare_, "compare:");
        _NS_PRIVATE_EXTERN_SEL(copy, "copy");
        _NS_PRIVATE_EXTERN_SEL(dateWithTimeIntervalSinceNow_, "dateWithTimeIntervalSinceNow:");
        _NS_PRIVATE_EXTERN_SEL(defaultCenter, "defaultCenter");
        _NS_PRIVATE_EXTERN_SEL(descriptionWithLocale_, "descriptionWithLocale:");
        _NS_PRIVATE_EXTERN_SEL(disableAutomaticTermination_, "disableAutomaticTermination:");
        _NS_PRIVATE_EXTERN_SEL(disableSuddenTermination, "disableSuddenTermination");
        _NS_PRIVATE_EXTERN_SEL(debugDescription, "debugDescription");
        _NS_PRIVATE_EXTERN_SEL(description, "description");
        _NS_PRIVATE_EXTERN_SEL(dictionary, "dictionary");
        _NS_PRIVATE_EXTERN_SEL(dictionaryWithObject_forKey_, "dictionaryWithObject:forKey:");
        _NS_PRIVATE_EXTERN_SEL(dictionaryWithObjects_forKeys_count_, "dictionaryWithObjects:forKeys:count:");
        _NS_PRIVATE_EXTERN_SEL(domain, "domain");
        _NS_PRIVATE_EXTERN_SEL(doubleValue, "doubleValue");
        _NS_PRIVATE_EXTERN_SEL(drain, "drain");
        _NS_PRIVATE_EXTERN_SEL(enableAutomaticTermination_, "enableAutomaticTermination:");
        _NS_PRIVATE_EXTERN_SEL(enableSuddenTermination, "enableSuddenTermination");
        _NS_PRIVATE_EXTERN_SEL(endActivity_, "endActivity:");
        _NS_PRIVATE_EXTERN_SEL(environment, "environment");
        _NS_PRIVATE_EXTERN_SEL(errorWithDomain_code_userInfo_, "errorWithDomain:code:userInfo:");
        _NS_PRIVATE_EXTERN_SEL(executablePath, "executablePath");
        _NS_PRIVATE_EXTERN_SEL(executableURL, "executableURL");
        _NS_PRIVATE_EXTERN_SEL(fileSystemRepresentation, "fileSystemRepresentation");
        _NS_PRIVATE_EXTERN_SEL(fileURLWithPath_, "fileURLWithPath:");
        _NS_PRIVATE_EXTERN_SEL(floatValue, "floatValue");
        _NS_PRIVATE_EXTERN_SEL(fullUserName, "fullUserName");
        _NS_PRIVATE_EXTERN_SEL(getValue_size_, "getValue:size:");
        _NS_PRIVATE_EXTERN_SEL(globallyUniqueString, "globallyUniqueString");
        _NS_PRIVATE_EXTERN_SEL(hash, "hash");
        _NS_PRIVATE_EXTERN_SEL(hasPerformanceProfile_, "hasPerformanceProfile:");
        _NS_PRIVATE_EXTERN_SEL(hostName, "hostName");
        _NS_PRIVATE_EXTERN_SEL(infoDictionary, "infoDictionary");
        _NS_PRIVATE_EXTERN_SEL(init, "init");
        _NS_PRIVATE_EXTERN_SEL(initWithCoder_, "initWithCoder:");
        _NS_PRIVATE_EXTERN_SEL(initWithBool_, "initWithBool:");
        _NS_PRIVATE_EXTERN_SEL(initWithBytes_objCType_, "initWithBytes:objCType:");
        _NS_PRIVATE_EXTERN_SEL(initWithBytesNoCopy_length_encoding_freeWhenDone_, "initWithBytesNoCopy:length:encoding:freeWhenDone:");
        _NS_PRIVATE_EXTERN_SEL(initWithChar_, "initWithChar:");
        _NS_PRIVATE_EXTERN_SEL(initWithCString_encoding_, "initWithCString:encoding:");
        _NS_PRIVATE_EXTERN_SEL(initWithDomain_code_userInfo_, "initWithDomain:code:userInfo:");
        _NS_PRIVATE_EXTERN_SEL(initWithDouble_, "initWithDouble:");
        _NS_PRIVATE_EXTERN_SEL(initWithFloat_, "initWithFloat:");
        _NS_PRIVATE_EXTERN_SEL(initWithInt_, "initWithInt:");
        _NS_PRIVATE_EXTERN_SEL(initWithLong_, "initWithLong:");
        _NS_PRIVATE_EXTERN_SEL(initWithLongLong_, "initWithLongLong:");
        _NS_PRIVATE_EXTERN_SEL(initWithObjects_forKeys_count_, "initWithObjects:forKeys:count:");
        _NS_PRIVATE_EXTERN_SEL(initWithPath_, "initWithPath:");
        _NS_PRIVATE_EXTERN_SEL(initWithShort_, "initWithShort:");
        _NS_PRIVATE_EXTERN_SEL(initWithString_, "initWithString:");
        _NS_PRIVATE_EXTERN_SEL(initWithUnsignedChar_, "initWithUnsignedChar:");
        _NS_PRIVATE_EXTERN_SEL(initWithUnsignedInt_, "initWithUnsignedInt:");
        _NS_PRIVATE_EXTERN_SEL(initWithUnsignedLong_, "initWithUnsignedLong:");
        _NS_PRIVATE_EXTERN_SEL(initWithUnsignedLongLong_, "initWithUnsignedLongLong:");
        _NS_PRIVATE_EXTERN_SEL(initWithUnsignedShort_, "initWithUnsignedShort:");
        _NS_PRIVATE_EXTERN_SEL(initWithURL_, "initWithURL:");
        _NS_PRIVATE_EXTERN_SEL(integerValue, "integerValue");
        _NS_PRIVATE_EXTERN_SEL(intValue, "intValue");
        _NS_PRIVATE_EXTERN_SEL(isDeviceCertified_, "isDeviceCertifiedFor:");
        _NS_PRIVATE_EXTERN_SEL(isEqual_, "isEqual:");
        _NS_PRIVATE_EXTERN_SEL(isEqualToNumber_, "isEqualToNumber:");
        _NS_PRIVATE_EXTERN_SEL(isEqualToString_, "isEqualToString:");
        _NS_PRIVATE_EXTERN_SEL(isEqualToValue_, "isEqualToValue:");
        _NS_PRIVATE_EXTERN_SEL(isiOSAppOnMac, "isiOSAppOnMac");
        _NS_PRIVATE_EXTERN_SEL(isLoaded, "isLoaded");
        _NS_PRIVATE_EXTERN_SEL(isLowPowerModeEnabled, "isLowPowerModeEnabled");
        _NS_PRIVATE_EXTERN_SEL(isMacCatalystApp, "isMacCatalystApp");
        _NS_PRIVATE_EXTERN_SEL(isOperatingSystemAtLeastVersion_, "isOperatingSystemAtLeastVersion:");
        _NS_PRIVATE_EXTERN_SEL(keyEnumerator, "keyEnumerator");
        _NS_PRIVATE_EXTERN_SEL(length, "length");
        _NS_PRIVATE_EXTERN_SEL(lengthOfBytesUsingEncoding_, "lengthOfBytesUsingEncoding:");
        _NS_PRIVATE_EXTERN_SEL(load, "load");
        _NS_PRIVATE_EXTERN_SEL(loadAndReturnError_, "loadAndReturnError:");
        _NS_PRIVATE_EXTERN_SEL(localizedDescription, "localizedDescription");
        _NS_PRIVATE_EXTERN_SEL(localizedFailureReason, "localizedFailureReason");
        _NS_PRIVATE_EXTERN_SEL(localizedInfoDictionary, "localizedInfoDictionary");
        _NS_PRIVATE_EXTERN_SEL(localizedRecoveryOptions, "localizedRecoveryOptions");
        _NS_PRIVATE_EXTERN_SEL(localizedRecoverySuggestion, "localizedRecoverySuggestion");
        _NS_PRIVATE_EXTERN_SEL(localizedStringForKey_value_table_, "localizedStringForKey:value:table:");
        _NS_PRIVATE_EXTERN_SEL(lock, "lock");
        _NS_PRIVATE_EXTERN_SEL(longValue, "longValue");
        _NS_PRIVATE_EXTERN_SEL(longLongValue, "longLongValue");
        _NS_PRIVATE_EXTERN_SEL(mainBundle, "mainBundle");
        _NS_PRIVATE_EXTERN_SEL(maximumLengthOfBytesUsingEncoding_, "maximumLengthOfBytesUsingEncoding:");
        _NS_PRIVATE_EXTERN_SEL(methodSignatureForSelector_, "methodSignatureForSelector:");
        _NS_PRIVATE_EXTERN_SEL(mutableBytes, "mutableBytes");
        _NS_PRIVATE_EXTERN_SEL(name, "name");
        _NS_PRIVATE_EXTERN_SEL(nextObject, "nextObject");
        _NS_PRIVATE_EXTERN_SEL(numberWithBool_, "numberWithBool:");
        _NS_PRIVATE_EXTERN_SEL(numberWithChar_, "numberWithChar:");
        _NS_PRIVATE_EXTERN_SEL(numberWithDouble_, "numberWithDouble:");
        _NS_PRIVATE_EXTERN_SEL(numberWithFloat_, "numberWithFloat:");
        _NS_PRIVATE_EXTERN_SEL(numberWithInt_, "numberWithInt:");
        _NS_PRIVATE_EXTERN_SEL(numberWithLong_, "numberWithLong:");
        _NS_PRIVATE_EXTERN_SEL(numberWithLongLong_, "numberWithLongLong:");
        _NS_PRIVATE_EXTERN_SEL(numberWithShort_, "numberWithShort:");
        _NS_PRIVATE_EXTERN_SEL(numberWithUnsignedChar_, "numberWithUnsignedChar:");
        _NS_PRIVATE_EXTERN_SEL(numberWithUnsignedInt_, "numberWithUnsignedInt:");
        _NS_PRIVATE_EXTERN_SEL(numberWithUnsignedLong_, "numberWithUnsignedLong:");
        _NS_PRIVATE_EXTERN_SEL(numberWithUnsignedLongLong_, "numberWithUnsignedLongLong:");
        _NS_PRIVATE_EXTERN_SEL(numberWithUnsignedShort_, "numberWithUnsignedShort:");
        _NS_PRIVATE_EXTERN_SEL(objCType, "objCType");
        _NS_PRIVATE_EXTERN_SEL(object, "object");
        _NS_PRIVATE_EXTERN_SEL(objectAtIndex_, "objectAtIndex:");
        _NS_PRIVATE_EXTERN_SEL(objectEnumerator, "objectEnumerator");
        _NS_PRIVATE_EXTERN_SEL(objectForInfoDictionaryKey_, "objectForInfoDictionaryKey:");
        _NS_PRIVATE_EXTERN_SEL(objectForKey_, "objectForKey:");
        _NS_PRIVATE_EXTERN_SEL(operatingSystem, "operatingSystem");
        _NS_PRIVATE_EXTERN_SEL(operatingSystemVersion, "operatingSystemVersion");
        _NS_PRIVATE_EXTERN_SEL(operatingSystemVersionString, "operatingSystemVersionString");
        _NS_PRIVATE_EXTERN_SEL(pathForAuxiliaryExecutable_, "pathForAuxiliaryExecutable:");
        _NS_PRIVATE_EXTERN_SEL(performActivityWithOptions_reason_usingBlock_, "performActivityWithOptions:reason:usingBlock:");
        _NS_PRIVATE_EXTERN_SEL(performExpiringActivityWithReason_usingBlock_, "performExpiringActivityWithReason:usingBlock:");
        _NS_PRIVATE_EXTERN_SEL(physicalMemory, "physicalMemory");
        _NS_PRIVATE_EXTERN_SEL(pointerValue, "pointerValue");
        _NS_PRIVATE_EXTERN_SEL(preflightAndReturnError_, "preflightAndReturnError:");
        _NS_PRIVATE_EXTERN_SEL(privateFrameworksPath, "privateFrameworksPath");
        _NS_PRIVATE_EXTERN_SEL(privateFrameworksURL, "privateFrameworksURL");
        _NS_PRIVATE_EXTERN_SEL(processIdentifier, "processIdentifier");
        _NS_PRIVATE_EXTERN_SEL(processInfo, "processInfo");
        _NS_PRIVATE_EXTERN_SEL(processName, "processName");
        _NS_PRIVATE_EXTERN_SEL(processorCount, "processorCount");
        _NS_PRIVATE_EXTERN_SEL(rangeOfString_options_, "rangeOfString:options:");
        _NS_PRIVATE_EXTERN_SEL(release, "release");
        _NS_PRIVATE_EXTERN_SEL(removeObserver_, "removeObserver:");
        _NS_PRIVATE_EXTERN_SEL(resourcePath, "resourcePath");
        _NS_PRIVATE_EXTERN_SEL(resourceURL, "resourceURL");
        _NS_PRIVATE_EXTERN_SEL(respondsToSelector_, "respondsToSelector:");
        _NS_PRIVATE_EXTERN_SEL(retain, "retain");
        _NS_PRIVATE_EXTERN_SEL(retainCount, "retainCount");
        _NS_PRIVATE_EXTERN_SEL(setAutomaticTerminationSupportEnabled_, "setAutomaticTerminationSupportEnabled:");
        _NS_PRIVATE_EXTERN_SEL(setProcessName_, "setProcessName:");
        _NS_PRIVATE_EXTERN_SEL(sharedFrameworksPath, "sharedFrameworksPath");
        _NS_PRIVATE_EXTERN_SEL(sharedFrameworksURL, "sharedFrameworksURL");
        _NS_PRIVATE_EXTERN_SEL(sharedSupportPath, "sharedSupportPath");
        _NS_PRIVATE_EXTERN_SEL(sharedSupportURL, "sharedSupportURL");
        _NS_PRIVATE_EXTERN_SEL(shortValue, "shortValue");
        _NS_PRIVATE_EXTERN_SEL(showPools, "showPools");
        _NS_PRIVATE_EXTERN_SEL(signal, "signal");
        _NS_PRIVATE_EXTERN_SEL(string, "string");
        _NS_PRIVATE_EXTERN_SEL(stringValue, "stringValue");
        _NS_PRIVATE_EXTERN_SEL(stringWithString_, "stringWithString:");
        _NS_PRIVATE_EXTERN_SEL(stringWithCString_encoding_, "stringWithCString:encoding:");
        _NS_PRIVATE_EXTERN_SEL(stringByAppendingString_, "stringByAppendingString:");
        _NS_PRIVATE_EXTERN_SEL(stringByResolvingSymlinksInPath, "stringByResolvingSymlinksInPath");
        _NS_PRIVATE_EXTERN_SEL(systemUptime, "systemUptime");
        _NS_PRIVATE_EXTERN_SEL(thermalState, "thermalState");
        _NS_PRIVATE_EXTERN_SEL(unload, "unload");
        _NS_PRIVATE_EXTERN_SEL(unlock, "unlock");
        _NS_PRIVATE_EXTERN_SEL(unsignedCharValue, "unsignedCharValue");
        _NS_PRIVATE_EXTERN_SEL(unsignedIntegerValue, "unsignedIntegerValue");
        _NS_PRIVATE_EXTERN_SEL(unsignedIntValue, "unsignedIntValue");
        _NS_PRIVATE_EXTERN_SEL(unsignedLongValue, "unsignedLongValue");
        _NS_PRIVATE_EXTERN_SEL(unsignedLongLongValue, "unsignedLongLongValue");
        _NS_PRIVATE_EXTERN_SEL(unsignedShortValue, "unsignedShortValue");
        _NS_PRIVATE_EXTERN_SEL(URLForAuxiliaryExecutable_, "URLForAuxiliaryExecutable:");
        _NS_PRIVATE_EXTERN_SEL(userInfo, "userInfo");
        _NS_PRIVATE_EXTERN_SEL(userName, "userName");
        _NS_PRIVATE_EXTERN_SEL(UTF8String, "UTF8String");
        _NS_PRIVATE_EXTERN_SEL(valueWithBytes_objCType_, "valueWithBytes:objCType:");
        _NS_PRIVATE_EXTERN_SEL(valueWithPointer_, "valueWithPointer:");
        _NS_PRIVATE_EXTERN_SEL(wait, "wait");
        _NS_PRIVATE_EXTERN_SEL(waitUntilDate_, "waitUntilDate:");
    }
}