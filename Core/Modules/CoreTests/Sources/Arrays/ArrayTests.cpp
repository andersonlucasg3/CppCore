#include "ArrayTests.h"
#include "Assert.h"

REGISTER_TEST_CLASS(ArrayTests);

#include "Templates/Array.h"

void CArrayTests::TestIntArray()
{
	TArray<int> IntArray;

	for (UInt32 i = 0; i < 5; i++)
	{
		ASSERT_EQUAL(IntArray.Num(), i);

		IntArray.Add(i);
	}

	UInt32 oi = 0;
	for (const UInt32 i : IntArray)
	{
		ASSERT_EQUAL(i, oi);
		oi++;
	}
	
	ASSERT_EQUAL(oi, 5);

	ASSERT_EQUAL(IntArray.Num(), 5);

	for (UInt32 i = 0; i < IntArray.Num(); i++)
	{
		ASSERT_EQUAL(IntArray[i], i);
	}

	for (UInt32 i = 0; i < 4; i++)
	{
		int32_t NewElement = (i + 1) * -1;
		IntArray.Insert(0, NewElement);

		ASSERT_EQUAL(IntArray[0], NewElement);
	}
	
	for (UInt32 i = 0; i < IntArray.Num(); i++)
	{
		ASSERT_EQUAL(IntArray[i], i - 4);
	}

	ASSERT_EQUAL(IntArray.Num(), 9);

	for (;IntArray.Num() > 4;)
	{
		IntArray.RemoveAt(4);
	}

	for (UInt32 i = 0; i < IntArray.Num(); i++)
	{
		ASSERT_EQUAL(IntArray[i], (IntArray.Num() - i) * -1);
	}

	IntArray.RemoveAll();

	IntArray.RemoveAll(false);

	ASSERT_EQUAL(IntArray.Num(), 0);
}

void CArrayTests::TestSharedPtrArray()
{
	TArray<TSharedPtr<int>> ArrayOfPtrs;

	ArrayOfPtrs.Add(MakeShared<int>(1));
	ArrayOfPtrs.Add(MakeShared<int>(2));

	ArrayOfPtrs.RemoveAt(0);
}

void CArrayTests::TestCopyArray()
{
	TArray<int> Array {
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10
	};

	for (int i = 0; i < 10; i++)
	{
		ASSERT_EQUAL(Array[i], i + 1);
	}

	TArray<int> CopiedArray = Array;

	for (int i = 0; i < 10; i++)
	{
		ASSERT_EQUAL(CopiedArray[i], i + 1);
	}

	TArray<int> OtherCopiedArray(CopiedArray);

	for (int i = 0; i < 10; i++)
	{
		ASSERT_EQUAL(OtherCopiedArray[i], i + 1);
	}

	Array[2] = 20;

	ASSERT_EQUAL(Array[2], 20);

	ASSERT_NOT_EQUAL(CopiedArray[2], 20);
}

void CArrayTests::TestCase() 
{
    TestIntArray();

	TestSharedPtrArray();

	TestCopyArray();
}