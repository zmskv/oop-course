#include "../include/pentagon.h"
#include "../include/point.h"
#include <memory>

template <Number T>
Pentagon<T>::Pentagon(const Point<T> points[5])
{
    for (int i = 0; i < 5; ++i)
    {
        this->points[i] = std::make_unique<Point<T>>(points[i]);
    }
    isValidPentagon();
}

template <Number T>
Pentagon<T>::Pentagon(const Pentagon &other)
{
    for (int i = 0; i < 5; ++i)
    {
        points[i] = std::make_unique<Point<T>>(*other.points[i]);
    }
}

template <Number T>
Pentagon<T>::Pentagon(Pentagon &&other) noexcept
{
    for (int i = 0; i < 5; ++i)
    {
        points[i] = std::move(other.points[i]);
    }
}

template <Number T>
Pentagon<T> &Pentagon<T>::operator=(const Pentagon &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 5; ++i)
        {
            points[i] = std::make_unique<Point<T>>(*other.points[i]);
        }
    }
    return *this;
}

template <Number T>
Pentagon<T> &Pentagon<T>::operator=(Pentagon &&other) noexcept
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

template <Number T>
bool Pentagon<T>::operator==(const Figure<T> &other) const
{
    const Pentagon *otherPentagon = dynamic_cast<const Pentagon *>(&other);
    if (!otherPentagon)
        return false;
    for (int i = 0; i < 5; ++i)
    {
        if (*points[i] != *otherPentagon->points[i])
            return false;
    }
    return true;
}

template <Number T>
Point<T> Pentagon<T>::geometricCenter() const
{
    T centerX = 0, centerY = 0;
    for (const auto &point : points)
    {
        centerX += point->getX();
        centerY += point->getY();
    }
    return Point<T>{centerX / 5, centerY / 5};
}

template <Number T>
Pentagon<T>::operator double() const
{
    double area = 0;
    for (int i = 0; i < 5; ++i)
    {
        int j = (i + 1) % 5;
        area += points[i]->getX() * points[j]->getY() - points[j]->getX() * points[i]->getY();
    }
    return std::abs(area) / 2;
}

template <Number T>
bool Pentagon<T>::isValidPentagon() const
{
    const double epsilon = 1e-3;
    double sideLength = std::sqrt(std::pow(points[1]->getX() - points[0]->getX(), 2) + std::pow(points[1]->getY() - points[0]->getY(), 2));

    for (int i = 1; i < 5; ++i)
    {
        int next = (i + 1) % 5;
        double currentSide = std::sqrt(std::pow(points[next]->getX() - points[i]->getX(), 2) + std::pow(points[next]->getY() - points[i]->getY(), 2));
        if (std::abs(currentSide - sideLength) > epsilon)
        {
            throw std::invalid_argument("Points do not form a valid pentagon.");
        }
    }

    return true;
}

template <Number T>
std::ostream &operator<<(std::ostream &os, const Pentagon<T> &pentagon)
{
    os << "Pentagon: points = ";
    for (const auto &point : pentagon.points)
    {
        os << *point << " ";
    }
    return os;
}

template <Number T>
std::istream &operator>>(std::istream &is, Pentagon<T> &pentagon)
{
    Point<T> points[5];
    for (int i = 0; i < 5; ++i)
    {
        is >> points[i];
    }
    for (int i = 0; i < 5; ++i)
    {
        pentagon.points[i] = std::make_unique<Point<T>>(points[i]);
    }
    return is;
}

template <Number T>
void Pentagon<T>::getInfo() const
{
    std::cout << *this << std::endl;
}