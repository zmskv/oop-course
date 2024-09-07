#include "../include/isCleanNumber.h"

bool isCleanNumber(int number)
{
    int last_digit;
    int prev_digit;
    while (number >= 10)
    {
        last_digit = number % 10;
        number /= 10;
        prev_digit = number % 10;

        if (prev_digit > last_digit)
        {
            return false;
        }
    }

    return true;
}