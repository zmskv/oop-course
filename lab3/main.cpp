#include <iostream>
#include "./src/rhombus.cpp"



int main(){
    Rhombus rhombus;
    std::cout << "Enter 4 points for Rhombus (format: x1 y1 x2 y2 x3 y3 x4 y4): ";
    try
    {
        std::cin >> rhombus;
        std::cout << "Rhombus created successfully: " << rhombus << std::endl;
        std::cout << "Geometric center: " << rhombus.geometricCenter() << std::endl;
        std::cout << "Area: " << static_cast<double>(rhombus) << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}