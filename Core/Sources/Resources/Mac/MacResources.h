#pragma once

#if PLATFORM_MACOS

#include "Resources/Resources.h"

class CMacResources : public CResources
{
public:
    CORE_API ~CMacResources() override = default;

    CORE_API SFileRef GetResource(const CString& InResourceName) const override;
};

typedef CMacResources CPlatformResources;

#endif // PLATFORM_MACOS