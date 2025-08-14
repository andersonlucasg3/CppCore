#include "FixedTests.h"

#include "Assert.h"
#include "Defines/Types.h"
#include "Math/Fixed.h"
#include "Math/Math.h"

#include "Templates/Strings.h"

using namespace Core::Types;
using namespace Core::Maths;

void CFixedTests::TestCase()
{
    ASSERT_EQUAL((Int8)10 * SFixed::Precision, 10 * SFixed::Precision);

    SFixed Fixed = 1;
    
    // Sum
    SFixed Result = Fixed + 10;
    ASSERT_EQUAL((Double)Result, 11.);

    // Sub
    Result = Fixed - 22;
    ASSERT_EQUAL((Double)Result, -21.);

    Fixed = 2;

    // Multi
    Result = Fixed * 0.5;
    ASSERT_EQUAL((Double)Result, 1);

    Result = Fixed * 2;
    ASSERT_EQUAL((Double)Result, 4);
    
    // Div
    Result = Fixed / 0.5;
    ASSERT_EQUAL((Double)Result, 4);

    Fixed = 0;

    Fixed += 100;
    ASSERT_EQUAL((Double)Fixed, 100);

    Fixed -= 50;
    ASSERT_EQUAL((Double)Fixed, 50);

    Fixed += 75;
    Fixed *= 125;
    ASSERT_EQUAL((Double)Fixed, 15625);

    Fixed /= 125;
    ASSERT_EQUAL((Double)Fixed, 125);

    TestMath();
}

void CFixedTests::TestMath()
{
    ASSERT_EQUAL(SFMath::Abs(1), 1);
    ASSERT_EQUAL(SFMath::Abs(-1), 1);

    ASSERT_EQUAL(SFMath::CopySign(SFMath::PI, 1.0),    SFMath::PI);
    ASSERT_EQUAL(SFMath::CopySign(SFMath::PI, -1.0),   -SFMath::PI);
    ASSERT_EQUAL(SFMath::CopySign(-2.71828182, 1.0), 2.71828182);
    ASSERT_EQUAL(SFMath::CopySign(-2.71828182, -1.0), -2.71828182);
    ASSERT_EQUAL(SFMath::CopySign(0.0, -1.0),         -0.0);
    ASSERT_EQUAL(SFMath::CopySign(-0.0, 1.0),         0.0);

    ASSERT_EQUAL(SFMath::Cos(0.0),                1.0);
    ASSERT_EQUAL(SFMath::Cos(SFMath::HalfPI),      0.0);
    ASSERT_EQUAL(SFMath::Cos(SFMath::PI),          -1.0);
    ASSERT_EQUAL(SFMath::Cos(SFMath::ThreeHalfPI), 0.0);
    ASSERT_EQUAL(SFMath::Cos(SFMath::TwoPI),       1.0);

    ASSERT_EQUAL(SFMath::Sin(0.0),                0.0);
    ASSERT_EQUAL(SFMath::Sin(SFMath::HalfPI),      1.0);
    ASSERT_EQUAL(SFMath::Sin(SFMath::PI),          0.0);
    ASSERT_EQUAL(SFMath::Sin(SFMath::ThreeHalfPI), -1.0);
    ASSERT_EQUAL(SFMath::Sin(SFMath::TwoPI),       0.0);

    ASSERT_EQUAL(SFMath::Asin(0.0), 0.0);
    ASSERT_EQUAL(SFMath::Asin(0.5), std::asin(0.5));
    ASSERT_EQUAL(SFMath::Asin(1.0), std::asin(1.0));

    ASSERT_EQUAL(SFMath::Tan(0.0), 0.0);
    ASSERT_EQUAL(SFMath::Tan(SFMath::HalfHalfPI), std::tan(M_PI_4)); // due to precision shit
    ASSERT_EQUAL(SFMath::Tan(SFMath::PI), 0.0);
    // ASSERT_EQUAL(SFMath::Tan(SFMath::ThreeHalfPI), undefined);
    ASSERT_EQUAL(SFMath::Tan(SFMath::TwoPI), 0.0);

    ASSERT_EQUAL(SFMath::Atan2(0.0, 1.0), 0.0);
    ASSERT_EQUAL(SFMath::Atan2(1.0, 1.0), std::atan2(1.0, 1.0));
    ASSERT_EQUAL(SFMath::Atan2(1.0, 0.0), std::atan2(1.0, 0.0));
    ASSERT_EQUAL(SFMath::Atan2(0.0, -1.0), std::atan2(0.0, -1.0));
    ASSERT_EQUAL(SFMath::Atan2(-1.0, -1.0), std::atan2(-1.0, -1.0));
    ASSERT_EQUAL(SFMath::Atan2(-1.0, 0.0), std::atan2(-1.0, 0.0));

    ASSERT_EQUAL(SFMath::Sqrt(0.0), 0.0);
    ASSERT_EQUAL(SFMath::Sqrt(1.0), 1.0);
    ASSERT_EQUAL(SFMath::Sqrt(4.0), 2.0);
    ASSERT_EQUAL(SFMath::Sqrt(9.0), 3.0);
    ASSERT_EQUAL(SFMath::Sqrt(16.0), 4.0);
    ASSERT_EQUAL(SFMath::Sqrt(25.0), 5.0);
    ASSERT_EQUAL(SFMath::Sqrt(100.0), 10.0);
    ASSERT_EQUAL(SFMath::Sqrt(0.25), 0.5);
    ASSERT_EQUAL(SFMath::Sqrt(0.5), std::sqrt(0.5));
    ASSERT_EQUAL(SFMath::Sqrt(0.75), std::sqrt(0.75));
    ASSERT_EQUAL(SFMath::Sqrt(1.25), std::sqrt(1.25));
    ASSERT_EQUAL(SFMath::Sqrt(2.5), std::sqrt(2.5));
    ASSERT_EQUAL(SFMath::Sqrt(3.75), std::sqrt(3.75));
    ASSERT_EQUAL(SFMath::Sqrt(6.25), std::sqrt(6.25));
}

REGISTER_TEST_CLASS(FixedTests);
