#include "../include/rhombus.h"
#include "../include/point.h"

Rhombus::Rhombus(const Point points[4])
{
    for (int i = 0; i < 4; ++i)
    {
        this->points[i] = points[i];
    }
    isValidRhombus();
}

Rhombus &Rhombus::operator=(const Rhombus &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; ++i)
        {
            points[i] = other.points[i];
        }
    }
    return *this;
}

Rhombus &Rhombus::operator=(Rhombus &&other) noexcept
{
    if (this != &other)
    {
        for (int i = 0; i < 4; ++i)
        {
            points[i] = std::move(other.points[i]);
        }
    }
    return *this;
}

bool Rhombus::operator==(const Figure &other) const
{
    const Rhombus *otherRhombus = dynamic_cast<const Rhombus *>(&other);
    if (!otherRhombus)
        return false;
    for (int i = 0; i < 4; ++i)
    {
        if ((points[i].x != otherRhombus->points[i].x) && (points[i].y != otherRhombus->points[i].y))
            return false;
    }
    return true;
}

Point Rhombus::geometricCenter() const
{
    double centerX = (points[0].x + points[2].x) / 2.0;
    double centerY = (points[0].y + points[2].y) / 2.0;

    return Point{centerX, centerY};
}

Rhombus::operator double() const
{
    double d1 = std::sqrt(std::pow(points[1].x - points[0].x, 2) + std::pow(points[1].y - points[0].y, 2));
    double d2 = std::sqrt(std::pow(points[2].x - points[1].x, 2) + std::pow(points[2].y - points[1].y, 2));
    return 0.5 * d1 * d2;
}

bool Rhombus::isValidRhombus() const
{
    double side1 = std::sqrt(std::pow(points[1].x - points[0].x, 2) + std::pow(points[1].y - points[0].y, 2));
    double side2 = std::sqrt(std::pow(points[2].x - points[1].x, 2) + std::pow(points[2].y - points[1].y, 2));
    double side3 = std::sqrt(std::pow(points[3].x - points[2].x, 2) + std::pow(points[3].y - points[2].y, 2));
    double side4 = std::sqrt(std::pow(points[0].x - points[3].x, 2) + std::pow(points[0].y - points[3].y, 2));
    if (!(side1 == side2 == side3 == side4))
    {
        throw std::invalid_argument("Points do not form a valid rhombus.");
    }
    return true;
}

std::ostream &operator<<(std::ostream &os, const Rhombus &rhombus)
{
    os << "Rhombus: points = ";
    for (const auto &point : rhombus.points)
    {
        os << point << " ";
    }
    return os;
}

std::istream &operator>>(std::istream &is, Rhombus &rhombus)
{

    Point points[4];
    for (int i = 0; i < 4; ++i)
    {
        is >> points[i];
    }
    if (is.fail())
    {
        throw std::invalid_argument("Invalid number of points for Rhombus. Expected 4 points.");
    }

    for (int i = 0; i < 4; ++i)
    {
        rhombus.points[i] = points[i];
    }
    return is;
}