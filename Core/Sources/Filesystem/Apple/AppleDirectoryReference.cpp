#include "AppleDirectoryReference.h"

#if PLATFORM_GROUP_APPLE

#include "Filesystem/DirectoryReference.h"
#include "Templates/String/String.h"
#include "Templates/String/Apple/AppleStringConvertion.h"
#include "Filesystem/Apple/AppleFileReference.h"
#include "Filesystem/FileReference.h"
#include "Foundation/NSFileManager.hpp"
#include "Foundation/NSSharedPtr.hpp"

#include <sys/_types/_filesec_t.h>

void CAppleDirectoryReference::UpdateExistance() 
{
    _bExists = NS::FileManager::defaultManager()->fileExistsAtPath(PathString());
}

CAppleDirectoryReference::CAppleDirectoryReference(const CString& InPath) : Super(InPath)
{
    _directoryURL = NS::RetainPtr(NS::URL::fileURLWithPath(CStringToNSString(_path)));

    UpdateExistance();
}

bool CAppleDirectoryReference::Create(bool InCreateIntermediates)
{
    NS::Error* Error = nullptr;
    if (!NS::FileManager::defaultManager()->createDirectoryAtURL(_directoryURL.get(), InCreateIntermediates, nullptr, &Error))
    {
        GLogger.Error("CAppleDirectoryReference::Create(InCreateIntermediates: {}) - Failed to create directory {}", 
            InCreateIntermediates, Error->debugDescription()->utf8String());
        return false;
    }

    UpdateExistance();
    return true;
}

bool CAppleDirectoryReference::Delete()
{
    NS::Error* Error = nullptr;
    if (!NS::FileManager::defaultManager()->removeItemAtURL(_directoryURL.get(), &Error))
    {
        GLogger.Error("CAppleDirectoryReference::Delete() - Failed to delete directory: {}", Error->debugDescription()->utf8String());
        return false;
    }

    UpdateExistance();
    return true;
}

SDirectoryRef CAppleDirectoryReference::Combine(const CString& InComponent) const
{
    return GPath.Combine({ _path, InComponent });
}

SDirectoryRef CAppleDirectoryReference::Combine(const TArray<CString>& InComponents) const
{
    TArray<CString> NewArray(InComponents);
    NewArray.Insert(0, _path);

    return GPath.Combine(NewArray);
}

SFileRef CAppleDirectoryReference::CombineFile(const CString& InFilename) const
{
    return GPath.Combine({ _path, InFilename });
}

SFileRef CAppleDirectoryReference::CombineFile(const TArray<CString>& InComponents) const
{
    TArray<CString> NewArray(InComponents);
    NewArray.Insert(0, _path);

    return GPath.Combine(NewArray);
    
}

NS::String* CAppleDirectoryReference::PathString() const
{
    return _directoryURL->path();
}

NS::URL* CAppleDirectoryReference::PathURL() const
{
    return _directoryURL.get();
}

#endif // PLATFORM_GROUP_APPLE