#include <iostream>
#include "src/clean_number.cpp"

int main()
{
    int value;
    std::cout << "Enter value:";
    std::cin >> value;

    std::cout << isCleanNumber(value) << std::endl;

    return 0;
}