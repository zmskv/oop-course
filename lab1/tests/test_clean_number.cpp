#include <gtest/gtest.h>
#include "../src/clean_number.cpp"

TEST(CleanNumberTest01, TestSet)
{   
    // arange
    int number = 123;
    // act
    bool result = isCleanNumber(number);
    // assert
    ASSERT_TRUE(result);
}

TEST(CleanNumberTest02, TestSet)
{
    // arange
    int number = 321;
    // act
    bool result = isCleanNumber(number);
    // assert
    ASSERT_FALSE(result);
}

TEST(CleanNumberTest03, TestSet)
{
    // arange
    int number = 901;
    // act
    bool result = isCleanNumber(number);
    // assert
    ASSERT_FALSE(result);
}

TEST(CleanNumberTest04, TestSet)
{
    // arange
    int number = 345;
    // act
    bool result = isCleanNumber(number);
    // assert
    ASSERT_TRUE(result);
}

TEST(CleanNumberTest05, TestSet)
{
    // arange
    int number = 812;
    // act
    bool result = isCleanNumber(number);
    // assert
    ASSERT_FALSE(result);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}