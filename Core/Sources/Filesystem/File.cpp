#include "File.h"

#include "Defines/Preprocessors.h"

#include COMPILE_PLATFORM_HEADER(File.h)

CFile::CFile(const CString& InFilePath) :
	FilePath(InFilePath)
{

}

CFilePtr CFile::Create(const CString& FilePath)
{
	CFilePtr File = CPlatformFile::Create(FilePath);
	if (!File->Create()) return CFilePtr();
	return File;
}

CFile* CFile::CreateUnsafe(const char* FilePath)
{
	CFile* FilePtr = CPlatformFile::CreateUnsafe(FilePath);
	if (!FilePtr->Create()) return nullptr;
	return FilePtr;
}

CFilePtr CFile::Open(const CString& FilePath, EOpenMode Mode)
{
	CFilePtr File = CPlatformFile::Create(FilePath);
	if (!File->Open(Mode)) return CFilePtr();
	return File;
}

CFile* CFile::OpenUnsafe(const char* FilePath, EOpenMode Mode)
{
	CFile* FilePtr = CPlatformFile::CreateUnsafe(FilePath);
	if (!FilePtr->Open(Mode)) return nullptr;
	return FilePtr;
}

bool CFile::Delete(const CString& FilePath)
{
	CFilePtr File = CPlatformFile::Create(FilePath);
	return File->Delete();
}

bool CFile::Exists(const CString& FilePath)
{
	return CPlatformFile::Exists(FilePath);
}