#include "WindowsFileReference.h"

#if PLATFORM_WINDOWS

#include <Windows.h>

void CWindowsFileReference::UpdateExistance()
{
    DWORD Attrs = GetFileAttributes(*_pathW);

    _bExists = Attrs != INVALID_FILE_ATTRIBUTES && !(Attrs & FILE_ATTRIBUTE_DIRECTORY);
}

CWindowsFileReference::CWindowsFileReference(const CString& InPath) : Super(InPath)
,   _pathW(*InPath, InPath.Len())
{
    UpdateExistance();
}

#endif // PLATFORM_WINDOWS