#pragma once

#include "Defines/PlatformInfo.h"

#if PLATFORM_APPLE

#include "Filesystem/FilesystemReference.h"
#include "Filesystem/FileReference.h"
#include "Filesystem/DirectoryReference.h"

#include <Foundation/NSString.hpp>
#include <Foundation/NSURL.hpp>
#include <Foundation/NSSharedPtr.hpp>

class CAppleDirectoryReference : public CDirectoryReference
{
    using Super = CDirectoryReference;

    NS::SharedPtr<NS::URL> _directoryURL;
    
    CORE_API void UpdateExistance() override;
    
public:
    CORE_API CAppleDirectoryReference(const CString& InPath);
    CORE_API ~CAppleDirectoryReference() override = default;

    CORE_API bool Create(bool InCreateIntermediates = false) override;
    CORE_API bool Delete() override;

    CORE_API SDirectoryRef Combine(const CString& InComponent) const override;
    CORE_API SDirectoryRef Combine(const TArray<CString>& InComponents) const override;
    CORE_API SFileRef CombineFile(const CString& InFilename) const override;
    CORE_API SFileRef CombineFile(const TArray<CString>& InComponents) const override;

    CORE_API NS::String* PathString() const;
    CORE_API NS::URL* PathURL() const;
};

#endif // PLATFORM_APPLE