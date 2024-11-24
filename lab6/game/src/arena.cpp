#include "../include/arena.h"
#include "../include/battle_visitor.h"
#include <algorithm>
#include <fstream>
#include <sstream>

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

void Arena::spawnNPC(const std::string &type, const std::string &name, int x = -1, int y = -1)
{
    if (x == -1 || y == -1)
    {
        x = randomCoordinate(0, width);
        y = randomCoordinate(0, height);
    }

    auto npc = NPCFactory::createNPC(type, name, x, y);
    if (npc)
    {
        addNPC(std::move(npc));
    }
    else
    {
        std::cerr << "Failed to spawn NPC of type: " << type << "\n";
    }
}

int Arena::randomCoordinate(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

void Arena::saveNPCsToFile(const std::string &filename)
{
    std::ofstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Unable to open file for saving NPCs");
    }
    for (const auto &npc : npcs)
    {
        file << npc->getName() << " " << npc->getX() << " " << npc->getY() << " " << npc->getType() << "\n";
    }
    file.close();
}

void Arena::loadNPCsFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Unable to open file for loading NPCs");
    }
    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string name, type;
        int x, y;
        iss >> name >> x >> y >> type;
        if (type == "Dragon")
        {
            addNPC(std::make_unique<Dragon>(name, x, y));
        }
        else if (type == "Frog")
        {
            addNPC(std::make_unique<Frog>(name, x, y));
        }
        else if (type == "Knight")
        {
            addNPC(std::make_unique<Knight>(name, x, y));
        }
    }
    file.close();
}

void Arena::printNPCs() const
{
    for (const auto &npc : npcs)
    {
        std::cout << "Type: " << npc->getType()
                  << ", Name: " << npc->getName()
                  << ", Coordinates: (" << npc->getX() << ", " << npc->getY() << ")\n";
    }
}