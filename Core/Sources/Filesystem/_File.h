#pragma once

#include "CoreDefinitions.h"
#include "Templates/String/String.h"
#include "Templates/Array.h"

CORE_CLASS_HEADER(File);

class CFile
{
public:
	enum EOpenMode : UByte
	{
		OpenRead,
		OpenWrite,
		OpenReadWrite
	};

	CORE_API virtual ~CFile() = default;

	CORE_API static CFilePtr Create(const CString& FilePath);
	CORE_API static CFile* CreateUnsafe(const char* FilePath);
	CORE_API static CFilePtr Open(const CString& FilePath, EOpenMode Mode);
	CORE_API static CFile* OpenUnsafe(const char* FilePath, EOpenMode Mode);
	CORE_API static bool Delete(const CString& FilePath);
	CORE_API static bool Exists(const CString& FilePath);

	CORE_API virtual bool Write(const TArray<int8_t>& ByteArray) = 0;
	CORE_API virtual bool Write(const void* Data, SSizeT Size) = 0;
	CORE_API virtual bool Read(TArray<int8_t>& OutByteArray) = 0;
	CORE_API virtual bool Read(void*& OutData, UInt64& Size) = 0;
	CORE_API virtual bool Flush() = 0;
	CORE_API virtual UInt64 GetSize() const = 0;

protected:
	CString FilePath;

	CORE_API virtual bool Create() = 0;
	CORE_API virtual bool Open(EOpenMode Mode) = 0;
	CORE_API virtual bool Delete() = 0;

	CORE_API CFile(const CString& FilePath);
};
