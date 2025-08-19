#pragma once

#include "TestBase.h"
#include "Assert.h"

#include <vector>

class CTestCoordinator
{
    TESTSUITLIB_API static std::vector<CTestBase*> AllTests;

    CTestCoordinator() = delete;
    ~CTestCoordinator() = delete;

public:
    TESTSUITLIB_API static bool Run();
    TESTSUITLIB_API static void Shutdown();

    template<typename TTest = CTestBase>
    static TTest* RegisterTestClass(const char* TestClassName)
    {
        TTest* Test = new TTest();
        Test->_testName = TestClassName;
        AllTests.push_back(Test);
        return Test;
    }

    template<typename TTest>
    friend class TTestBase;
};