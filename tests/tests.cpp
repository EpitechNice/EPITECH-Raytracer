#include <gtest/gtest.h>

TEST(TestType, TestName)
{
    EXPECT_EQ("Hello", "Hello") << "Both strings are not the same !"; // Excpect are prefered, as they do NOT generate fatal errors
    EXPECT_NE("Hello", "World") << "Both strings are the same !"; // EQ : equal; NE : not equal
}

// You might also define functions this way :
testing::AssertionResult IsEven(int n)
{
  if ((n % 2) == 0)
    return testing::AssertionSuccess() << n << " is even";
  else
    return testing::AssertionFailure() << n << " is odd";
}
// So when running tests, these will be displayed

TEST(TestType, IsEven)
{
    EXPECT_TRUE(IsEven(8));
    EXPECT_TRUE(IsEven(7));
}