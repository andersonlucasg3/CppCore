#pragma once

#include <type_traits>
#include <string>
#include <vector>

class CTestBase;

struct CTestAssertInfo
{
    const std::string FileName;
    const std::string FunctionName;
    const int LineNumber;

    const std::string Expression;

    TESTSUITLIB_API CTestAssertInfo(const std::string& InFileName, const std::string& InFunctionName, const int InLineNumber, const std::string InExpression);
};

class CAssert
{
    std::vector<CTestAssertInfo> _failedTestCases;

    template<typename TLeft, typename TRight>
    constexpr bool IsANumber()
    {
        constexpr bool IsLeftTypeANumber = std::is_floating_point_v<TLeft> || std::is_integral_v<TLeft>;
        constexpr bool IsRightTypeANumber = std::is_floating_point_v<TRight> || std::is_integral_v<TRight>;

        return IsLeftTypeANumber && IsRightTypeANumber;
    }

    bool HasAnyFailures() const;

public:
    CAssert() = default;
    ~CAssert() = default;

    template<typename TLeft, typename TRight>
    void Equal(TLeft InLeftValue, TRight InRightValue, const CTestAssertInfo& Info)
    {
        bool bResult = InLeftValue == InRightValue;

        if (!bResult)
        {
            _failedTestCases.push_back(Info);
        }
    }

    template<typename TLeft, typename TRight>
    void NotEqual(TLeft InLeftValue, TRight InRightValue, const CTestAssertInfo& Info)
    {
        bool bResult = InLeftValue != InRightValue;

        if (!bResult)
        {
            _failedTestCases.push_back(Info);
        }
    }

    template<typename TLeft, typename TRight>
    void Greater(TLeft InLeftValue, TRight InRightValue, bool bAndEqual, const CTestAssertInfo& Info)
    {
        static_assert(IsANumber<TLeft, TRight>());

        bool bResult;

        if (bAndEqual)
        {
            bResult = InLeftValue >= InRightValue;
        }
        else
        {
            bResult = InLeftValue > InRightValue;
        }

        if (!bResult)
        {
            _failedTestCases.push_back(Info);
        }
    }

    template<typename TLeft, typename TRight>
    bool Lesser(TLeft InLeftValue, TRight InRightValue, bool bAndEqual, const CTestAssertInfo& Info)
    {
        static_assert(IsANumber<TLeft, TRight>());
        
        bool bResult;

        if (bAndEqual)
        {
            bResult = InLeftValue <= InRightValue;
        }
        else
        {
            bResult = InLeftValue < InRightValue;
        }

        if (!bResult)
        {
            _failedTestCases.push_back(Info);
        }
    }

    friend class CTestCoordinator;
};

#define LITERAL(a) a
#define TO_STR(a) #a
#define WANTSTR(a) TO_STR(a)
#define ASSERT_CONTEXT(l, symbol, r) { __FILE__, __FUNCTION__, __LINE__, ASSERT_CONCAT_3(l, symbol, r) }
#define ASSERT_CONCAT_2(a, b) a b
#define ASSERT_CONCAT_3(a, s, b) WANTSTR(ASSERT_CONCAT_2(ASSERT_CONCAT_2(a, s), b))

#define ASSERT_TRUE(v)                      Assert->Equal(LITERAL(v), true, ASSERT_CONTEXT(v, ==, true))
#define ASSERT_FALSE(v)                     Assert->Equal(LITERAL(v), false, ASSERT_CONTEXT(v, ==, false))
#define ASSERT_EQUAL(l, r)                  Assert->Equal(LITERAL(l), LITERAL(r), ASSERT_CONTEXT(l, ==, r))
#define ASSERT_NOT_EQUAL(l, r)              Assert->NotEqual(LITERAL(l), LITERAL(r), ASSERT_CONTEXT(l, !=, r))
#define ASSERT_GREATER(l, r)                Assert->Greater(LITERAL(l), LITERAL(r), false, ASSERT_CONTEXT(l, >, r))
#define ASSERT_GREATER_EQUAL(l, r)          Assert->Greater(LITERAL(l), LITERAL(r), true, ASSERT_CONTEXT(l, >=, r))
#define ASSERT_LESSER(l, r)                 Assert->Lesser(LITERAL(l), LITERAL(r), false, ASSERT_CONTEXT(l, <, r))
#define ASSERT_LESSER_EQUAL(l, r)           Assert->Lesser(LITERAL(l), LITERAL(r), true, ASSERT_CONTEXT(l, <=, r))