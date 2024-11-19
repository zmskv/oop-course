#include "../include/frog.h"

Frog::Frog(std::string name, int x, int y) : NPC(name, x, y) {}

void Frog::accept(Visitor &visitor)
{
    visitor.visit(*this);
}