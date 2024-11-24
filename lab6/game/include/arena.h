#pragma once
#include "npc.h"
#include "visitor.h"
#include "observer.h"
#include "npc_factory.h"
#include <vector>
#include <memory>
#include <random>

class Arena
{
public:
    Arena(int width, int height);
    void addNPC(std::unique_ptr<NPC> npc);
    void addObserver(std::shared_ptr<Observer> observer);
    void startBattle(int range);
    void spawnNPC(const std::string &type, const std::string &name, int x, int y);
    void saveNPCsToFile(const std::string &filename);
    void loadNPCsFromFile(const std::string &filename);
    void printNPCs() const;

private:
    int width, height;
    std::vector<std::unique_ptr<NPC>> npcs;
    std::vector<std::shared_ptr<Observer>> observers;

    int randomCoordinate(int min, int max);
};