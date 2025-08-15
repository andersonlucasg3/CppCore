#pragma once

#include "Templates/Hashable.h"

#include "Memory/Memory.h"

#include <cstring>

template <typename TElement>
class TArray;

template<
	typename TChar,
	typename TDerived
>
class TString : public CHashable
{
protected:
	// TODO: change this to unique ptr maybe?
	TChar* BufferPtr;
	UInt64 Length;

	inline TChar* CopyStr(const TChar* CStr, UInt64 Len)
	{
		const UInt64 NewLength = Len + 1;
		TChar* NewBuffer = new TChar[NewLength];
		GMemory.Copy(CStr, NewBuffer, sizeof(TChar) * Len);
		NewBuffer[Len] = '\0';
		Length = Len;
		return NewBuffer;
	}

	inline virtual SizeT StrLen(const TChar* Buffer) const = 0;

public:
	inline TString() :
		BufferPtr(nullptr),
		Length(0)
	{
		//
	}

	inline TString(const TString& Other) :
		BufferPtr(CopyStr(Other.BufferPtr, Other.Length)),
		Length(Other.Length)
	{
		//
	}

	inline TString(const TChar* CStr, SizeT Len) :
		BufferPtr(CopyStr(CStr, Len)),
		Length(Len)
	{
		//
	}

	inline TString(TChar* CStr, SizeT Len) :
		BufferPtr(CopyStr(CStr, Len)),
		Length(Len)
	{
		//
	}

	inline virtual ~TString()
	{
		if (BufferPtr != nullptr)
		{
			delete[] BufferPtr;
			BufferPtr = nullptr;
		}
	}

	inline SizeT Len() const
	{
		return Length;
	}

	inline bool Contains(const TChar* Char) const
	{
		UInt64 SearchingStrLen = StrLen(Char);

		for (UInt64 Index = 0; Index <= Length - SearchingStrLen; ++Index)
		{
			if (GMemory.Equal(BufferPtr + Index, SearchingStrLen, Char, SearchingStrLen))
			{
				return true;
			}
		}

		return false;
	}

	inline Int64 LastIndexOf(const TChar Char) const
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

	inline const TDerived SubString(UInt64 Start) const
	{
		return SubString(Start, Length - 1);
	}

	inline const TDerived SubString(UInt64 Start, UInt64 End) const
	{
		const UInt64 NewLength = End - Start + 1;
		TChar* NewBuffer = new TChar[NewLength];
		GMemory.Copy(BufferPtr + Start, NewBuffer, sizeof(TChar) * (NewLength - 1));
		NewBuffer[NewLength - 1] = '\0';
        return TDerived(NewBuffer, NewLength - 1);
	}

	inline const TDerived Replace(const TChar OldChar, const TChar NewChar) const
	{
		TDerived NewStr = **this;

		for (UInt32 Index = 0; Index < NewStr.Length; ++Index)
		{
			if (NewStr.BufferPtr[Index] == OldChar)
			{
				NewStr.BufferPtr[Index] = NewChar;
			}
		}

		return NewStr;
	}

	inline const TDerived Replace(const TChar* OldStr, const TChar* NewStr) const
	{
		TDerived Builder = "";

		UInt64 OldStrLen = StrLen(OldStr);

		UInt64 LastCopyed = 0;
		for (UInt64 Index = 0; Index <= Length - OldStrLen; ++Index)
		{
			if (GMemory.Equal(BufferPtr + Index, OldStrLen, OldStr, OldStrLen))
			{
				if (Index > LastCopyed)
				{
					Builder += SubString(LastCopyed, Index);
				}

				Builder += NewStr;
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

	inline const TDerived Replace(const TString& OldStr, const TString& NewStr) const
	{
		return Replace(OldStr.BufferPtr, NewStr.BufferPtr);
	}

	inline TArray<TDerived> Split(const char Separator) const
	{
		TArray<TDerived> Results;
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

	inline bool IsEmpty() const
	{
		return Length == 0;
	}

	inline bool StartsWith(const TDerived& Other) const
	{
		if (Other.Length > Length) return false;

		return GMemory.Equal(BufferPtr, Other.Length, Other.BufferPtr, Other.Length);
	}

	inline bool EndsWith(const TDerived& Other) const
	{
		if (Other.Length > Length) return false;

		return GMemory.Equal(BufferPtr - Other.Length, Other.Length, Other.BufferPtr, Other.Length);
	}

	inline TChar LastChar() const
	{
		return BufferPtr[Length - 1];
	}

	inline SizeT Hash() const
	{
		SizeT Hash = 14695981039346656037ULL; // 64-bit FNV offset basis
		constexpr SizeT FnvPrime = 1099511628211ULL;
		
		TChar* Buffer = BufferPtr;

		while (*Buffer) {
			Hash ^= static_cast<SizeT>(*Buffer++);
			Hash *= FnvPrime;
		}

		return Hash;
	}

	inline TChar operator[](SizeT InIndex) const
	{
		return BufferPtr[InIndex];
	}

	inline const TChar* operator*() const
	{
		return BufferPtr;
	}
};