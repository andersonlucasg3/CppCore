#pragma once

#include "CoreDefinitions.h"

#if PLATFORM_MACOS

#include "Templates/SharedPointers.h"

#include "Threading/Thread.h"

#include <thread>

CORE_CLASS_HEADER(MacThread);

class CMacThread : public CThread
{
    using Super = CThread;

    CString ThreadName;
    TSharedPtr<std::thread> Thread;

public:
    CORE_API CMacThread() = default;
    CORE_API ~CMacThread() override = default;

    CORE_API void SetName(const CString& Name) override;
    CORE_API CString Name() const override;

    CORE_API void Start(const TFunction<void(const CThreadWeakPtr&)>& ThreadFunc) override;
    CORE_API void Join() override;

    CORE_API static CMacThreadPtr Create();
};

typedef CMacThread CPlatformThread;

#endif // PLATFORM_MACOS