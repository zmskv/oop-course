#include "../include/hexagon.h"
#include "../include/point.h"

Hexagon::Hexagon(const Point points[6])
{
    for (int i = 0; i < 6; ++i)
    {
        this->points[i] = points[i];
    }
    isValidHexagon();
}

Hexagon &Hexagon::operator=(const Hexagon &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 6; ++i)
        {
            points[i] = other.points[i];
        }
    }
    return *this;
}

Hexagon &Hexagon::operator=(Hexagon &&other) noexcept
{
    if (this != &other)
    {
        for (int i = 0; i < 6; ++i)
        {
            points[i] = std::move(other.points[i]);
        }
    }
    return *this;
}

bool Hexagon::operator==(const Figure &other) const
{
    const Hexagon *otherHexagon = dynamic_cast<const Hexagon *>(&other);
    for (int i = 0; i < 6; ++i)
    {
        if (points[i].x != otherHexagon->points[i].x && points[i].y != otherHexagon->points[i].y)
        {
            return false;
        }
    }
    return true;
}

Point Hexagon::geometricCenter() const
{
    double centerX = 0, centerY = 0;
    for (const auto &point : points)
    {
        centerX += point.x;
        centerY += point.y;
    }
    return Point{centerX / 6, centerY / 6};
}

Hexagon::operator double() const
{
    double area = 0;
    for (int i = 0; i < 6; ++i)
    {
        int j = (i + 1) % 6;
        area += points[i].x * points[j].y - points[j].x * points[i].y;
    }
    return std::abs(area) / 2;
}

bool Hexagon::isValidHexagon() const
{
    const double epsilon = 1e-6;
    double sideLength = std::sqrt(std::pow(points[1].x - points[0].x, 2) + std::pow(points[1].y - points[0].y, 2));

    for (int i = 1; i < 6; ++i)
    {
        int next = (i + 1) % 6;
        double currentSide = std::sqrt(std::pow(points[next].x - points[i].x, 2) + std::pow(points[next].y - points[i].y, 2));
        if (std::abs(currentSide - sideLength) > epsilon)
        {
            throw std::invalid_argument("Points do not form a valid hexagon.");
        }
    }

    return true;
}

std::ostream &operator<<(std::ostream &os, const Hexagon &hexagon)
{
    os << "Hexagon: points = ";
    for (const auto &point : hexagon.points)
    {
        os << point << " ";
    }
    return os;
}

std::istream &operator>>(std::istream &is, Hexagon &hexagon)
{
    Point points[6];
    for (int i = 0; i < 6; ++i)
    {
        is >> points[i];
    }
    if (is.fail())
    {
        throw std::invalid_argument("Invalid number of points for Hexagon. Expected 6 points.");
    }
    for (int i = 0; i < 6; ++i)
    {
        hexagon.points[i] = points[i];
    }
    return is;
}

void Hexagon::getInfo() const
{
    std::cout << *this << std::endl;
}