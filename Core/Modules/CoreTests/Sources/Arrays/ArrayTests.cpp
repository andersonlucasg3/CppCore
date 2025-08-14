#include "ArrayTests.h"

REGISTER_TEST_CLASS(ArrayTests);

#include "Templates/Array.h"
#include "Templates/Strings.h"

inline void TestIntArray()
{
	TArray<int> IntArray;

	for (UInt32 i = 0; i < 5; i++)
	{
		assert(IntArray.Num() == i);

		IntArray.Add(i);
	}

	UInt32 oi = 0;
	for (const UInt32 i : IntArray)
	{
		assert(i == oi);
		oi++;
	}
	
	assert(oi == 5);

	assert(IntArray.Num() == 5);

	for (UInt32 i = 0; i < IntArray.Num(); i++)
	{
		assert(IntArray[i] == i);
	}

	for (UInt32 i = 0; i < 4; i++)
	{
		int32_t NewElement = (i + 1) * -1;
		IntArray.Insert(0, NewElement);

		assert(IntArray[0] == NewElement);
	}
	
	for (UInt32 i = 0; i < IntArray.Num(); i++)
	{
		assert(IntArray[i] == i - 4);
	}

	assert(IntArray.Num() == 9);

	for (;IntArray.Num() > 4;)
	{
		IntArray.RemoveAt(4);
	}

	for (UInt32 i = 0; i < IntArray.Num(); i++)
	{
		assert(IntArray[i] == (IntArray.Num() - i) * -1);
	}

	IntArray.RemoveAll();

	IntArray.RemoveAll(false);

	assert(IntArray.Num() == 0);
}

inline void TestSharedPtrArray()
{
	TArray<TSharedPtr<int>> ArrayOfPtrs;

	ArrayOfPtrs.Add(MakeShared<int>(1));
	ArrayOfPtrs.Add(MakeShared<int>(2));

	ArrayOfPtrs.RemoveAt(0);
}

inline void TestCopyArray()
{
	TArray<int> Array {
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10
	};

	for (int i = 0; i < 10; i++)
	{
		assert(Array[i] == i + 1);
	}

	TArray<int> CopiedArray = Array;

	for (int i = 0; i < 10; i++)
	{
		assert(CopiedArray[i] == i + 1);
	}

	TArray<int> OtherCopiedArray(CopiedArray);

	for (int i = 0; i < 10; i++)
	{
		assert(OtherCopiedArray[i] == i + 1);
	}

	Array[2] = 20;

	assert(Array[2] == 20);

	assert(CopiedArray[2] != 20);
}

void CArrayTests::TestCase() 
{
    TestIntArray();

	TestSharedPtrArray();

	TestCopyArray();
}