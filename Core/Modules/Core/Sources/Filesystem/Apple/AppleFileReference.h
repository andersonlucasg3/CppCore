#pragma once

#include "Filesystem/FileReference.h"
#include "Object/ClassMacros.h"

#include "NSSharedPtr.hpp"
#include "NSString.h"
#include "NSURL.h"

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