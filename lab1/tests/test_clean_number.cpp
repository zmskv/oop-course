#include <gtest/gtest.h>
#include "../src/clean_number.cpp"

TEST(CleanNumberTest01, TestSet)
{
    ASSERT_TRUE(isCleanNumber(123));
}

TEST(CleanNumberTest02, TestSet)
{
    ASSERT_FALSE(isCleanNumber(321));
}

TEST(CleanNumberTest03, TestSet)
{
    ASSERT_FALSE(isCleanNumber(901));
}

TEST(CleanNumberTest04, TestSet)
{
    ASSERT_TRUE(isCleanNumber(345));
}

TEST(CleanNumberTest05, TestSet)
{
    ASSERT_FALSE(isCleanNumber(812));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}