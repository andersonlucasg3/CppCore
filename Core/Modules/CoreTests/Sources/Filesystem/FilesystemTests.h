#pragma once

#include "TestBase.h"

class CFilesystemTests : public CTestBase
{
    void TestCase() override;

    void TestFiles();
    void TestDirectories();
};