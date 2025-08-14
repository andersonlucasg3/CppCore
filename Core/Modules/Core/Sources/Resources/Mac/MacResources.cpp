#include "MacResources.h"

#include "Process/Mac/MacProcess.h"

#include "Filesystem/DirectoryReference.h"
#include "Filesystem/FileReference.h"

SFileRef CMacResources::GetResource(const CString& InResourceName) const
{
    SDirectoryRef ContainerDirectory = GMacProcess.GetContainerPath();

    return ContainerDirectory->CombineFile({
        GMacProcess.IsRunningOnAppBundle() ? "../Resources" : "Resources",
        InResourceName
    });
}