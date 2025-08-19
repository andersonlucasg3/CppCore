#include "NSFileManager.h"

namespace NS 
{
    FileManager* FileManager::defaultManager()
    {
        return Object::sendMessage<FileManager*>(_NS_PRIVATE_CLS(NSFileManager), _NS_PRIVATE_SEL(defaultManager));
    }

    URL* FileManager::urlForDirectory(SearchPathDirectory directory, SearchPathDomainMask domain, URL* appropriateForURL, bool shouldCreate, Error** error) const
    {
        return Object::sendMessage<URL*>(this, _NS_PRIVATE_SEL(urlForDirectory_inDomain_appropriateForURL_create_error_), directory, domain, appropriateForURL, shouldCreate, error);
    }

    bool FileManager::createDirectoryAtPath(String* path, bool withIntermediateDirectories, Dictionary* attributes, Error** error) const
    {
        return Object::sendMessage<bool>(this, _NS_PRIVATE_SEL(createDirectoryAtPath_withIntermediateDirectories_attributes_error_), path, withIntermediateDirectories, attributes, error);
    }

    bool FileManager::createDirectoryAtURL(URL* url, bool withIntermediateDirectories, Dictionary* attributes, Error** error) const
    {
        return Object::sendMessage<bool>(this, _NS_PRIVATE_SEL(createDirectoryAtURL_withIntermediateDirectories_attributes_error_), url, withIntermediateDirectories, attributes, error);
    }

    bool FileManager::removeItemAtPath(String* path, Error** error) const
    {
        return Object::sendMessage<bool>(this, _NS_PRIVATE_SEL(removeItemAtPath_error_), path, error);
    }

    bool FileManager::removeItemAtURL(URL* url, Error** error) const
    {
        return Object::sendMessage<bool>(this, _NS_PRIVATE_SEL(removeItemAtURL_error_), url, error);
    }

    bool FileManager::fileExistsAtPath(String* path) const
    {
        return Object::sendMessage<bool>(this, _NS_PRIVATE_SEL(fileExistsAtPath_), path);
    }

    bool FileManager::fileExistsAtPath(String* path, bool* isDirectory) const
    {
        return Object::sendMessage<bool>(this, _NS_PRIVATE_SEL(fileExistsAtPath_), path, isDirectory);
    }
}