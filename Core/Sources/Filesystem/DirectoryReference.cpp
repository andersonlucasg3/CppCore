#include "DirectoryReference.h"

#include "Defines/Preprocessors.h"
#include "Filesystem/Path.h"

#include COMPILE_PLATFORM_HEADER(DirectoryReference.h)

static TFunction<TSharedPtr<CPlatformDirectoryReference>(const CString&)> FactoryFunction = [](const CString& InPath)
{
    return MakeShared<CPlatformDirectoryReference>(InPath);
};

SDirectoryRef::SDirectoryRef(const char* InCStr) : SDirectoryRef(CString(InCStr))
{
    //
}

SDirectoryRef::SDirectoryRef(const CString& InPath) : Super()
{
    this->operator=(InPath);
}

SDirectoryRef::SDirectoryRef(const TArray<CString>& InComponents) : Super()
{
    this->operator=(CPlatformDirectoryReference::Get(GPath.Combine(InComponents), FactoryFunction));
}

SDirectoryRef& SDirectoryRef::operator=(const char* InCStr)
{
    this->operator=(CString(InCStr));

    return *this;
}

SDirectoryRef& SDirectoryRef::operator=(const CString& InPath)
{
    this->operator=(CPlatformDirectoryReference::Get(InPath, FactoryFunction));

    return *this;
}

SDirectoryRef& SDirectoryRef::operator=(const TArray<CString>& InComponentes)
{
    this->operator=(CPlatformDirectoryReference::Get(GPath.Combine(InComponentes), FactoryFunction));

    return *this;
}

void SDirectoryRef::operator=(const TSharedPtr<CDirectoryReference>& Other)
{
    Super::operator=(Other);
}