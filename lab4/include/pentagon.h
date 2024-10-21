#pragma once
#include "../include/figure.h"
#include "../include/point.h"
#include <memory>
#include <iostream>

template <Number T>
class Pentagon : public Figure<T>
{
public:
    Pentagon() = default;
    Pentagon(const Point<T> points[5]);
    Pentagon(const Pentagon &other);
    Pentagon(Pentagon &&other) noexcept;
    Pentagon &operator=(const Pentagon &other);
    Pentagon &operator=(Pentagon &&other) noexcept;

    bool operator==(const Figure<T> &other) const override;
    void getInfo() const override;
    Point<T> geometricCenter() const override;
    operator double() const override;

    template <Number P>
    friend std::ostream &operator<<(std::ostream &os, const Pentagon<P> &pentagon);

    template <Number P>
    friend std::istream &operator>>(std::istream &is, Pentagon<P> &pentagon);

private:
    std::unique_ptr<Point<T>> points[5];
    bool isValidPentagon() const;
};