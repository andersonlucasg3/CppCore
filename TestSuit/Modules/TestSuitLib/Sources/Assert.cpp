#include "Assert.h"

CTestAssertInfo::CTestAssertInfo(
        const std::string& InFileName, 
        const std::string& InFunctionName,
        const int InLineNumber,
        const std::string InExpression) 
:   FileName(InFileName)
,   FunctionName(InFunctionName)
,   LineNumber(InLineNumber)
,   Expression(InExpression)
{
    //
}

bool CAssert::HasAnyFailures() const
{
    return _failedTestCases.size() > 0;
}