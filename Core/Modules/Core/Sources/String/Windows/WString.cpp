#include "WString.h"

#include "String/String.h"

#include <cstring>

SizeT CWString::StrLen(const wchar_t* Buffer) const
{
    return wcslen(Buffer);
}

CWString::CWString() : Super()
{
    //
}

CWString::CWString(const CWString& Other) : Super(Other)
{
    //
}

CWString::CWString(const CString& CStr) : CWString(*CStr, CStr.Len())
{

}

CWString::CWString(const wchar_t* WCStr) : Super(WCStr, wcslen(WCStr))
{
    //
}

CWString::CWString(const wchar_t* WCStr, UInt64 Len) : Super(WCStr, Len)
{
    //
}

CWString::CWString(const char* CStr) : CWString(CStr, strlen(CStr))
{
    //
}

CWString::CWString(const char* CStr, SizeT StrLen)
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

    BufferPtr = NewBuffer;
    Length = StrLen;
}