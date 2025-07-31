#pragma once

#include "Filesystem/FilesystemReference.h"
#include "Templates/SmartPointer/SharedPointer.h"

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
    CFileReference(const CString& InPath) : Super(InPath) { }
    ~CFileReference() override = default;
};