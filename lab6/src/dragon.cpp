#include "../include/dragon.h"

Dragon::Dragon(std::string name, int x, int y) : NPC(name, x, y) {}

void Dragon::accept(Visitor &visitor)
{
    visitor.visit(*this);
}