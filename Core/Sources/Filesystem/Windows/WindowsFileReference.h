#pragma once

#include "Defines/PlatformInfo.h"

#if PLATFORM_WINDOWS

#include "Filesystem/FileReference.h"
#include "Templates/String/WString.h"

class CWindowsFileReference : public CFileReference
{
    using Super = CFileReference;

    CWString _pathW;

    CORE_API void UpdateExistance() override;

public:
    explicit CORE_API CWindowsFileReference(const CString& InPath);
    CORE_API ~CWindowsFileReference() override = default;
};

typedef CWindowsFileReference CPlatformFileReference;

#endif // PLATFORM_WINDOWS