#pragma once

#include "Templates/Functions.h"
#include "Templates/SharedPointers.h"

#include "Memory/Memory.h"

template<typename TElement>
struct SArrayDeleter : public TDeleter<TElement>
{
	using Super = TDeleter<TElement>;

	inline SArrayDeleter(TElement* InPtr) : Super(InPtr)
	{
		//
	}

	inline void Delete() override
	{
		if (Super::_ptr == nullptr) return;

		delete[] Super::_ptr;
	}
};

template<typename TElement>
class TArray
{
	using ArrayType = TSharedPtr<TElement>;
	using ArrayDeleter = SArrayDeleter<TElement>;

	ArrayType DataPtr;
	SizeT ItemNum;
	SizeT ArraySize;
	
	inline TElement& SetAt(const UInt64& Index, const TElement& Item)
	{
		TElement& Element = *(DataPtr + Index);

		return Element = Item;
	}

	inline void IncreaseArray()
	{
		Resize(ArraySize + 4);
	}

	inline void DecreaseArray(bool bKeepArraySize)
	{
		if (!bKeepArraySize && (ArraySize - ItemNum > 4))
		{
			Resize(ItemNum + 4);
		}
	}

	template<typename TEquatable>
	inline bool IsEqual(TEquatable LHS, TEquatable RHS) const
	{
		return LHS == RHS;
	}

	template<>
	inline bool IsEqual(const char* LHS, const char* RHS) const
	{
		return std::strcmp(LHS, RHS) == 0;
	}

public:
	inline TArray(const TArray& Other) :
		ItemNum(Other.ItemNum),
		ArraySize(Other.ItemNum)
	{
		DataPtr = MakeShareable<TElement, ArrayDeleter>(new TElement[Other.ItemNum]);

		for (UInt32 Index = 0; Index < Other.ItemNum; ++Index)
		{
			DataPtr[Index] = Other.DataPtr[Index];
		}
	}

	inline TArray(SizeT Size = 4, bool bSetItemNumFromSize = false) :
		ItemNum(0),
		ArraySize(Size)
	{
		if (Size > 0)
		{
			DataPtr = MakeShareable<TElement, ArrayDeleter>(new TElement[Size]);
		}

		if (bSetItemNumFromSize)
		{
			ItemNum = Size;
		}
	}

	inline TArray(const TElement* Data, SizeT Size) :
		DataPtr(MakeShareable<TElement, ArrayDeleter>(new TElement[Size])),
		ItemNum(Size),
		ArraySize(Size)
	{
		GMemory.Copy(Data, DataPtr.Raw(), sizeof(TElement) * ItemNum);
	}

	// initializer lists constructor
	inline TArray(std::initializer_list<TElement> InitList) noexcept :
		ItemNum(InitList.size()),
		ArraySize(InitList.size())
	{
		DataPtr = MakeShareable<TElement, ArrayDeleter>(new TElement[InitList.size()]);

		for (UInt32 Index = 0; Index < ItemNum; ++Index)
		{
			DataPtr[Index] = InitList.begin()[Index];
		}
	}

	inline virtual ~TArray()
	{
		DataPtr = nullptr;
	}

	inline TElement& Add(const TElement& NewItem)
	{
		if (ItemNum == ArraySize)
		{
			IncreaseArray();
		}

		return SetAt(ItemNum++, NewItem);
	}

	inline TElement& Insert(UInt64 Index, const TElement& NewItem)
	{
		if ((static_cast<Int64>(ArraySize) - static_cast<Int64>(ItemNum + 1)) <= 0)
		{
			IncreaseArray();
		}

		for (UInt64 CurrentIndex = ItemNum++; CurrentIndex > Index; --CurrentIndex)
		{
			// setting the previous to the next
			SetAt(CurrentIndex, DataPtr[CurrentIndex - 1]);
		}

		return SetAt(Index, NewItem);
	}

	inline void Fill(const TElement& Element)
	{
		ItemNum = ArraySize;
		for (UInt64 Index = 0; Index < ItemNum; ++Index)
		{
			SetAt(Index, Element);
		}
	}

	inline bool Remove(const TElement& Element)
	{
		int32_t IndexToRemove = -1;
		for (UInt32 CurrentIndex = 0; CurrentIndex < ItemNum; CurrentIndex++)
		{
			const TElement& Other = *(DataPtr + CurrentIndex);
			if (IsEqual<TElement>(Element, Other))
			{
				IndexToRemove = CurrentIndex;

				break;
			}
		}

		if (IndexToRemove != -1)
		{
			RemoveAt(IndexToRemove);

			return true;
		}

		return false;
	}

	inline void RemoveAt(UInt64 Index, bool bKeepArraySize = true)
	{
		assert(Index <= ItemNum - 1);
		
		ItemNum--;

		for (UInt64 CurrentIndex = Index; CurrentIndex < ItemNum; ++CurrentIndex)
		{
			SetAt(CurrentIndex, DataPtr[CurrentIndex + 1]);
		}

		DecreaseArray(bKeepArraySize);
	}

