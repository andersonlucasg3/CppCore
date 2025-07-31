#include "WindowsThread.h"

#if PLATFORM_WINDOWS

#include <Windows.h>
#include <processthreadsapi.h>

void CWindowsThread::SetName(const CString& Name)
{
	this->Name = Name;
}

void CWindowsThread::Start(const TFunction<void(const CThreadWeakPtr&)>& ThreadFunc)
{
	Super::Start(ThreadFunc);

	if (!Thread)
	{
		CThreadWeakPtr WeakThread = this;
		Thread = MakeShared<std::thread>([ThreadFunc, WeakThread]
		{
			while (WeakThread->IsRunning())
			{
				ThreadFunc(WeakThread);
			}
		});

		if (!Name.IsEmpty())
		{
			CWString WName(Name);
			SetThreadDescription(Thread->native_handle(), *WName);
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

CWindowsThreadPtr CWindowsThread::Create()
{
	return MakeShareable(new CWindowsThread);
}

#endif // PLATFORM_WINDOWS