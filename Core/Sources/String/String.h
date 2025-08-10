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
	inline explicit CString(const char* CStr, TArgs ... Args) : CString()
	{
		std::string Formatted = std::vformat(CStr, std::make_format_args(Args...));
		BufferPtr = CopyStr(Formatted.c_str(), Formatted.size());
	}

	inline ~CString() override = default;

	inline CString& operator+=(const CString& Other);
	inline CString& operator+=(const char* CStr);
	inline CString& operator+=(char Char);
	inline CString operator+(const CString& Other) const;
	inline CString operator+(const char* CStr) const;
	inline CString operator+(char Char) const;
	inline bool operator >(const CString& Other) const;
	inline bool operator <(const CString& Other) const;
	inline CString& operator=(const CString& Other);
	inline CString& operator=(char* CStr);
	inline CString& operator=(const char* CStr);
	inline bool operator==(const CString& Other) const;
	inline bool operator==(const char* InCStr) const;
};

CString operator+(const char* Lhs, const CString& Rhs);