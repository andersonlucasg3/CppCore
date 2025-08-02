#include "WindowsThread.h"

#if PLATFORM_WINDOWS

#include "String/WString.h"
#include <Windows.h>
#include <processthreadsapi.h>

void CWindowsThread::SetName(const CString& Name)
{
	this->_name = Name;
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
			CWString WName(*_name, _name.Len());
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