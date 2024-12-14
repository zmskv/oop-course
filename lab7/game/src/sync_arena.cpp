#include "../include/sync_arena.h"

SynchronizedArena::SynchronizedArena(int width, int height)
    : arena(width, height), gameOver(false) {}

void SynchronizedArena::moveNPCs()
{
    std::scoped_lock<std::shared_mutex> lock(npcMutex);
    for (auto &npc : arena.getNPCs())
    {
        int movement = npc->getMovementDistance();
        int dx = rand() % (2 * movement + 1) - movement;
        int dy = rand() % (2 * movement + 1) - movement;
        npc->setX(std::max(0, std::min(npc->getX() + dx, 100)));
        npc->setY(std::max(0, std::min(npc->getY() + dy, 100)));
    }
    for (size_t i = 0; i < arena.getNPCs().size(); ++i)
    {
        for (size_t j = i + 1; j < arena.getNPCs().size(); ++j)
        {
            NPC *npc1 = arena.getNPCs()[i].get();
            NPC *npc2 = arena.getNPCs()[j].get();
            int dx = npc1->getX() - npc2->getX();
            int dy = npc1->getY() - npc2->getY();
            int distance = std::abs(dx) + std::abs(dy);
            if (distance <= npc1->getAttackRange() && distance <= npc2->getAttackRange())
            {
                addBattleTask(npc1, npc2);
            }
        }
    }
}

void SynchronizedArena::addBattleTask(NPC *attacker, NPC *defender)
{
    std::lock_guard<std::mutex> lock(battleMutex);
    battleQueue.push({attacker, defender});
    battleCV.notify_one();
}

void SynchronizedArena::processBattleTasks()
{
    std::unique_lock<std::mutex> lock(battleMutex);
    battleCV.wait(lock, [this]
                  { return !battleQueue.empty() || gameOver; });
    if (gameOver)
        return;
    auto task = battleQueue.front();
    battleQueue.pop();
    lock.unlock();

    std::unique_lock<std::shared_mutex> npcLock(npcMutex);
    auto it1 = std::find_if(arena.getNPCs().begin(), arena.getNPCs().end(), [task](const std::unique_ptr<NPC> &npc)
                            { return npc.get() == task.first; });
    auto it2 = std::find_if(arena.getNPCs().begin(), arena.getNPCs().end(), [task](const std::unique_ptr<NPC> &npc)
                            { return npc.get() == task.second; });
    if (it1 != arena.getNPCs().end() && it2 != arena.getNPCs().end())
    {
        int attackStrength = rand() % 6 + 1;
        int defenseStrength = rand() % 6 + 1;
        if (attackStrength > defenseStrength)
        {
            arena.getNPCs().erase(it2);
        }
    }
    npcLock.unlock();
}
