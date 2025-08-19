#include "NSProcessInfo.h"

_NS_PRIVATE_DEF_CONST(NS::NotificationName, ProcessInfoThermalStateDidChangeNotification);
_NS_PRIVATE_DEF_CONST(NS::NotificationName, ProcessInfoPowerStateDidChangeNotification);

#if defined(METAL_ENABLED)
    // The linker searches for these symbols in the Metal framework, be sure to link it in as well:
    _NS_PRIVATE_DEF_CONST(NS::NotificationName, ProcessInfoPerformanceProfileDidChangeNotification);
    _NS_PRIVATE_DEF_CONST(NS::DeviceCertification, DeviceCertificationiPhonePerformanceGaming);
    _NS_PRIVATE_DEF_CONST(NS::ProcessPerformanceProfile, ProcessPerformanceProfileDefault);
    _NS_PRIVATE_DEF_CONST(NS::ProcessPerformanceProfile, ProcessPerformanceProfileSustained);
#endif // defined(METAL_ENABLED)

namespace NS 
{
    ProcessInfo* ProcessInfo::processInfo()
    {
        return Object::sendMessage<ProcessInfo*>(_NS_PRIVATE_CLS(NSProcessInfo), _NS_PRIVATE_SEL(processInfo));
    }

    Array* ProcessInfo::arguments() const
    {
        return Object::sendMessage<Array*>(this, _NS_PRIVATE_SEL(arguments));
    }

    Dictionary* ProcessInfo::environment() const
    {
        return Object::sendMessage<Dictionary*>(this, _NS_PRIVATE_SEL(environment));
    }

    String* ProcessInfo::hostName() const
    {
        return Object::sendMessage<String*>(this, _NS_PRIVATE_SEL(hostName));
    }

    String* ProcessInfo::processName() const
    {
        return Object::sendMessage<String*>(this, _NS_PRIVATE_SEL(processName));
    }

    void ProcessInfo::setProcessName(const String* pString)
    {
        Object::sendMessage<void>(this, _NS_PRIVATE_SEL(setProcessName_), pString);
    }

    int ProcessInfo::processIdentifier() const
    {
        return Object::sendMessage<int>(this, _NS_PRIVATE_SEL(processIdentifier));
    }

    String* ProcessInfo::globallyUniqueString() const
    {
        return Object::sendMessage<String*>(this, _NS_PRIVATE_SEL(globallyUniqueString));
    }

    String* ProcessInfo::userName() const
    {
        return Object::sendMessageSafe<String*>(this, _NS_PRIVATE_SEL(userName));
    }

    String* ProcessInfo::fullUserName() const
    {
        return Object::sendMessageSafe<String*>(this, _NS_PRIVATE_SEL(fullUserName));
    }

    UInteger ProcessInfo::operatingSystem() const
    {
        return Object::sendMessage<UInteger>(this, _NS_PRIVATE_SEL(operatingSystem));
    }

    OperatingSystemVersion ProcessInfo::operatingSystemVersion() const
    {
        return Object::sendMessage<OperatingSystemVersion>(this, _NS_PRIVATE_SEL(operatingSystemVersion));
    }

    String* ProcessInfo::operatingSystemVersionString() const
    {
        return Object::sendMessage<String*>(this, _NS_PRIVATE_SEL(operatingSystemVersionString));
    }

    bool ProcessInfo::isOperatingSystemAtLeastVersion(OperatingSystemVersion version) const
    {
        return Object::sendMessage<bool>(this, _NS_PRIVATE_SEL(isOperatingSystemAtLeastVersion_), version);
    }

    UInteger ProcessInfo::processorCount() const
    {
        return Object::sendMessage<UInteger>(this, _NS_PRIVATE_SEL(processorCount));
    }

    UInteger ProcessInfo::activeProcessorCount() const
    {
        return Object::sendMessage<UInteger>(this, _NS_PRIVATE_SEL(activeProcessorCount));
    }

    unsigned long long ProcessInfo::physicalMemory() const
    {
        return Object::sendMessage<unsigned long long>(this, _NS_PRIVATE_SEL(physicalMemory));
    }

    TimeInterval ProcessInfo::systemUptime() const
    {
        return Object::sendMessage<TimeInterval>(this, _NS_PRIVATE_SEL(systemUptime));
    }

