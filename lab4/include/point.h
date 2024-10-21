#pragma once
#include <concepts>
#include <type_traits>
#include <memory>
#include <iostream>

template <typename T>
concept Number = std::is_integral_v<T> || std::is_floating_point_v<T>;

template <Number T>
class Point
{
public:
    Point() : x(0), y(0) {}
    Point(T x, T y) : x(x), y(y) {}
    T getX() const { return x; }
    T getY() const { return y; }

    friend std::ostream &operator<<(std::ostream &os, const Point &point)
    {
        os << "(" << point.x << ", " << point.y << ")";
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Point &point)
    {
        is >> point.x >> point.y;
        return is;
    }

    bool operator==(const Point &other) const
    {
        return (x == other.x && y == other.y);
    }

private:
    T x, y;
};