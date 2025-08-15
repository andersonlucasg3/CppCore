#pragma once

#include "TestSuit.h"

class CArrayTests : public CTestBase
{
	void TestCase() override;

	void TestIntArray();
	void TestSharedPtrArray();
	void TestCopyArray();
};