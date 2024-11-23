#include <memory>
#include "npc.h"
#include "dragon.h"
#include "knight.h"
#include "frog.h"

class NPCFactory
{
public:
    static std::unique_ptr<NPC> createNPC(const std::string &type, const std::string &name, int x, int y)
    {
        if (type == "Dragon")
            return std::make_unique<Dragon>(name, x, y);
        if (type == "Frog")
            return std::make_unique<Frog>(name, x, y);
        if (type == "Knight")
            return std::make_unique<Knight>(name, x, y);
        return nullptr;
    }
};