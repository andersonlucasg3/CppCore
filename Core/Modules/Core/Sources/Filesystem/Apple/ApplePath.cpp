#include "ApplePath.h"

#include "Templates/Array.h"

#include "Process/Mac/MacProcess.h"

#include "String/Apple/AppleStringConvertion.h"

#include "NSFileManager.h"
#include "NSError.h"
#include "NSURL.h"

char CApplePath::PathSeparator() const
{
    return '/';
}

CString CApplePath::GetFullPath(const CString& InPath) const
{
    CString Path = InPath;

    if (Path.IsEmpty())
    {
        return Path;
    }

    if (Path[0] != '/')
    {
        const CString& WorkingDirectory = GProcess.GetContainerPath();
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

const CString& CApplePath::CachesPath() const
{
    static CString CachesPath = []
    {
        if (GMacProcess.IsRunningOnAppBundle())
        {
            NS::Error* Error = nullptr;

            NS::URL* CachesDirectory = NS::FileManager::defaultManager()->urlForDirectory(NS::CachesDirectory, NS::UserDomainMask, nullptr, true, &Error);

            return CString(CachesDirectory->fileSystemRepresentation());
        }
        else
        {
            return GPath.Combine({
                GMacProcess.GetContainerPath(),
                "Caches",
            });
        }
    }();
    return CachesPath;
}
