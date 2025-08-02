#pragma once

#include "StringTemplate.h"
#include "Templates/Array.h"

class CWString : public TString<wchar_t, CWString>
{
	using TStr = TString<wchar_t, CWString>;
	using ArrayDeleter = SArrayDeleter<wchar_t>;

protected:
	inline virtual SizeT StrLen(const wchar_t* Buffer) const
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

	inline CWString(const char* CStr, SizeT StrLen)
	{
		wchar_t* NewBuffer = new wchar_t[StrLen + 1];

		UInt64 Index = 0;
		UInt64 Remaining = StrLen;
		while (Index + Remaining < StrLen)
		{
			SizeT ConvertedSize = 0;
			wchar_t ConvertedChars[1024];
			errno_t Err = mbstowcs_s(&ConvertedSize, ConvertedChars, CStr + Index, 1024);

			if (Err == 0)
			{
				GMemory.Copy(ConvertedChars, NewBuffer + Index, ConvertedSize * sizeof(wchar_t));
				
				Index += ConvertedSize;
				Remaining -= ConvertedSize;
			}
			else
			{
				throw "Failed to convert wchar string to char string";
			}
		}
		
		NewBuffer[StrLen] = L'\0';

		BufferPtr = MakeShareable<wchar_t, ArrayDeleter>(NewBuffer);
        Length = StrLen;
	}
};