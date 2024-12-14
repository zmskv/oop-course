#pragma once
#include "arena.h"
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <shared_mutex>

class SynchronizedArena
{
    Arena arena;
    std::shared_mutex npcMutex;
    std::queue<std::pair<NPC *, NPC *>> battleQueue;
    std::mutex battleMutex;
    std::condition_variable battleCV;
    bool gameOver;

public:
    SynchronizedArena(int width, int height);
    void moveNPCs();
    void notifyAllThreads() { battleCV.notify_all(); }
    std::shared_mutex &getNpcMutex() { return npcMutex; }
    void addNPC(std::unique_ptr<NPC> npc) { arena.addNPC(std::move(npc)); }
    void addBattleTask(NPC *attacker, NPC *defender);
    void processBattleTasks();
    std::vector<std::unique_ptr<NPC>> &getNPCs() { return arena.getNPCs(); }
    bool isGameOver() const { return gameOver; }
    void setGameOver(bool value) { gameOver = value; }
};