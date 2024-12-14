#include "../include/dragon.h"

Dragon::Dragon(std::string name, int x, int y)
    : NPC(name, x, y, 50, 30) {}

void Dragon::accept(Visitor &visitor)
{
    visitor.visit(*this);
}

void Dragon::move()
{
    int dx = rand() % (2 * movementDistance + 1) - movementDistance;
    int dy = rand() % (2 * movementDistance + 1) - movementDistance;
    x = std::max(0, std::min(x + dx, 100));
    y = std::max(0, std::min(y + dy, 100));
}

bool Dragon::canAttack(NPC *other)
{
    int dx = std::abs(x - other->getX());
    int dy = std::abs(y - other->getY());
    return (dx + dy) <= attackRange;
}