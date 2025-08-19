#include "SharedPtrTests.h"

#include "SmartPointer/SharedPointer.h"
#include "SmartPointer/WeakPointer.h"
#include "SmartPointer/MakeAndCasts.h"

REGISTER_TEST_CLASS(SharedPtrTests);

class ITestType 
{
public:
    virtual ~ITestType() = default;

    virtual int MyTestMethod() = 0;
};

class CTestType : public ITestType 
{
public:
    ~CTestType() override = default;

    virtual int MyTestMethod() override { return 1234; }
};

void CSharedPtrTests::TestCase() 
{
    TSharedPtr<int> NullSharedPtr;

    assert(NullSharedPtr == nullptr);
    assert(!NullSharedPtr);

    int *SharedPtr = nullptr;

    {
        TSharedPtr<int> SharedIntPtr = MakeShared<int>();
        SharedPtr = SharedIntPtr.Raw();

        assert(*SharedIntPtr == 0);
        assert(SharedIntPtr);
        assert(*SharedIntPtr == 0);

        *SharedIntPtr = 10;

        assert(*SharedIntPtr == 10);

        *SharedIntPtr = 20;

        assert(*SharedIntPtr == 20);

        assert(SharedIntPtr.RefCount() == 1);

        {
            TSharedPtr<int> CopySharedIntPtr = SharedIntPtr;

            assert(SharedIntPtr == CopySharedIntPtr);

            assert(CopySharedIntPtr.RefCount() == 2);
        }

        assert(SharedIntPtr.RefCount() == 1);
    }

    // testing inheritance

    TSharedPtr<ITestType> TestTypePtr = MakeShared<CTestType>();

    assert(TestTypePtr);

    // testing equality

    TSharedPtr<CTestType> OtherTestTypePtr = StaticCastSharedPtr<CTestType>(TestTypePtr);

    assert(OtherTestTypePtr->MyTestMethod() == 1234);

    assert(TestTypePtr == OtherTestTypePtr);

    // testing assertion

    // Uncomment to test assertion
    // OtherTestTypePtr = TestTypePtr;

    // testing weak pointers

    TWeakPtr<int> WeakPtr1;
    TWeakPtr<int> WeakPtr2;
    TWeakPtr<int> WeakPtr3;

    assert(!WeakPtr1);
    assert(WeakPtr1 == nullptr);

    {
        TSharedPtr<int> TempPtr = MakeShared<int>(20);

        WeakPtr1 = TempPtr;
        WeakPtr2 = TempPtr;
        WeakPtr3 = WeakPtr2;

        assert(WeakPtr1);
        assert(WeakPtr1 == TempPtr);
        assert(*WeakPtr1 == 20);
    }

    assert(!WeakPtr1);
    assert(!WeakPtr2);
    assert(!WeakPtr3);

    TWeakPtr<CTestType> WeakObject = OtherTestTypePtr;

    TWeakPtr<ITestType> OtherWeakObject = OtherTestTypePtr;

    {
        TWeakPtr<CTestType> AnotherWeakObject =
            StaticCastWeakPtr<CTestType>(OtherWeakObject);
    }
}