#pragma once

#include "NSObject.hpp"
#include "NSDefines.h"
#include "NSNotification.h"
#include "NSPrivate.h"

#include <functional>

namespace NS
{
    _NS_CONST(NotificationName, ProcessInfoThermalStateDidChangeNotification);
    _NS_CONST(NotificationName, ProcessInfoPowerStateDidChangeNotification);
    _NS_CONST(NotificationName, ProcessInfoPerformanceProfileDidChangeNotification);

    _NS_ENUM(Integer, ProcessInfoThermalState) 
    {
        ProcessInfoThermalStateNominal = 0,
        ProcessInfoThermalStateFair = 1,
        ProcessInfoThermalStateSerious = 2,
        ProcessInfoThermalStateCritical = 3
    };

    _NS_OPTIONS(std::uint64_t, ActivityOptions) 
    {
        ActivityIdleDisplaySleepDisabled = (1ULL << 40),
        ActivityIdleSystemSleepDisabled = (1ULL << 20),
        ActivitySuddenTerminationDisabled = (1ULL << 14),
        ActivityAutomaticTerminationDisabled = (1ULL << 15),
        ActivityUserInitiated = (0x00FFFFFFULL | ActivityIdleSystemSleepDisabled),
        ActivityUserInitiatedAllowingIdleSystemSleep = (ActivityUserInitiated & ~ActivityIdleSystemSleepDisabled),
        ActivityBackground = 0x000000FFULL,
        ActivityLatencyCritical = 0xFF00000000ULL,
    };

#if defined(METAL_ENABLED)
    typedef NS::Integer DeviceCertification;
    _NS_CONST(DeviceCertification, DeviceCertificationiPhonePerformanceGaming);

    typedef NS::Integer ProcessPerformanceProfile;
    _NS_CONST(ProcessPerformanceProfile, ProcessPerformanceProfileDefault);
    _NS_CONST(ProcessPerformanceProfile, ProcessPerformanceProfileSustained);
#endif // defined(METAL_ENABLED)

    class ProcessInfo : public Referencing<ProcessInfo>
    {
    public:
        static ProcessInfo*     processInfo();

        class Array*            arguments() const;
        class Dictionary*       environment() const;
        class String*           hostName() const;
        class String*           processName() const;
        void                    setProcessName(const String* pString);
        int                     processIdentifier() const;
        class String*           globallyUniqueString() const;

        class String*           userName() const;
        class String*           fullUserName() const;

        UInteger                operatingSystem() const;
        OperatingSystemVersion  operatingSystemVersion() const;
        class String*           operatingSystemVersionString() const;
        bool                    isOperatingSystemAtLeastVersion(OperatingSystemVersion version) const;

        UInteger                processorCount() const;
        UInteger                activeProcessorCount() const;
        unsigned long long      physicalMemory() const;
        TimeInterval            systemUptime() const;

        void                    disableSuddenTermination();
        void                    enableSuddenTermination();

        void                    disableAutomaticTermination(const class String* pReason);
        void                    enableAutomaticTermination(const class String* pReason);
        bool                    automaticTerminationSupportEnabled() const;
        void                    setAutomaticTerminationSupportEnabled(bool enabled);

        class Object*           beginActivity(ActivityOptions options, const class String* pReason);
        void                    endActivity(class Object* pActivity);
        void                    performActivity(ActivityOptions options, const class String* pReason, void (^block)(void));
        void                    performActivity(ActivityOptions options, const class String* pReason, const std::function<void()>& func);
        void                    performExpiringActivity(const class String* pReason, void (^block)(bool expired));
        void                    performExpiringActivity(const class String* pReason, const std::function<void(bool expired)>& func);

        ProcessInfoThermalState thermalState() const;
        bool                    isLowPowerModeEnabled() const;

        bool                    isiOSAppOnMac() const;
        bool                    isMacCatalystApp() const;

#if defined(METAL_ENABLED)
        bool                    isDeviceCertified(DeviceCertification performanceTier) const;
        bool                    hasPerformanceProfile(ProcessPerformanceProfile performanceProfile) const;
#endif // defined(METAL_ENABLED)
    };
}

_NS_PRIVATE_EXTERN_CONST(NS::NotificationName, ProcessInfoThermalStateDidChangeNotification);
_NS_PRIVATE_EXTERN_CONST(NS::NotificationName, ProcessInfoPowerStateDidChangeNotification);

#if defined(METAL_ENABLED)
    // The linker searches for these symbols in the Metal framework, be sure to link it in as well:
    _NS_PRIVATE_EXTERN_CONST(NS::NotificationName, ProcessInfoPerformanceProfileDidChangeNotification);
    _NS_PRIVATE_EXTERN_CONST(NS::DeviceCertification, DeviceCertificationiPhonePerformanceGaming);
    _NS_PRIVATE_EXTERN_CONST(NS::ProcessPerformanceProfile, ProcessPerformanceProfileDefault);
    _NS_PRIVATE_EXTERN_CONST(NS::ProcessPerformanceProfile, ProcessPerformanceProfileSustained);
#endif // defined(METAL_ENABLED)