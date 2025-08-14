#pragma once

#include "Threading/Thread.h"

#include <thread>

CORE_CLASS_HEADER(WindowsThread);

class CWindowsThread : public CThread
{
    using Super = CThread;

    CString _name;
    TSharedPtr<std::thread> Thread;
    bool bIsRunning = false;

protected:
    CORE_API CWindowsThread() = default;

public:
    CORE_API ~CWindowsThread() override = default;

    CORE_API void SetName(const CString& Name) override;
    CORE_API const CString& Name() const override;

    CORE_API void Start(const TFunction<void(const CThreadWeakPtr&)>& ThreadFunc) override;
    CORE_API void Join() override;

    CORE_API static CWindowsThreadPtr Create();
};

typedef CWindowsThread CPlatformThread;