#pragma once

#include "NSObject.hpp"
#include "NSDictionary.h"
#include "NSString.h"
#include "NSError.h"
#include "NSURL.h"

namespace NS
{
    _NS_ENUM(NS::UInteger, SearchPathDirectory) {
        ApplicationDirectory = 1,
        LibraryDirectory = 5,
        UserDirectory = 7,
        DocumentDirectory = 9,
        CachesDirectory = 13,
    };

    _NS_ENUM(NS::UInteger, SearchPathDomainMask) {
        UserDomainMask = 1,
        LocalDomainMask = 2,
        NetworkDomainMask = 4,
        SystemDomainMask = 8,
        AllDomainsMask = 0x0FFFF,
    };

    class FileManager : Referencing<FileManager>
    {
    public:
        static FileManager *defaultManager();

        NS::URL* urlForDirectory(NS::SearchPathDirectory directory, NS::SearchPathDomainMask domain, NS::URL* appropriateForURL, bool shouldCreate, NS::Error** error) const;
        bool createDirectoryAtPath(NS::String* path, bool withIntermediateDirectories, NS::Dictionary* attributes, NS::Error** error) const;
        bool createDirectoryAtURL(NS::URL* url, bool withIntermediateDirectories, NS::Dictionary* attributes, NS::Error** error) const;
        bool removeItemAtPath(NS::String* path, NS::Error** error) const;
        bool removeItemAtURL(NS::URL* url, NS::Error **error) const;
        bool fileExistsAtPath(NS::String* path) const;
        bool fileExistsAtPath(NS::String* path, bool* isDirectory) const;
    };
}