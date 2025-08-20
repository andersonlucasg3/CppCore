#include "QueueTests.h"

#include "Templates/Queue.h"

#include "SmartPointer/MakeAndCasts.h"

REGISTER_TEST_CLASS(QueueTests);

inline void TestIntQueue()
{
	TQueue<int> IntQueue;

	assert(IntQueue.IsEmpty());

	IntQueue.Enqueue(0);

	assert(!IntQueue.IsEmpty());

	int Value;
	assert(IntQueue.Peak(Value) && Value == 0);

	assert(!IntQueue.IsEmpty());

	for (int32_t i = 1; i <= 10; i++)
	{
		IntQueue.Enqueue(i);
	}

	for (int i = 0; i <= 10; i++)
	{
		assert(IntQueue.Dequeue(Value));
		assert(Value == i);
	}
}

inline void TestSharedPtrQueue()
{
	TQueue<TSharedPtr<int>> QueueOfPtrs;

	QueueOfPtrs.Enqueue(MakeShared<int>(1));
	QueueOfPtrs.Enqueue(MakeShared<int>(2));

	TSharedPtr<int> Deq;
	QueueOfPtrs.Dequeue(Deq);

	assert(*Deq == 1);
}

inline void TestInterfaceQueue()
{
	class IInterfaceTest
	{
	public:
		virtual ~IInterfaceTest() = default;
		virtual void TestMethod() = 0;
	};

	class CConcreteTest : public IInterfaceTest
	{
	public:
		~CConcreteTest() override = default;
		void TestMethod() override { }
	};

	TQueue<TSharedPtr<IInterfaceTest>> Queue;

	Queue.Enqueue(MakeShared<CConcreteTest>());
	Queue.Enqueue(MakeShared<CConcreteTest>());

	TSharedPtr<IInterfaceTest> Ptr;
	Queue.Dequeue(Ptr);
}

void CQueueTests::TestCase()
{
    TestIntQueue();

	TestSharedPtrQueue();

	TestInterfaceQueue();
}