    void ProcessInfo::disableSuddenTermination()
    {
        Object::sendMessageSafe<void>(this, _NS_PRIVATE_SEL(disableSuddenTermination));
    }

    void ProcessInfo::enableSuddenTermination()
    {
        Object::sendMessageSafe<void>(this, _NS_PRIVATE_SEL(enableSuddenTermination));
    }

    void ProcessInfo::disableAutomaticTermination(const String* pReason)
    {
        Object::sendMessageSafe<void>(this, _NS_PRIVATE_SEL(disableAutomaticTermination_), pReason);
    }

    void ProcessInfo::enableAutomaticTermination(const String* pReason)
    {
        Object::sendMessageSafe<void>(this, _NS_PRIVATE_SEL(enableAutomaticTermination_), pReason);
    }

    bool ProcessInfo::automaticTerminationSupportEnabled() const
    {
        return Object::sendMessageSafe<bool>(this, _NS_PRIVATE_SEL(automaticTerminationSupportEnabled));
    }

    void ProcessInfo::setAutomaticTerminationSupportEnabled(bool enabled)
    {
        Object::sendMessageSafe<void>(this, _NS_PRIVATE_SEL(setAutomaticTerminationSupportEnabled_), enabled);
    }

    Object* ProcessInfo::beginActivity(ActivityOptions options, const String* pReason)
    {
        return Object::sendMessage<Object*>(this, _NS_PRIVATE_SEL(beginActivityWithOptions_reason_), options, pReason);
    }

    void ProcessInfo::endActivity(Object* pActivity)
    {
        Object::sendMessage<void>(this, _NS_PRIVATE_SEL(endActivity_), pActivity);
    }

    void ProcessInfo::performActivity(ActivityOptions options, const String* pReason, void (^block)(void))
    {
        Object::sendMessage<void>(this, _NS_PRIVATE_SEL(performActivityWithOptions_reason_usingBlock_), options, pReason, block);
    }

    void ProcessInfo::performActivity(ActivityOptions options, const String* pReason, const std::function<void()>& function)
    {
        __block std::function<void()> blockFunction = function;

        performActivity(options, pReason, ^() { blockFunction(); });
    }

    void ProcessInfo::performExpiringActivity(const String* pReason, void (^block)(bool expired))
    {
        Object::sendMessageSafe<void>(this, _NS_PRIVATE_SEL(performExpiringActivityWithReason_usingBlock_), pReason, block);
    }

    void ProcessInfo::performExpiringActivity(const String* pReason, const std::function<void(bool expired)>& function)
    {
        __block std::function<void(bool expired)> blockFunction = function;

        performExpiringActivity(pReason, ^(bool expired) { blockFunction(expired); });
    }

    ProcessInfoThermalState ProcessInfo::thermalState() const
    {
        return Object::sendMessage<ProcessInfoThermalState>(this, _NS_PRIVATE_SEL(thermalState));
    }

    bool ProcessInfo::isLowPowerModeEnabled() const
    {
        return Object::sendMessageSafe<bool>(this, _NS_PRIVATE_SEL(isLowPowerModeEnabled));
    }

    bool ProcessInfo::isiOSAppOnMac() const
    {
        return Object::sendMessageSafe<bool>(this, _NS_PRIVATE_SEL(isiOSAppOnMac));
    }

    bool ProcessInfo::isMacCatalystApp() const
    {
        return Object::sendMessageSafe<bool>(this, _NS_PRIVATE_SEL(isMacCatalystApp));
    }

#if defined(METAL_ENABLED)

    bool ProcessInfo::isDeviceCertified(DeviceCertification performanceTier) const
    {
        return Object::sendMessageSafe<bool>(this, _NS_PRIVATE_SEL(isDeviceCertified_), performanceTier);
    }

#endif // defined(METAL_ENABLED)

#if defined(METAL_ENABLED)

    bool ProcessInfo::hasPerformanceProfile(ProcessPerformanceProfile performanceProfile) const
    {
        return Object::sendMessageSafe<bool>(this, _NS_PRIVATE_SEL(hasPerformanceProfile_), performanceProfile);
    }

#endif // defined(METAL_ENABLED)
}