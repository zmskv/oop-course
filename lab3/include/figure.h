#pragma once
#include <iostream>
#include <ostream>
#include <cmath>
#include "../include/point.h"

class Figure
{
public:
    virtual ~Figure() noexcept = default;

    virtual void getInfo() const = 0;
    virtual operator double() const = 0;
    virtual bool operator==(const Figure &other) const = 0;
    virtual Point geometricCenter() const = 0;
};
