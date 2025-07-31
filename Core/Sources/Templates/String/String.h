#pragma once

#include "StringTemplate.h"
#include "Templates/Array.h"

#include <cstring>
#include <string>
#include <format>
#include <cwchar>

class CWString;

class CString : public TString<char, CString>
{
	using Super = TString<char, CString>;
	using ArrayDeleter = SArrayDeleter<char>;

protected:
    SSizeT StrLen(const char* Buffer) const override
    {
        return std::strlen(Buffer);
    }

public:
	inline CString() : Super()
	{
		//
	}

	inline CString(const CString& Other) : Super(Other)
	{
		//
	}

	inline CString(char* CStr, UInt64 Len) : Super(CStr, Len)
	{
		//
	}

	inline CString(const char* CStr, UInt64 Len) : Super(CStr, Len)
	{
		//
	}

	inline CString(const char* CStr) : Super(CStr, std::strlen(CStr))
	{
		//
	}
	
	inline CString(const wchar_t* WStr)
	{
        SSizeT WStrLen = wcslen(WStr);
        char* NewBuffer = new char[WStrLen + 1];
		wcstombs(NewBuffer, WStr, WStrLen);
		NewBuffer[WStrLen] = '\0';

		BufferPtr = MakeShareable<char, ArrayDeleter>(NewBuffer);
        Length = WStrLen;
	}

	template<
		typename ... TArgs
	>
	inline explicit CString(const char* CStr, TArgs ... Args) : CString()
	{
		std::string Formatted = std::vformat(CStr, std::make_format_args(Args...));
		BufferPtr = CopyStr(Formatted.c_str(), Formatted.size());
	}

	inline ~CString() override = default;

	void Destroy() { }

	inline CString& operator += (const CString& Other)
	{
		return *this = CString("{}{}", BufferPtr.Raw(), Other.BufferPtr.Raw());
	}

	inline CString operator+(const CString& Other) const
	{
		return CString("{}{}", BufferPtr.Raw(), Other.BufferPtr.Raw());
	}

	inline CString operator+(const char* CStr) const
	{
		return CString("{}{}", BufferPtr.Raw(), CStr);
	}

	inline bool operator >(const CString& Other) const
	{
		return Length > Other.Length;
	}

	inline bool operator <(const CString& Other) const
	{
		return Length < Other.Length;
	}

	inline CString& operator=(const CString& Other)
	{
		BufferPtr = Other.BufferPtr;
		Length = Other.Length;

		return *this;
	}

	inline CString& operator=(char* CStr)
	{
		Length = strlen(CStr);
		BufferPtr = CopyStr(CStr, Length);

		return *this;
	}

	inline CString& operator=(const char* CStr)
	{
		Length = strlen(CStr);
		BufferPtr = CopyStr(CStr, Length);

		return *this;
	}

	inline bool operator==(const CString& Other) const
	{
		if (!BufferPtr || !Other.BufferPtr) return false;
		return std::string_view(BufferPtr.Raw(), Length) == std::string_view(Other.BufferPtr.Raw(), Other.Length);
	}

	inline bool operator==(const char* InCStr) const
	{
		if (!BufferPtr || !InCStr) return false;
		return std::string_view(BufferPtr.Raw(), Length) == std::string_view(InCStr);
	}
};