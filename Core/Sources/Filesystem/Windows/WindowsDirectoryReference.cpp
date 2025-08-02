#include "WindowsDirectoryReference.h"

#if PLATFORM_WINDOWS

#include "Filesystem/Path.h"

#include <Windows.h>

void CWindowsDirectoryReference::UpdateExistance()
{
	DWORD Attrs = GetFileAttributes(*_pathW);
	
	_bExists = Attrs != INVALID_FILE_ATTRIBUTES && (Attrs & FILE_ATTRIBUTE_DIRECTORY);
}

CWindowsDirectoryReference::CWindowsDirectoryReference(const CString& InPath) : Super(InPath)
,	_pathW(*InPath, InPath.Len())
{	
	UpdateExistance();
}

bool CWindowsDirectoryReference::Create(bool InCreateIntermediates)
{
	return CreateDirectory(*_pathW, NULL);
}

bool CWindowsDirectoryReference::Delete()
{
	return RemoveDirectory(*_pathW);
}

SDirectoryRef CWindowsDirectoryReference::Combine(const CString& InComponent) const
{
	return GPath.Combine({ _path, InComponent });
}

SDirectoryRef CWindowsDirectoryReference::Combine(const TArray<CString>& InComponents) const
{
	TArray<CString> NewArray(InComponents);
	NewArray.Insert(0, _path);
	
	return GPath.Combine(NewArray);
}

SFileRef CWindowsDirectoryReference::CombineFile(const CString& InFilename) const
{
	return GPath.Combine({ _path, InFilename });
}

SFileRef CWindowsDirectoryReference::CombineFile(const TArray<CString>& InComponents) const
{
	TArray<CString> NewArray(InComponents);
	NewArray.Insert(0, _path);
	
	return GPath.Combine(NewArray);
}

#endif // PLATFORM_WINDOWS