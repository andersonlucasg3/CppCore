#include "WindowsPath.h"

#if PLATFORM_WINDOWS

CString CWindowsPath::FixPath(const CString& Path)
{
    return Path.Replace('/', '\\');
}

CString CWindowsPath::Combine(const TArray<CString>& PathComponents) const
{
    CString FullPath = FixPath(PathComponents[0]);
    for (UInt32 Index = 1; Index < PathComponents.Num(); ++Index)
    {
        FullPath += "\\";
        FullPath += FixPath(PathComponents[Index]);
    }
    return FullPath;
}

CString CWindowsPath::RemoveLastPathComponent(const CString& Path) const
{
    UInt64 LastSlashIndex = Path.LastIndexOf('\\');
    if (LastSlashIndex == -1)
    {
        return Path;
    }
    return Path.SubString(0, LastSlashIndex);
}

#endif // PLATFORM_WINDOWS