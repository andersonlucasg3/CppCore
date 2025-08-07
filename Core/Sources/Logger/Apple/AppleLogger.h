#pragma once

#if PLATFORM_GROUP_APPLE

#include "Logger/Logger.h"

class CAppleLogger : public CLogger
{
    using Super = CLogger;

protected:
	CORE_API void WriteLogLine(const std::string& LogLine) const override;

public:
    CORE_API CAppleLogger() = default;
    CORE_API ~CAppleLogger() override = default;
};

typedef CAppleLogger CPlatformLogger;

#endif // PLATFORM_GROUP_APPLE