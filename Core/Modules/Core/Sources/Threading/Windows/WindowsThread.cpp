#include "WindowsThread.h"

#include <Windows.h>

#include <processthreadsapi.h>
#include <synchapi.h>

void CWindowsThread::SetName(const CString& Name)
{
	this->_name = Name;
}

const CString& CWindowsThread::Name() const
{
	return _name;
}

void CWindowsThread::Start(const TFunction<void(const CThreadWeakPtr&)>& ThreadFunc)
{
	Super::Start(ThreadFunc);

	if (!Thread)
	{
		CThreadWeakPtr WeakThread = AsWeak();
		Thread = MakeShared<std::thread>([ThreadFunc, WeakThread]
		{
			while (WeakThread->IsRunning())
			{
				ThreadFunc(WeakThread);
			}
		});

		if (!_name.IsEmpty())
		{
			SetThreadDescription(Thread->native_handle(), _name.WStr().Raw());
		}
	}
}

void CWindowsThread::Join()
{
	if (Thread && Thread->joinable())
	{
		Thread->join();
	}
}

void CWindowsThread::Sleep(UInt64 InTimeMilliseconds)
{
	::Sleep(InTimeMilliseconds);
}

CWindowsThreadPtr CWindowsThread::Create()
{
	return MakeShareable(new CWindowsThread);
}