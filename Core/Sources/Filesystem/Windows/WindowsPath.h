#pragma once

#include "CoreDefinitions.h"

#if PLATFORM_WINDOWS

#include "Filesystem/Path.h"

class CWindowsPath : public IPath
{
	CORE_API static CString FixPath(const CString& Path);

public:
	CORE_API CWindowsPath() = default;
	CORE_API ~CWindowsPath() override = default;

	CORE_API CString Combine(const TArray<CString>& PathComponents) const override;
	CORE_API CString RemoveLastPathComponent(const CString& Path) const override;
};

typedef CWindowsPath CPlatformPath;

#endif // PLATFORM_WINDOWS