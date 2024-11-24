#pragma once
#include "npc.h"
#include "visitor.h"

class Dragon : public NPC
{
public:
    Dragon(std::string name, int x, int y);
    void accept(Visitor &visitor) override;
    std::string getType() const override { return "Dragon"; }
};