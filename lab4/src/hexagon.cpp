#include "../include/hexagon.h"
#include "../include/point.h"

template <Number T>
Hexagon<T>::Hexagon(const Point<T> points[6])
{
    for (int i = 0; i < 6; ++i)
    {
        this->points[i] = std::make_unique<Point<T>>(points[i]);
    }
    isValidHexagon();
}

template <Number T>
Hexagon<T>::Hexagon(const Hexagon &other)
{
    for (int i = 0; i < 6; ++i)
    {
        points[i] = std::make_unique<Point<T>>(*other.points[i]);
    }
}

template <Number T>
Hexagon<T>::Hexagon(Hexagon &&other) noexcept
{
    for (int i = 0; i < 6; ++i)
    {
        points[i] = std::move(other.points[i]);
    }
}

template <Number T>
Hexagon<T> &Hexagon<T>::operator=(const Hexagon &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 6; ++i)
        {
            points[i] = std::make_unique<Point<T>>(*other.points[i]);
        }
    }
    return *this;
}

template <Number T>
Hexagon<T> &Hexagon<T>::operator=(Hexagon &&other) noexcept
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

template <Number T>
bool Hexagon<T>::operator==(const Figure<T> &other) const
{
    const Hexagon *otherHexagon = dynamic_cast<const Hexagon *>(&other);
    if (!otherHexagon)
        return false;
    for (int i = 0; i < 6; ++i)
    {
        if (*points[i] != *otherHexagon->points[i])
            return false;
    }
    return true;
}

template <Number T>
Point<T> Hexagon<T>::geometricCenter() const
{
    T centerX = 0, centerY = 0;
    for (const auto &point : points)
    {
        centerX += point->getX();
        centerY += point->getY();
    }
    return Point<T>{centerX / 6, centerY / 6};
}

template <Number T>
Hexagon<T>::operator double() const
{
    double area = 0;
    for (int i = 0; i < 6; ++i)
    {
        int j = (i + 1) % 6;
        area += points[i]->getX() * points[j]->getY() - points[j]->getX() * points[i]->getY();
    }
    return std::abs(area) / 2;
}

template <Number T>
bool Hexagon<T>::isValidHexagon() const
{
    const double epsilon = 1e-3;
    double sideLength = std::sqrt(std::pow(points[1]->getX() - points[0]->getX(), 2) + std::pow(points[1]->getY() - points[0]->getY(), 2));

    for (int i = 1; i < 6; ++i)
    {
        int next = (i + 1) % 6;
        double currentSide = std::sqrt(std::pow(points[next]->getX() - points[i]->getX(), 2) + std::pow(points[next]->getY() - points[i]->getY(), 2));
        if (std::abs(currentSide - sideLength) > epsilon)
        {
            throw std::invalid_argument("Points do not form a valid hexagon.");
        }
    }

    return true;
}

template <Number T>
std::ostream &operator<<(std::ostream &os, const Hexagon<T> &hexagon)
{
    os << "Hexagon: points = ";
    for (const auto &point : hexagon.points)
    {
        os << *point << " ";
    }
    return os;
}

template <Number T>
std::istream &operator>>(std::istream &is, Hexagon<T> &hexagon)
{
    Point<T> points[6];
    for (int i = 0; i < 6; ++i)
    {
        is >> points[i];
    }
    for (int i = 0; i < 6; ++i)
    {
        hexagon.points[i] = std::make_unique<Point<T>>(points[i]);
    }
    return is;
}

template <Number T>
void Hexagon<T>::getInfo() const
{
    std::cout << *this << std::endl;
}