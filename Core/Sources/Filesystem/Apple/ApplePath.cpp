#include "ApplePath.h"

#if PLATFORM_APPLE

#include "Templates/String/Apple/AppleStringConvertion.h"
#include "Process/Apple/AppleProcess.h"

#include "Foundation/NSFileManager.hpp"
#include "Foundation/NSError.hpp"
#include "Foundation/NSURL.hpp"

CString CApplePath::GetFullPath(const CString& InPath) const
{
    CString Path = InPath;

    if (Path.IsEmpty())
    {
        return Path;
    }

    if (Path[0] != '/')
    {
        const CString& WorkingDirectory = GProcess.GetExecutableContainerPath();
        Path = GPath.Combine({ WorkingDirectory, InPath });    
    }

    NS::String* FullPathString = CStringToNSString(Path)->stringByResolvingSymlinksInPath();
    
    return CString(FullPathString->fileSystemRepresentation());
}

CString CApplePath::GetPathRoot(const CString& InPath) const
{
    if (InPath.IsEmpty())
    {
        return InPath;
    }

    if (InPath[0] == '/')
    {
        return "/";
    }

    return "";
}

CString CApplePath::Combine(const TArray<CString>& PathComponents) const
{
    CString FullPath = PathComponents[0];
    for (UInt64 Index = 1; Index < PathComponents.Num(); ++Index)
    {
        if (FullPath.IsEmpty() || FullPath.LastChar() != '/')
        {
            FullPath += "/";
        }

        FullPath += PathComponents[Index];
    }
    return FullPath;
}

CString CApplePath::LastPathComponent(const CString& InPath) const
{
    if (InPath.IsEmpty())
    {
        return InPath;
    }

    UInt64 LastSlashIndex = InPath.LastIndexOf('/');
    
    if (LastSlashIndex == -1ul)
    {
        return InPath; // No slashes, return the whole path
    }

    return InPath.SubString(LastSlashIndex + 1);
}

CString CApplePath::RemoveLastPathComponent(const CString& Path) const
{
    UInt64 LastSlashIndex = Path.LastIndexOf('/');
    if (LastSlashIndex == -1ul)
    {
        return Path;
    }
    return Path.SubString(0, LastSlashIndex);
}

const CString& CApplePath::CachesPath() const
{
    static CString CachesPath = []
    {
        if (CAppleProcess::Get().IsRunningOnAppBundle())
        {
            NS::Error* Error = nullptr;

            NS::URL* CachesDirectory = NS::FileManager::defaultManager()->urlForDirectory(NS::CachesDirectory, NS::UserDomainMask, nullptr, true, &Error);

            return CString(CachesDirectory->fileSystemRepresentation());
        }
        else
        {
            return GPath.Combine({
                CAppleProcess::Get().GetExecutableContainerPath(),
                "Caches",
            });
        }
    }();
    return CachesPath;
}

#endif // PLATFORM_APPLE
