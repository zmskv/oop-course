#pragma once
#include "dragon.h"
#include "frog.h"
#include "knight.h"
#include <vector>

class Visitor
{
public:
    virtual void visit(Dragon &dragon) = 0;
    virtual void visit(Frog &frog) = 0;
    virtual void visit(Knight &knight) = 0;
};