	inline void RemoveWhere(const TFunction<bool(const TElement&)>& Predicate, bool bKeepArraySize = true)
	{
		for (UInt64 CurrentIndex = 0; CurrentIndex < ItemNum; ++CurrentIndex)
		{
			const TElement& Element = *(DataPtr.Get() + CurrentIndex);
			if (Predicate(Element))
			{
				RemoveAt(CurrentIndex, bKeepArraySize);

				--CurrentIndex;
			}
		}
	}

	inline void RemoveAll(bool bKeepArraySize = true)
	{
		for (UInt32 Index = 0; Index < ItemNum; ++Index)
		{
			TElement tempItem;
			SetAt(Index, tempItem);
		}

		ItemNum = 0;

		DecreaseArray(bKeepArraySize);
	}

	inline bool Contains(const TElement& Element) const
	{
		for (UInt64 CurrentIndex = 0; CurrentIndex < ItemNum; ++CurrentIndex)
		{
			const TElement& Other = *(DataPtr + CurrentIndex);
			if (IsEqual<TElement>(Element, Other))
			{
				return true;
			}
		}

		return false;
	}

	template<typename TSize = SizeT>
	inline const TSize Num() const
	{
		return static_cast<TSize>(ItemNum);
	}

	inline bool IsEmpty() const
	{
		return ItemNum == 0;
	}

	inline TElement* GetData()
	{
		return DataPtr.Raw();
	}

	template<typename TReinterpretedElement>
	inline TReinterpretedElement* GetData()
	{
		TElement* Data = GetData();
		return reinterpret_cast<TReinterpretedElement*>(Data);
	}

	inline const TElement* GetData() const
	{
		return DataPtr.Raw();
	}

	template<typename TReinterpretedElement>
	inline const TReinterpretedElement* GetData() const
	{
		const TElement* Data = GetData();
		return reinterpret_cast<TReinterpretedElement*>(Data);
	}

	inline TElement& First()
	{
		return *DataPtr.Get();
	}

	inline const TElement& First() const
	{
		return *DataPtr.Get();
	}

	inline void Resize(SizeT NewSize, bool bApplyNewSizeToItemNum = false)
	{
		if (ArraySize != NewSize)
		{
			if (NewSize == 0)
			{
				DataPtr = nullptr;
				ItemNum = 0;
				ArraySize = 0;
				return;
			}

			ArrayType NewDataPtr = MakeShareable<TElement, ArrayDeleter>(new TElement[NewSize]);
			
			// must use assign so copy operators will be used
			for (Int32 Index = 0; Index < ItemNum; ++Index)
			{
				NewDataPtr.Raw()[Index] = DataPtr.Raw()[Index];
			}

			DataPtr = NewDataPtr;
			ArraySize = NewSize;
		}

		if (bApplyNewSizeToItemNum)
		{
			ItemNum = ArraySize;
		}
	}

	template<typename TCast>
	inline TArray<TCast> Cast(const TFunction<TCast(const TElement& Element)>& CastFunc) const
	{
		TArray<TCast> Casted(ItemNum, true);
		for (UInt32 Index = 0; Index < ItemNum; ++Index)
		{
			Casted[Index] = CastFunc(DataPtr.Get()[Index]);
		}
		return Casted;
	}

	template<typename TCast>
	inline TArray<TCast> Cast() const
	{
		TArray<TCast> Casted(ItemNum * sizeof(TElement), true);
		GMemory.Copy(GetData(), Casted.GetData(), Casted.Num());
		return Casted;
	}

	inline void ForEach(const TFunction<void(TElement&)>& EachFunc)
	{
		for (UInt32 Index = 0; Index < ItemNum; ++Index)
		{
			EachFunc(DataPtr[Index]);
		}
	}

	inline void ForEach(const TFunction<void(const TElement&)>& EachFunc) const
	{
		for (UInt32 Index = 0; Index < ItemNum; ++Index)
		{
			EachFunc(DataPtr.Get()[Index]);
		}
	}

	inline void Reverse()
	{
		ArrayType NewDataPtr = MakeShareable<TElement, ArrayDeleter>(new TElement[ArraySize]);

		for (UInt32 IndexReversed = ItemNum - 1, Index = 0; Index < ItemNum; --IndexReversed, ++Index)
		{
			TElement& NewElement = NewDataPtr[IndexReversed];
			TElement& CurrentElement = DataPtr[Index];

			NewElement = CurrentElement;
		}

		DataPtr = NewDataPtr;
	}

	inline TElement& operator[](SizeT Index)
	{
		TElement& Element = *(DataPtr + Index);

		return Element;
	}

	inline const TElement& operator[](SizeT Index) const
	{
		const TElement& Element = *(DataPtr + Index);

		return Element;
	}

	inline TArray& operator=(const TArray& Other)
	{
		DataPtr = MakeShareable<TElement, ArrayDeleter>(new TElement[Other.ItemNum]);
		ItemNum = Other.ItemNum;
		ArraySize = Other.ItemNum;

		GMemory.Copy(Other.GetData(), GetData(), ItemNum * sizeof(TElement));

		return *this;
	}

	inline TElement* begin() const
	{
		return (TElement*)DataPtr;
	}

	inline TElement* end() const
	{
		return DataPtr + ItemNum;
	}
};
