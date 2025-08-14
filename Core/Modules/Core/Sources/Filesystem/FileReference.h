#pragma once

#include "Templates/SmartPointer/SharedPointer.h"

#include "Filesystem/FilesystemReference.h"

class CFileReference;

struct SFileRef final : public TSharedPtr<CFileReference>
{
    using Super = TSharedPtr<CFileReference>;

    SFileRef() = default;
    SFileRef(const char* InCStr);
    SFileRef(const CString& InPath);
    SFileRef(const TArray<CString>& InComponents);
    ~SFileRef() = default;

    SFileRef& operator=(const char* InCStr);
    SFileRef& operator=(const CString& InPath);
    SFileRef& operator=(const TArray<CString>& InComponents);

private:
    void operator=(const TSharedPtr<CFileReference>& Other);
};

class CFileReference : public TFilesystemReference<CFileReference>
{
    using Super = TFilesystemReference<CFileReference>;

protected:
    CORE_API explicit CFileReference(const CString& InPath);
    CORE_API ~CFileReference() override = default;

public:
    CORE_API bool Delete() override;
};