#include "../include/npc.h"

NPC::NPC(std::string name, int x, int y, int movementDistance, int attackRange)
    : name(name), x(x), y(y), movementDistance(movementDistance), attackRange(attackRange) {}

std::string NPC::getName() const { return name; }
int NPC::getX() const { return x; }
int NPC::getY() const { return y; }