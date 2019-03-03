#include "Calculator.h"
#include "gtest/gtest.h"

TEST(calculator_test, add)
{
	int a = 2;
	int b = 3;
	Calculator calculator;
	int result = calculator.add(a, b);

	EXPECT_EQ(5, result);
}
