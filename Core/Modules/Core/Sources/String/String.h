#pragma once

#include "Templates/String/StringTemplate.h"

#include <format>

class CWString;

class CString : public TString<char, CString>
{
	using Super = TString<char, CString>;

protected:
    SizeT StrLen(const char* Buffer) const override;

public:
	CORE_API CString();
	CORE_API CString(const CString& Other);
	CORE_API CString(const char* CStr);
	CORE_API CString(const char* CStr, SizeT Len);
	
#if PLATFORM_WINDOWS
	CORE_API CString(const wchar_t* WStr, SizeT WStrLen);
#endif // PLATFORM_WINDOWS

	template<
		typename ... TArgs
	>
	explicit CString(const char* CStr, TArgs ... Args) : CString()
	{
		std::string Formatted = std::vformat(CStr, std::make_format_args(Args...));
		BufferPtr = CopyStr(Formatted.c_str(), Formatted.size());
	}

	CORE_API ~CString() override = default;

	CORE_API CString& operator+=(const CString& Other);
	CORE_API CString& operator+=(const char* CStr);
	CORE_API CString& operator+=(char Char);
	CORE_API CString operator+(const CString& Other) const;
	CORE_API CString operator+(const char* CStr) const;
	CORE_API CString operator+(char Char) const;
	CORE_API bool operator >(const CString& Other) const;
	CORE_API bool operator <(const CString& Other) const;
	CORE_API CString& operator=(const CString& Other);
	CORE_API CString& operator=(char* CStr);
	CORE_API CString& operator=(const char* CStr);
	CORE_API bool operator==(const CString& Other) const;
	CORE_API bool operator==(const char* InCStr) const;
};

CORE_API CString operator+(const char* Lhs, const CString& Rhs);