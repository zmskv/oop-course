#include "../include/pentagon.h"
#include "../include/point.h"

Pentagon::Pentagon(const Point points[5])
{
    for (int i = 0; i < 5; ++i)
    {
        this->points[i] = points[i];
    }
    isValidPentagon();
}

Pentagon &Pentagon::operator=(const Pentagon &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 5; ++i)
        {
            points[i] = other.points[i];
        }
    }
    return *this;
}

Pentagon &Pentagon::operator=(Pentagon &&other) noexcept
{
    if (this != &other)
    {
        for (int i = 0; i < 5; ++i)
        {
            points[i] = std::move(other.points[i]);
        }
    }
    return *this;
}

bool Pentagon::operator==(const Figure &other) const
{
    const Pentagon *otherPentagon = dynamic_cast<const Pentagon *>(&other);
    if (!otherPentagon)
        return false;
    for (int i = 0; i < 5; ++i)
    {
        if (points[i].x != otherPentagon->points[i].x && points[i].y != otherPentagon->points[i].y)
        {
            return false;
        }
    }
    return true;
}

Point Pentagon::geometricCenter() const
{
    double centerX = 0, centerY = 0;
    for (const auto &point : points)
    {
        centerX += point.x;
        centerY += point.y;
    }
    return Point{centerX / 5, centerY / 5};
}

Pentagon::operator double() const
{
    double area = 0;
    for (int i = 0; i < 5; ++i)
    {
        int j = (i + 1) % 5;
        area += points[i].x * points[j].y - points[j].x * points[i].y;
    }
    return std::abs(area) / 2;
}

bool Pentagon::isValidPentagon() const
{
    const double epsilon = 1e-3;
    double sideLength = std::sqrt(std::pow(points[1].x - points[0].x, 2) + std::pow(points[1].y - points[0].y, 2));

    for (int i = 1; i < 5; ++i)
    {
        int next = (i + 1) % 5;
        double currentSide = std::sqrt(std::pow(points[next].x - points[i].x, 2) + std::pow(points[next].y - points[i].y, 2));
        if (std::abs(currentSide - sideLength) > epsilon)
        {
            throw std::invalid_argument("Points do not form a valid pentagon.");
        }
    }

    return true;
}

std::ostream &operator<<(std::ostream &os, const Pentagon &pentagon)
{
    os << "Pentagon: points = ";
    for (const auto &point : pentagon.points)
    {
        os << point << " ";
    }
    return os;
}

std::istream &operator>>(std::istream &is, Pentagon &pentagon)
{
    Point points[5];
    for (int i = 0; i < 5; ++i)
    {
        is >> points[i];
    }
    if (is.fail())
    {
        throw std::invalid_argument("Invalid number of points for Pentagon. Expected 5 points.");
    }
    for (int i = 0; i < 5; ++i)
    {
        pentagon.points[i] = points[i];
    }
    return is;
}

void Pentagon::getInfo() const
{
    std::cout << *this << std::endl;
}