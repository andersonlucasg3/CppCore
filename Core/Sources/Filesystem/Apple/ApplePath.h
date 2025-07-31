#pragma once

#include "CoreDefinitions.h"

#if PLATFORM_APPLE

#include "Filesystem/Path.h"

class CApplePath : public CPath
{
    CString _cachesPath;

public:
    CORE_API CApplePath() = default;
    CORE_API ~CApplePath() override = default;

    CORE_API CString GetFullPath(const CString& InPath) const override;
    CORE_API CString GetPathRoot(const CString& InPath) const override;

    CORE_API CString Combine(const TArray<CString>& PathComponents) const override;

    CORE_API CString LastPathComponent(const CString& InPath) const override;
    CORE_API CString RemoveLastPathComponent(const CString& Path) const override;
    
    CORE_API const CString& CachesPath() const override;
};

typedef CApplePath CPlatformPath;

#endif // PLATFORM_APPLE