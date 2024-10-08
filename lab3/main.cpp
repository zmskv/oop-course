#include <iostream>
#include "./src/rhombus.cpp"
#include "./src/hexagon.cpp"
#include "./src/pentagon.cpp"

int main()
{
    Point rhombusPoints[4] = {
        {0.0, 1.0},
        {1.0, 0.0},
        {0.0, -1.0},
        {-1.0, 0.0}};
    Rhombus rhombus(rhombusPoints);

    Point pentagonPoints[5] = {
        {1.0, 0.0},
        {0.309016994, 0.951056516},
        {-0.809016994, 0.587785252},
        {-0.809016994, -0.587785252},
        {0.309016994, -0.951056516}};
    Pentagon pentagon(pentagonPoints);

    Point hexagonPoints[6] = {
        {1.0, 0.0},
        {0.5, std::sqrt(3) / 2},
        {-0.5, std::sqrt(3) / 2},
        {-1.0, 0.0},
        {-0.5, -std::sqrt(3) / 2},
        {0.5, -std::sqrt(3) / 2}};
    Hexagon hexagon(hexagonPoints);

    std::cout << "Geometric center Rhombus: " << rhombus.geometricCenter() << std::endl;
    std::cout << "Area Rhombus: " << static_cast<double>(rhombus) << std::endl;
    std::cout << "Geometric center Pentagon: " << pentagon.geometricCenter() << std::endl;
    std::cout << "Area Pentagon: " << static_cast<double>(pentagon) << std::endl;
    std::cout << "Geometric center Hexagon: " << hexagon.geometricCenter() << std::endl;
    std::cout << "Area Hexagon: " << static_cast<double>(hexagon) << std::endl;

    Figure *arr[] = {
        &rhombus,
        &pentagon,
        &hexagon,
    };

    for (auto value : arr)
    {
        value->getInfo();
    }

    return 0;
}