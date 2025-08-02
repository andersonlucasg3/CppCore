#include "WindowsResources.h"

#if PLATFORM_WINDOWS

#include "Filesystem/Path.h"
#include "Process/Process.h"

SFileRef CWindowsResources::GetResource(const CString& InResourceName) const
{
	return GPath.Combine({
		GProcess.GetExecutableContainerPath(),
		"Resources",
		InResourceName
	});;
}

#endif // PLATFORM_WINDOWS