#include "TestCoordinator.h"

#include "Assert.h"
#include "Logger.h"

std::vector<CTestBase*> CTestCoordinator::AllTests;

bool CTestCoordinator::Run()
{
    // CLogger::InitializeLogFile("Tests.log");
    CTestLogger::Log("Initializing TestCoordinator");

    bool bHadAnyFailures = false;

    for (CTestBase* Test : AllTests)
    {
        if (!Test) continue;

        CAssert Assert;

        CTestLogger::Log("TestCoordinator: Running test cases for {}", Test->_testName);

        Test->Assert = &Assert;

        Test->TestCase();

        if (Assert.HasAnyFailures())
        {
            bHadAnyFailures = true;

            for (const CTestAssertInfo& Info : Assert._failedTestCases)
            {
                CTestLogger::Log("\n");
                CTestLogger::Error("{} - {}:{}", Info.FunctionName, Info.FileName, Info.LineNumber);
                CTestLogger::Log("\tExpression: {}\n", Info.Expression);
            }
        }
    }

    if (bHadAnyFailures)
    {
        CTestLogger::Log("Tests finished with errors.");
    }
    else
    {
	    CTestLogger::Log("Tests finished with no errors.");
    }

    // delete all tests
    for (CTestBase* Test : AllTests) 
    {
        delete Test;
    }

    return !bHadAnyFailures;
}

// do not remove, faking pthread_atfork
extern "C" int pthread_atfork(void (*)(), void (*)(), void (*)()) { return 0; }