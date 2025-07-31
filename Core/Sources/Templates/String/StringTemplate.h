#pragma once

#include "Memory/Memory.h"
#include "Templates/Array.h"
#include "Templates/Hashable.h"
#include "Templates/SharedPointers.h"
#include <cstring>

template<
	typename TBuffer,
	typename TDerived
>
class TString : public CHashable
{
	using ArrayDeleter = SArrayDeleter<TBuffer>;

protected:
	// TODO: change this to unique ptr maybe?
	TSharedPtr<TBuffer> BufferPtr;
	UInt64 Length;

	inline TSharedPtr<TBuffer> CopyStr(const TBuffer* CStr, UInt64 Len)
	{
		const UInt64 NewLength = Len + 1;
		TBuffer* NewBuffer = new TBuffer[NewLength];
		GMemory.Copy(CStr, NewBuffer, sizeof(TBuffer) * Len);
		NewBuffer[Len] = '\0';
		Length = Len;
		return MakeShareable<TBuffer, ArrayDeleter>(NewBuffer);
	}

	inline virtual SSizeT StrLen(const TBuffer* Buffer) const = 0;

public:
	inline TString() :
		BufferPtr(),
		Length(0)
	{
		//
	}

	inline TString(const TString& Other) :
		BufferPtr(Other.BufferPtr),
		Length(Other.Length)
	{
		//
	}

	inline TString(const TBuffer* CStr, SSizeT Len) :
		BufferPtr(CopyStr(CStr, Len)),
		Length(Len)
	{
		//
	}

	inline TString(TBuffer* CStr, SSizeT Len) :
		BufferPtr(MakeShareable<TBuffer, ArrayDeleter>(CStr)),
		Length(Len)
	{
		//
	}

	inline virtual ~TString() = default;

	inline SSizeT Len() const
	{
		return Length;
	}

	inline bool Contains(const TBuffer* Char) const
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

	inline UInt64 LastIndexOf(const TBuffer Char) const
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
		TBuffer* NewBuffer = new TBuffer[NewLength];
		GMemory.Copy((TBuffer*)BufferPtr + Start, NewBuffer, sizeof(TBuffer) * (NewLength - 1));
		NewBuffer[NewLength - 1] = '\0';
        return TDerived(NewBuffer, NewLength - 1);
	}

	inline const TDerived Replace(const TBuffer OldChar, const TBuffer NewChar) const
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

	inline const TDerived Replace(const TBuffer* OldStr, const TBuffer* NewStr) const
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
		return Replace(OldStr.BufferPtr.Get(), NewStr.BufferPtr.Get());
	}

	inline TArray<TDerived> Split(const char Separator) const
	{
		TArray<TDerived> Results;
		SInt64 LastFoundSeparator = 0;
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

		return GMemory.Equal(BufferPtr.Raw(), Other.Length, Other.BufferPtr.Raw(), Other.Length);
	}

	inline bool EndsWith(const TDerived& Other) const
	{
		if (Other.Length > Length) return false;

		return GMemory.Equal(BufferPtr.Raw() - Other.Length, Other.Length, Other.BufferPtr.Raw(), Other.Length);
	}

	inline TBuffer LastChar() const
	{
		return BufferPtr[Length - 1];
	}

	inline SSizeT Hash() const
	{
		SSizeT Hash = 14695981039346656037ULL; // 64-bit FNV offset basis
		constexpr SSizeT FnvPrime = 1099511628211ULL;
		
		TBuffer* Buffer = BufferPtr.Raw();

		while (*Buffer) {
			Hash ^= static_cast<SSizeT>(*Buffer++);
			Hash *= FnvPrime;
		}

		return Hash;
	}

	inline TBuffer operator[](SSizeT InIndex) const
	{
		return BufferPtr[InIndex];
	}

	inline const TBuffer* operator*() const
	{
		return BufferPtr.Raw();
	}
};