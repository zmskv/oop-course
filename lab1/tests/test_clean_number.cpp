#include <gtest/gtest.h>
#include "../src/clean_number.cpp"

TEST(TestSet, CorrectCleanNumber)
{   
    // arrange
    int number = 123;
    // act
    bool result = isCleanNumber(number);
    // assert
    ASSERT_TRUE(result);
}

TEST(TestSet, WrongCleanNumber)
{
    // arrange
    int number = 321;
    // act
    bool result = isCleanNumber(number);
    // assert
    ASSERT_FALSE(result);
}

TEST(TestSet, NegativeCorrectCleanNumber)
{
    // arrange
    int number = -123;
    // act
    bool result = isCleanNumber(number);
    // assert
    ASSERT_TRUE(result);
}

TEST(CleanNumberTest04, NegativeWrongCleanNumber)
{
    // arrange
    int number = 543;
    // act
    bool result = isCleanNumber(number);
    // assert
    ASSERT_FALSE(result);
}