#pragma once

#include "Templates/String/StringTemplate.h"

#include <string>
#include <cstring>
#include <format>

#if PLATFORM_WINDOWS
#include <cwchar>
#endif // PLATFORM_WINDOWS

class CWString;

class CString : public TString<char, CString>
{
	using Super = TString<char, CString>;

protected:
    SizeT StrLen(const char* Buffer) const override;

public:
	CString();
	CString(const CString& Other);
	CString(char* CStr, UInt64 Len);
	CString(const char* CStr, UInt64 Len);
	CString(const char* CStr);
	
#if PLATFORM_WINDOWS
	CString(const wchar_t* WStr, SizeT WStrLen);
#endif // PLATFORM_WINDOWS

	template<
		typename ... TArgs
	>
	explicit CString(const char* CStr, TArgs ... Args) : CString()
	{
		std::string Formatted = std::vformat(CStr, std::make_format_args(Args...));
		BufferPtr = CopyStr(Formatted.c_str(), Formatted.size());
	}

	~CString() override = default;

	CString& operator+=(const CString& Other);
	CString& operator+=(const char* CStr);
	CString& operator+=(char Char);
	CString operator+(const CString& Other) const;
	CString operator+(const char* CStr) const;
	CString operator+(char Char) const;
	bool operator >(const CString& Other) const;
	bool operator <(const CString& Other) const;
	CString& operator=(const CString& Other);
	CString& operator=(char* CStr);
	CString& operator=(const char* CStr);
	bool operator==(const CString& Other) const;
	bool operator==(const char* InCStr) const;
};

CString operator+(const char* Lhs, const CString& Rhs);