#include "../include/arena.h"
#include "../include/battle_visitor.h"
#include <algorithm>

Arena::Arena(int width, int height) : width(width), height(height) {}

void Arena::addNPC(std::unique_ptr<NPC> npc)
{

    npcs.push_back(std::move(npc));
}

void Arena::addObserver(std::shared_ptr<Observer> observer)
{
    observers.push_back(observer);
}

void Arena::startBattle(int range)
{
    std::cout << "Starting battle with range: " << range << std::endl;

    for (auto &observer : observers)
    {
        observer->update("The battle has started with range: " + std::to_string(range));
    }

    BattleVisitor battleVisitor(range, npcs, observers);
    std::vector<NPC *> npcsToVisit;
    for (auto &npc : npcs)
    {
        npcsToVisit.push_back(npc.get());
    }

    for (auto it = npcsToVisit.begin(); it != npcsToVisit.end();)
    {
        NPC *npc = *it;

        auto found = std::find_if(
            npcs.begin(), npcs.end(),
            [npc](const std::unique_ptr<NPC> &original)
            { return original.get() == npc; });

        if (found != npcs.end())
        {
            npc->accept(battleVisitor);
        }

        ++it;
    }

    if (npcs.empty())
    {
        for (auto &observer : observers)
        {
            observer->update("All NPCs have been eliminated. The battle is over.");
        }
    }
    else
    {
        std::string survivors = "The battle is over. Surviving NPCs: ";
        for (const auto &npc : npcs)
        {
            survivors += npc->getName() + " ";
        }
        for (auto &observer : observers)
        {
            observer->update(survivors);
        }
    }
}

void Arena::spawnNPC(const std::string &type, const std::string &name)
{
    int x = randomCoordinate(0, width);
    int y = randomCoordinate(0, height);
    auto npc = NPCFactory::createNPC(type, name, x, y);
    if (npc)
    {
        addNPC(std::move(npc));
    }
}

int Arena::randomCoordinate(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}