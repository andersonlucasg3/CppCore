#include "String.h"

SizeT CString::StrLen(const char* Buffer) const
{
    return std::strlen(Buffer);
}

CString::CString() : Super()
{
    //
}

CString::CString(const CString& Other) : Super(Other)
{
    //
}

CString::CString(const char* CStr) : Super(CStr, std::strlen(CStr))
{
    //
}

CString::CString(const char* CStr, SizeT Len) : Super(CStr, Len)
{
    //
}

#if PLATFORM_WINDOWS
CString::CString::CString(const wchar_t* WStr, SizeT WStrLen)
{
    char* NewBuffer = new char[WStrLen + 1];

    UInt64 Index = 0;
    UInt64 Remaining = WStrLen;
    while (Index + Remaining < WStrLen)
    {
        SizeT ConvertedSize = 0;
        char ConvertedChars[1024];
        errno_t Err = wcstombs_s(&ConvertedSize, ConvertedChars, WStr + Index, 1024);

        if (Err == 0)
        {
            GMemory.Copy(ConvertedChars, NewBuffer + Index, ConvertedSize * sizeof(char));

            Index += ConvertedSize;
            Remaining -= ConvertedSize;
        }
        else
        {
            throw "Failed to convert wchar string to char string";
        }
    }
    
    NewBuffer[WStrLen] = '\0';

    BufferPtr = NewBuffer;
    Length = WStrLen;
}
#endif

CString& CString::operator+=(const CString& Other)
{
    return *this = CString("{}{}", BufferPtr, Other.BufferPtr);
}

CString& CString::operator+=(const char* CStr)
{
    return *this = CString("{}{}", BufferPtr, CStr);
}

CString& CString::operator+=(char Char)
{
    return *this = CString("{}{}", BufferPtr, Char);
}

CString CString::operator+(const CString& Other) const
{
    return CString("{}{}", BufferPtr, Other.BufferPtr);
}

CString CString::operator+(const char* CStr) const
{
    return CString("{}{}", BufferPtr, CStr);
}

CString CString::operator+(char Char) const
{
    return CString("{}{}", BufferPtr, Char);
}

bool CString::operator >(const CString& Other) const
{
    return Length > Other.Length;
}

bool CString::operator <(const CString& Other) const
{
    return Length < Other.Length;
}

CString& CString::operator=(const CString& Other)
{
    Length = Other.Length;
    BufferPtr = CopyStr(Other.BufferPtr, Length);

    return *this;
}

CString& CString::operator=(char* CStr)
{
    Length = strlen(CStr);
    BufferPtr = CopyStr(CStr, Length);

    return *this;
}

CString& CString::operator=(const char* CStr)
{
    Length = strlen(CStr);
    BufferPtr = CopyStr(CStr, Length);

    return *this;
}

bool CString::operator==(const CString& Other) const
{
    if (!BufferPtr || !Other.BufferPtr) return false;
    return std::string_view(BufferPtr, Length) == std::string_view(Other.BufferPtr, Other.Length);
}

bool CString::operator==(const char* InCStr) const
{
    if (!BufferPtr || !InCStr) return false;
    return std::string_view(BufferPtr, Length) == std::string_view(InCStr);
}

CString operator+(const char* Lhs, const CString& Rhs)
{
    return CString("%s%s", Lhs, *Rhs);
}