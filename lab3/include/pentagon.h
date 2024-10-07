#pragma once
#include "../include/figure.h"
#include "../include/point.h"

class Pentagon : public Figure
{
public:
    Pentagon() = default;
    Pentagon(const Point points[5]);
    Pentagon &operator=(const Pentagon &other);
    Pentagon &operator=(Pentagon &&other) noexcept;

    bool operator==(const Figure &other) const override;
    Point geometricCenter() const override;
    operator double() const override;

    friend std::ostream &operator<<(std::ostream &os, const Pentagon &pentagon);
    friend std::istream &operator>>(std::istream &is, Pentagon &pentagon);

private:
    Point points[5];
    bool isValidPentagon() const;
};