#pragma once
#include "npc.h"
#include "visitor.h"

class Frog : public NPC
{
public:
    Frog(std::string name, int x, int y);
    void accept(Visitor &visitor) override;
    void move() override;
    bool canAttack(NPC *other) override;
    std::string getType() const override { return "Frog"; }
};