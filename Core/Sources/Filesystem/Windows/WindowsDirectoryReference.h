#pragma once

#include "Defines/PlatformInfo.h"

#if PLATFORM_WINDOWS

#include "Filesystem/DirectoryReference.h"

class CWindowsDirectoryReference : public CDirectoryReference
{
	using Super = CDirectoryReference;

	CORE_API void UpdateExistance() override;

public:
	CORE_API CWindowsDirectoryReference(const CString& InPath);
	CORE_API ~CWindowsDirectoryReference() override = default;
};

#endif // PLATFORM_WINDOWS