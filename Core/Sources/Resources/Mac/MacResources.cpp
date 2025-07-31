#include "MacResources.h"

#if PLATFORM_MACOS

#include "Process/Apple/AppleProcess.h"
#include "Filesystem/DirectoryReference.h"
#include "Filesystem/FileReference.h"

SFileRef CMacResources::GetResource(const CString& InResourceName) const
{
    SDirectoryRef ContainerDirectory = CAppleProcess::Get().GetExecutableContainerPath();

    return ContainerDirectory->CombineFile({
        CAppleProcess::Get().IsRunningOnAppBundle() ? "../Resources" : "Resources",
        InResourceName
    });
}

#endif // PLATFORM_MACOS