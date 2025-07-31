#include "WindowsResources.h"

#if PLATFORM_WINDOWS

#include "Filesystem/Path.h"
#include "Process/Process.h"

CString CWindowsResources::GetResource(const CString& RelativeResourcePath) const
{
	return IPath::Get()->Combine({
		IProcess::Get()->GetExecutableContainerPath(),
		"Resources",
		RelativeResourcePath
	});;
}

#endif // PLATFORM_WINDOWS