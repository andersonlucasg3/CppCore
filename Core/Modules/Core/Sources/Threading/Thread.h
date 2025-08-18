#pragma once

#include "Defines/Preprocessors.h"

#include "Object/Object.h"

#include "Templates/Functions.h"

#include "String/String.h"

#include COMPILE_PLATFORM_HEADER_FEATURE(Threading, CriticalSection.h)

DECLARE_CLASS_HEADER(Thread);

class CThread : 
    public CObject, 
    public TSharedFromThis<CThread>
{
    using Super = CObject;
    
    bool bIsRunning = false;
    SPlatformCriticalSection IsRunningSection;

public:
    CORE_API CThread() = default;
    CORE_API ~CThread() override = default;

    CORE_API virtual void SetName(const CString& Name) = 0;
    CORE_API virtual const CString& Name() const = 0;

    CORE_API virtual bool IsRunning();
    CORE_API virtual void Start(const TFunction<void(const CThreadWeakPtr&)>& ThreadFunc);
    CORE_API virtual void Join() = 0;
    CORE_API virtual void Exit();

    CORE_API static CThreadPtr Create();
};