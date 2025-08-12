#pragma once

#include "Templates/Array.h"
#include "Templates/String/StringTemplate.h"

class CWString : public TString<wchar_t, CWString>
{
	using Super = TString<wchar_t, CWString>;
	using ArrayDeleter = SArrayDeleter<wchar_t>;

protected:
	SizeT StrLen(const wchar_t* Buffer) const override;

public:
	CWString();
	CWString(const CWString& Other);
	CWString(const wchar_t* CStr);
	CWString(const wchar_t* CStr, UInt64 Len);
	CWString(const char* CStr, SizeT StrLen);
};