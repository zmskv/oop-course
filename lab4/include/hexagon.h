#pragma once
#include "../include/figure.h"
#include "../include/point.h"
#include <memory>
#include <iostream>

template <Number T>
class Hexagon : public Figure<T>
{
public:
    Hexagon() = default;
    Hexagon(const Point<T> points[6]);
    Hexagon(const Hexagon &other);
    Hexagon(Hexagon &&other) noexcept;
    Hexagon &operator=(const Hexagon &other);
    Hexagon &operator=(Hexagon &&other) noexcept;

    bool operator==(const Figure<T> &other) const override;
    void getInfo() const override;
    Point<T> geometricCenter() const override;
    operator double() const override;

    template <Number P>
    friend std::ostream &operator<<(std::ostream &os, const Hexagon<P> &hexagon);

    template <Number P>
    friend std::istream &operator>>(std::istream &is, Hexagon<P> &hexagon);

private:
    std::unique_ptr<Point<T>> points[6];
    bool isValidHexagon() const;
};