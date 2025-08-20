#include "String.h"

#include "Defines/Types.h"

#include "Templates/Array.h"

#include "SmartPointer/MakeAndCasts.h"

#include "Memory/Memory.h"

#include <stdlib.h>
#include <string_view>
#include <cassert>
#include <cwchar>

const char* CString::_empty = "";

void CString::CopyStr(const char* CStr, SizeT Len)
{
    if (CStr == nullptr || Len == 0)
    {
        BufferPtr = nullptr;
        Length = 0;
    }

    const SizeT NewLength = Len + 1;
    char* NewBuffer = new char[NewLength];
    GMemory.Copy(CStr, NewBuffer, sizeof(char) * Len);
    NewBuffer[Len] = '\0';

    BufferPtr = MakeShareable<char, SArrayDeleter<char>>(NewBuffer);
    Length = Len;
}

SizeT CString::StrLen(const char* Buffer) const
{
    if (Buffer == nullptr) return 0;

    return std::strlen(Buffer);
}

#if PLATFORM_WINDOWS

void CString::CopyStr(const wchar_t* CWStr, SizeT Len)
{
    if (CWStr == nullptr || Len == 0)
    {
        BufferPtr = nullptr;
        Length = 0;
    }

    char* NewBuffer = new char[Len + 1];

    UInt64 Index = 0;
    UInt64 Remaining = Len;
    while (Index + Remaining < Len)
    {
        SizeT ConvertedSize = 0;
        char ConvertedChars[1024];
        errno_t Err = wcstombs_s(&ConvertedSize, ConvertedChars, CWStr + Index, 1024);

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
    
    NewBuffer[Len] = '\0';

    BufferPtr = MakeShareable<char, SArrayDeleter<char>>(NewBuffer);
    Length = Len;
}

SizeT CString::StrLen(const wchar_t* Buffer) const
{
    if (Buffer == nullptr) return 0;

    return std::wcslen(Buffer);
}

#endif // PLATFORM_WINDOWS

bool CString::Contains(const char* CStr, SizeT Len) const
{
    for (UInt64 Index = 0; Index <= Length - Len; ++Index)
    {
        if (GMemory.Equal(BufferPtr + Index, Len, CStr, Len))
        {
            return true;
        }
    }

    return false;
}

const char* CString::Empty() 
{
    return _empty;
}

CString::CString()
:   Length(0)
,   BufferPtr(nullptr)
{
    //
}

CString::CString(const CString& Other)
:   Length(Other.Length)
,   BufferPtr(Other.BufferPtr)
{
    
}

CString::CString(const char* CStr)
:   CString()
{
    CopyStr(CStr, StrLen(CStr));
}

CString::CString(const char* CStr, SizeT Len) 
:   CString()
{
    CopyStr(CStr, Len);
}

#if PLATFORM_WINDOWS
CString::CString(const wchar_t* CWStr)
:   CString()
{
    CopyStr(CWStr, StrLen(CWStr));
}

CString::CString(const wchar_t* CWStr, SizeT Len)
:   CString()
{
    CopyStr(CWStr, Len);
}
#endif

SizeT CString::Len() const
{
    return Length;
}

bool CString::IsEmpty() const
{
    return Length == 0;
}

bool CString::Contains(const char* CStr) const
{
    return Contains(CStr, StrLen(CStr));
}

bool CString::Contains(const CString& Other) const
{
    return Contains(*Other, Other.Length);
}

Int64 CString::LastIndexOf(const char Char) const
{
    for (UInt64 Index = Length - 1; Index >= 0; --Index)
    {
        if (BufferPtr[Index] == Char)
        {
            return Index;
        }
    }

    return -1;
}

CString CString::SubString(UInt64 Start) const
{
    return SubString(Start, Length - 1);
}

CString CString::SubString(UInt64 Start, UInt64 End) const
{
    const SizeT NewLength = End - Start;
    return CString(BufferPtr + Start, NewLength);
}

CString CString::Replace(const char OldChar, const char NewChar) const
{
    CString NewStr(BufferPtr.Raw(), Length);

    for (UInt64 Index = 0; Index < NewStr.Length; ++Index)
    {
        if (NewStr.BufferPtr[Index] == OldChar)
        {
            NewStr.BufferPtr[Index] = NewChar;
        }
    }

    return NewStr;
}

CString CString::Replace(const char* OldCStr, const char* NewCStr) const
{
    CString Builder = "";

    SizeT OldStrLen = StrLen(OldCStr);

    UInt64 LastCopyed = 0;
    for (UInt64 Index = 0; Index <= Length - OldStrLen; ++Index)
    {
        if (GMemory.Equal(BufferPtr + Index, OldStrLen, OldCStr, OldStrLen))
        {
            if (Index > LastCopyed)
            {
                Builder += SubString(LastCopyed, Index);
            }

            Builder += NewCStr;
            LastCopyed = Index + OldStrLen;
            Index = LastCopyed;
        }
    }

    if (LastCopyed < Length)
    {
        Builder += SubString(LastCopyed, Length);
    }

    return Builder;
}

CString CString::Replace(const CString& OldStr, const CString& NewStr) const
{
    return Replace(OldStr.BufferPtr.Raw(), NewStr.BufferPtr.Raw());
}

TArray<CString> CString::Split(const char Separator) const
{
    TArray<CString> Results;
    Int64 LastFoundSeparator = 0;
    for (UInt64 Index = 0; Index < Length; Index++)
    {
        if (BufferPtr[Index] == Separator)
        {
            Results.Add(SubString(LastFoundSeparator, Index));
            LastFoundSeparator = Index + 1;
        }
    }

    if (LastFoundSeparator != 0)
    {
        Results.Add(SubString(LastFoundSeparator, Length));
    }

    return Results;
}

bool CString::StartsWith(const CString& Other) const
{
    if (Other.Length > Length) return false;

    return GMemory.Equal(BufferPtr.Raw(), Other.Length, Other.BufferPtr.Raw(), Other.Length);
}

bool CString::EndsWith(const CString& Other) const
{
    if (Other.Length > Length) return false;

    return GMemory.Equal(BufferPtr + -Other.Length, Other.Length, Other.BufferPtr.Raw(), Other.Length);
}

char CString::LastChar() const
{
    return BufferPtr[Length - 1];
}

SizeT CString::Hash() const
{
    SizeT Hash = 14695981039346656037ULL; // 64-bit FNV offset basis
    constexpr SizeT FnvPrime = 1099511628211ULL;
    
    char* Buffer = BufferPtr.Raw();

    while (*Buffer) {
        Hash ^= static_cast<SizeT>(*Buffer++);
        Hash *= FnvPrime;
    }

    return Hash;
}

CWString CString::WStr() const
{
    char* CStr = BufferPtr.Raw();

    wchar_t* NewBuffer = new wchar_t[Length + 1];

    UInt64 Index = 0;
    UInt64 Remaining = Length;
    while (Index + Remaining < Length)
    {
        SizeT ConvertedSize = 0;
        wchar_t ConvertedChars[1024];
        errno_t Err = mbstowcs_s(&ConvertedSize, ConvertedChars, CStr + Index, 1024);

        if (Err == 0)
        {
            GMemory.Copy(ConvertedChars, NewBuffer + Index, ConvertedSize * sizeof(char));

            Index += ConvertedSize;
            Remaining -= ConvertedSize;
        }
        else
        {
            throw "Failed to convert char string to wchar string";
        }
    }
    
    NewBuffer[Length] = L'\0';

    return MakeShareable<wchar_t, SArrayDeleter<wchar_t>>(NewBuffer);
}

CString& CString::operator+=(const CString& Other)
{
    return *this = CString("{}{}", BufferPtr.Raw(), Other.BufferPtr.Raw());
}

CString& CString::operator+=(const char* CStr)
{
    return *this = CString("{}{}", BufferPtr.Raw(), CStr);
}

CString& CString::operator+=(char Char)
{
    return *this = CString("{}{}", BufferPtr.Raw(), Char);
}

CString CString::operator+(const CString& Other) const
{
    return CString("{}{}", BufferPtr.Raw(), Other.BufferPtr.Raw());
}

CString CString::operator+(const char* CStr) const
{
    return CString("{}{}", BufferPtr.Raw(), CStr);
}

CString CString::operator+(char Char) const
{
    return CString("{}{}", BufferPtr.Raw(), Char);
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
    BufferPtr = Other.BufferPtr;
    Length = Other.Length;

    return *this;
}

CString& CString::operator=(char* CStr)
{
    CopyStr(CStr, StrLen(CStr));

    return *this;
}

CString& CString::operator=(const char* CStr)
{
    CopyStr(CStr, StrLen(CStr));

    return *this;
}

#if PLATFORM_WINDOWS
CString& CString::operator=(wchar_t* WStr)
{
    CopyStr(WStr, StrLen(WStr));

    return *this;
}

CString& CString::operator=(const wchar_t* CWStr)
{
    CopyStr(CWStr, StrLen(CWStr));

    return *this;
}
#endif // PLATFORM_WINDOWS

bool CString::operator==(const CString& Other) const
{
    if (!BufferPtr || !Other.BufferPtr) return false;
    return std::string_view(BufferPtr.Raw(), Length) == std::string_view(Other.BufferPtr.Raw(), Other.Length);
}

bool CString::operator==(const char* InCStr) const
{
    if (!BufferPtr || !InCStr) return false;
    return std::string_view(BufferPtr.Raw(), Length) == std::string_view(InCStr);
}

CString operator+(const char* Lhs, const CString& Rhs)
{
    return CString("%s%s", Lhs, *Rhs);
}

char CString::operator[](UInt64 Index) const
{
    return BufferPtr[Index];
}

char* CString::operator*() const
{
    return BufferPtr.Raw();
}