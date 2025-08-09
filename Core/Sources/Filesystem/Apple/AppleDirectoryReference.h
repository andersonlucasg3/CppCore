#pragma once

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

    CORE_API NS::String* PathString() const;
    CORE_API NS::URL* PathURL() const;
};