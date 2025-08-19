#pragma once

#include "Templates/Array.h"
#include "Templates/String/StringTemplate.h"

class CWString : public TString<wchar_t, CWString>
{
	using Super = TString<wchar_t, CWString>;
	using ArrayDeleter = SArrayDeleter<wchar_t>;

protected:
	CORE_API SizeT StrLen(const wchar_t* Buffer) const override;

public:
	CORE_API CWString();
	CORE_API CWString(const CWString& Other);
	CORE_API CWString(const CString& CStr);
	CORE_API CWString(const wchar_t* WCStr);
	CORE_API CWString(const wchar_t* WCStr, UInt64 Len);
	CORE_API CWString(const char* CStr);
	CORE_API CWString(const char* CStr, SizeT StrLen);
};