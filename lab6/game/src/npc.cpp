#include "../include/npc.h"

NPC::NPC(std::string name, int x, int y) : name(name), x(x), y(y) {}

std::string NPC::getName() const { return name; }
int NPC::getX() const { return x; }
int NPC::getY() const { return y; }