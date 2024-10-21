#include "../include/rhombus.h"
#include "../include/point.h"

template <Number T>
Rhombus<T>::Rhombus(const Point<T> points[4])
{
    for (int i = 0; i < 4; ++i)
    {
        this->points[i] = std::make_unique<Point<T>>(points[i]);
    }
    isValidRhombus();
}

template <Number T>
Rhombus<T>::Rhombus(const Rhombus &other)
{
    for (int i = 0; i < 4; ++i)
    {
        points[i] = std::make_unique<Point<T>>(*other.points[i]);
    }
}

template <Number T>
Rhombus<T>::Rhombus(Rhombus &&other) noexcept
{
    for (int i = 0; i < 4; ++i)
    {
        points[i] = std::move(other.points[i]);
    }
}

template <Number T>
Rhombus<T> &Rhombus<T>::operator=(const Rhombus &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 4; ++i)
        {
            points[i] = std::make_unique<Point<T>>(*other.points[i]);
        }
    }
    return *this;
}

template <Number T>
Rhombus<T> &Rhombus<T>::operator=(Rhombus &&other) noexcept
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

template <Number T>
bool Rhombus<T>::operator==(const Figure<T> &other) const
{
    const Rhombus *otherRhombus = dynamic_cast<const Rhombus *>(&other);
    if (!otherRhombus)
        return false;
    for (int i = 0; i < 4; ++i)
    {
        if (*points[i] != *otherRhombus->points[i])
            return false;
    }
    return true;
}

template <Number T>
Point<T> Rhombus<T>::geometricCenter() const
{
    T centerX = (points[0]->getX() + points[2]->getX()) / 2.0;
    T centerY = (points[0]->getY() + points[2]->getY()) / 2.0;
    return Point<T>{centerX, centerY};
}

template <Number T>
Rhombus<T>::operator double() const
{
    double d1 = std::sqrt(std::pow(points[1]->getX() - points[0]->getX(), 2) + std::pow(points[1]->getY() - points[0]->getY(), 2));
    double d2 = std::sqrt(std::pow(points[2]->getX() - points[1]->getX(), 2) + std::pow(points[2]->getY() - points[1]->getY(), 2));
    return 0.5 * d1 * d2;
}

template <Number T>
bool Rhombus<T>::isValidRhombus() const
{
    const double epsilon = 1e-3;
    double sideLength = std::sqrt(std::pow(points[1]->getX() - points[0]->getX(), 2) + std::pow(points[1]->getY() - points[0]->getY(), 2));

    for (int i = 1; i < 4; ++i)
    {
        int next = (i + 1) % 4;
        double currentSide = std::sqrt(std::pow(points[next]->getX() - points[i]->getX(), 2) + std::pow(points[next]->getY() - points[i]->getY(), 2));
        if (std::abs(currentSide - sideLength) > epsilon)
        {
            throw std::invalid_argument("Points do not form a valid rhombus.");
        }
    }

    return true;
}

template <Number T>
std::ostream &operator<<(std::ostream &os, const Rhombus<T> &rhombus)
{
    os << "Rhombus: points = ";
    for (const auto &point : rhombus.points)
    {
        os << *point << " ";
    }
    return os;
}

template <Number T>
std::istream &operator>>(std::istream &is, Rhombus<T> &rhombus)
{
    Point<T> points[4];
    for (int i = 0; i < 4; ++i)
    {
        is >> points[i];
    }
    for (int i = 0; i < 4; ++i)
    {
        rhombus.points[i] = std::make_unique<Point<T>>(points[i]);
    }
    return is;
}

template <Number T>
void Rhombus<T>::getInfo() const
{
    std::cout << *this << std::endl;
}