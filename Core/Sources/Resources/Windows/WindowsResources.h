#pragma once

#include "CoreDefinitions.h"

#if PLATFORM_WINDOWS

#include "Resources/Resources.h"

class CWindowsResources : public IResources
{
public:
	CORE_API ~CWindowsResources() override = default;
	
	CORE_API CString GetResource(const CString& RelativeResourcePath) const override;
};

typedef CWindowsResources CPlatformResources;

#endif // PLATFORM_WINDOWS