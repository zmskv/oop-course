#pragma once
#include "../include/figure.h"
#include "../include/point.h"
#include <memory>
#include <iostream>

template <Number T>
class Rhombus : public Figure<T>
{
public:
    Rhombus() = default;
    Rhombus(const Point<T> points[4]);
    Rhombus(const Rhombus &other);
    Rhombus(Rhombus &&other) noexcept;
    Rhombus &operator=(const Rhombus &other);
    Rhombus &operator=(Rhombus &&other) noexcept;

    bool operator==(const Figure<T> &other) const override;
    void getInfo() const override;
    Point<T> geometricCenter() const override;
    operator double() const override;

    template <Number P>
    friend std::ostream &operator<<(std::ostream &os, const Rhombus<P> &rhombus);

    template <Number P>
    friend std::istream &operator>>(std::istream &is, Rhombus<P> &rhombus);

private:
    std::unique_ptr<Point<T>> points[4];
    bool isValidRhombus() const;
};