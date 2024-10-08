#pragma once
#include "../include/figure.h"
#include "../include/point.h"

class Rhombus : public Figure
{
public:
    Rhombus() = default;
    Rhombus(const Point points[4]);
    Rhombus &operator=(const Rhombus &other);
    Rhombus &operator=(Rhombus &&other) noexcept;

    bool operator==(const Figure &other) const override;
    void getInfo() const override;
    Point geometricCenter() const override;
    operator double() const override;

    friend std::ostream &operator<<(std::ostream &os, const Rhombus &rhombus);
    friend std::istream &operator>>(std::istream &is, Rhombus &rhombus);

private:
    Point points[4];
    bool isValidRhombus() const;
};