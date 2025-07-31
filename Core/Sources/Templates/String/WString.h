#pragma once

#include "StringTemplate.h"
#include "Templates/Array.h"

class CWString : public TString<wchar_t, CWString>
{
	using TStr = TString<wchar_t, CWString>;
	using ArrayDeleter = SArrayDeleter<wchar_t>;

protected:
	inline virtual SSizeT StrLen(const wchar_t* Buffer) const
	{
		return wcslen(Buffer);
	}

public:
	inline CWString() : TStr()
	{
		//
	}

	inline CWString(const CWString& Other) : TStr(Other)
	{
		//
	}

	inline CWString(const wchar_t* CStr, UInt64 Len) : TStr(CStr, Len)
	{
		//
	}

	inline CWString(const wchar_t* CStr) : TStr(CStr, wcslen(CStr))
	{
		//
	}

	inline CWString(const char* CStr)
	{
		SSizeT StrLen = strlen(CStr);
		wchar_t* NewBuffer = new wchar_t[StrLen + 1];
        mbstowcs(NewBuffer, CStr, StrLen);
        NewBuffer[StrLen] = L'\0';
        
		BufferPtr = MakeShareable<wchar_t, ArrayDeleter>(NewBuffer);
		Length = StrLen;
	}
};