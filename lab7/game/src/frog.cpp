#include "../include/frog.h"

Frog::Frog(std::string name, int x, int y)
    : NPC(name, x, y, 1, 10) {}

void Frog::accept(Visitor &visitor)
{
    visitor.visit(*this);
}

void Frog::move()
{
    int new_x = x + rand() % (2 * movementDistance + 1) - movementDistance;
    new_x = std::max(0, std::min(100, new_x));
    int new_y = y + rand() % (2 * movementDistance + 1) - movementDistance;
    new_y = std::max(0, std::min(100, new_y));
    x = new_x;
    y = new_y;
}

bool Frog::canAttack(NPC *other)
{
    int dx = std::abs(x - other->getX());
    int dy = std::abs(y - other->getY());
    return (dx + dy) <= attackRange;
}