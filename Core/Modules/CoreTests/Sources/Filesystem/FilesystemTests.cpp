#include "FilesystemTests.h"

#include "TestSuit.h"

#include "Defines/Asserts.h"
#include "Defines/Types.h"
#include "Filesystem/Path.h"
#include "Filesystem/DirectoryReference.h"
#include "Filesystem/FileReference.h"
#include "Process/Process.h"

REGISTER_TEST_CLASS(FilesystemTests);

void TestFiles()
{
    SFileRef Ref = "./Text.txt";

    const CString& Path = Ref->Path();
    CString Combined = GPath.Combine({ GProcess.GetContainerPath(), "Text.txt" });

    bool bEqual = Path == Combined;

    assert(bEqual);
    assert_equal(Path, Combined);
    assert(!Ref->Exists());

    SFileRef ExistingRef = "./EngineTests";

    assert(ExistingRef->Exists());
}

void TestDirectories()
{
    SDirectoryRef Ref = ".";

    const CString& Path = Ref->Path();
    const CString& Combined = GProcess.GetContainerPath();
    
    bool bEqual = Path == Combined;
    assert(bEqual);
    assert_equal(Path, Combined);
    assert(Ref->Exists());

    SDirectoryRef CreateRef = "./Temp";

    assert(CreateRef->Create(true));
    assert(CreateRef->Exists());

    assert(CreateRef->Delete());
    assert(!CreateRef->Exists());
}

void CFilesystemTests::TestCase()
{
    TestFiles();
    TestDirectories();
}