#pragma once

#if PLATFORM_GROUP_APPLE

#include "Filesystem/FileReference.h"

#include <Foundation/NSString.hpp>
#include <Foundation/NSURL.hpp>
#include <Foundation/NSSharedPtr.hpp>

CORE_CLASS_HEADER(AppleFileReference);

class CAppleFileReference : public CFileReference
{
    using Super = CFileReference;

    NS::SharedPtr<NS::URL> _fileURL;
    
    CORE_API void UpdateExistance() override;
    
public:
    CORE_API CAppleFileReference(const CString& InPath);
    CORE_API ~CAppleFileReference() override = default;

    CORE_API NS::String* PathString() const;
    CORE_API NS::URL* PathURL() const;
};

#endif // PLATFORM_GROUP_APPLE