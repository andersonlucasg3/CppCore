#pragma once

#include "Assert.h"

class CTestBase
{
    const char* _testName;
    
protected:
    CAssert* Assert;

public:
    virtual ~CTestBase() = default;
    
    virtual void TestCase() = 0;

    friend class CTestCoordinator;
};