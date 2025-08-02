#pragma once

#include "Filesystem/FilesystemReference.h"

#include "FileReference.h"

class CDirectoryReference;

struct SDirectoryRef final : public TSharedPtr<CDirectoryReference>
{
    using Super = TSharedPtr<CDirectoryReference>;

    SDirectoryRef() = default;
    SDirectoryRef(const char* InCStr);
    SDirectoryRef(const CString& InPath);
    SDirectoryRef(const TArray<CString>& InComponents);
    ~SDirectoryRef() = default;

    SDirectoryRef& operator=(const char* InCStr);
    SDirectoryRef& operator=(const CString& InPath);
    SDirectoryRef& operator=(const TArray<CString>& InComponents);

private:
    void operator=(const TSharedPtr<CDirectoryReference>& Other);
};

class CDirectoryReference : public TFilesystemReference<CDirectoryReference>
{
    using Super = TFilesystemReference<CDirectoryReference>;

protected:
    explicit CDirectoryReference(const CString& InPath) : Super(InPath) { }
    virtual ~CDirectoryReference() = default;

public:
    CORE_API virtual bool Create(bool InCreateIntermediates = false) = 0;
    CORE_API virtual bool Delete() = 0;

    CORE_API virtual SDirectoryRef Combine(const CString& InComponent) const = 0;
    CORE_API virtual SDirectoryRef Combine(const TArray<CString>& InComponents) const = 0;
    CORE_API virtual SFileRef CombineFile(const CString& InFilename) const = 0;
    CORE_API virtual SFileRef CombineFile(const TArray<CString>& InComponents) const = 0;
};