#include "simple_test.cpp"
#include <gtest/gtest.h>

TEST(AddTest, PositiveNumbers)
{
    EXPECT_EQ(add(2, 3), 5);
}

TEST(AddTest, NegativeNumbers)
{
    EXPECT_EQ(add(-2, -3), -5);
}

TEST(AddTest, MixedNumbers)
{
    EXPECT_EQ(add(2, -3), -1);
    EXPECT_EQ(add(-2, 3), 1);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}