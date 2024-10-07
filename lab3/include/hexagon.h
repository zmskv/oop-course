#pragma once
#include "../include/figure.h"
#include "../include/point.h"

class Hexagon : public Figure
{
public:
    Hexagon() = default;
    Hexagon(const Point points[6]);
    Hexagon &operator=(const Hexagon &other);
    Hexagon &operator=(Hexagon &&other) noexcept;

    bool operator==(const Figure &other) const override;
    Point geometricCenter() const override;
    operator double() const override;

    friend std::ostream &operator<<(std::ostream &os, const Hexagon &hexagon);
    friend std::istream &operator>>(std::istream &is, Hexagon &hexagon);

private:
    Point points[6];
    bool isValidHexagon() const;
};