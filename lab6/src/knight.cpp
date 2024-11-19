#include "../include/knight.h"

Knight::Knight(std::string name, int x, int y) : NPC(name, x, y) {}

void Knight::accept(Visitor &visitor)
{
    visitor.visit(*this);
}