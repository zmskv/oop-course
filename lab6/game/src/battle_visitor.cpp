#include "../include/battle_visitor.h"
#include "../include/dragon.h"
#include "../include/frog.h"
#include "../include/knight.h"

BattleVisitor::BattleVisitor(int range, std::vector<std::unique_ptr<NPC>> &npcs, std::vector<std::shared_ptr<Observer>> &observers)
    : range(range), npcs(npcs), observers(observers) {}

void BattleVisitor::visit(Dragon &dragon)
{
    for (auto it = npcs.begin(); it != npcs.end();)
    {
        if (auto knight = dynamic_cast<Knight *>(it->get()))
        {

            if (isInRange(dragon, *knight))
            {
                notifyObservers("Dragon killed " + it->get()->getName());

                it = npcs.erase(it);
            }
            else
            {
                ++it;
            }
        }
        else
        {
            ++it;
        }
    }
}

void BattleVisitor::visit(Knight &knight)
{
    for (auto it = npcs.begin(); it != npcs.end();)
    {

        if (auto dragon = dynamic_cast<Dragon *>(it->get()))
        {

            if (isInRange(knight, *dragon))
            {
                notifyObservers("Knight killed " + it->get()->getName());

                it = npcs.erase(it);
            }
            else
            {
                ++it;
            }
        }
        else
        {
            ++it;
        }
    }
}

void BattleVisitor::visit(Frog &frog)
{
    for (auto it = npcs.begin(); it != npcs.end();)
    {

        if (it->get() != &frog && isInRange(frog, *it->get()))
        {
            notifyObservers("Frog killed " + it->get()->getName());
            it = npcs.erase(it);
        }
        else
        {
            ++it;
        }
    }

    std::cout << "Frog killed itself: " << frog.getName() << std::endl;

    for (auto it = npcs.begin(); it != npcs.end();)
    {
        if (it->get() == &frog)
        {
            notifyObservers("Frog killed itself: " + frog.getName());
            it = npcs.erase(it);
            break;
        }
        else
        {
            ++it;
        }
    }
}

bool BattleVisitor::isInRange(const NPC &npc1, const NPC &npc2)
{
    return std::abs(npc1.getX() - npc2.getX()) + std::abs(npc1.getY() - npc2.getY()) <= range;
}

void BattleVisitor::notifyObservers(const std::string &event)
{
    for (auto &observer : observers)
    {
        observer->update(event);
    }
}

bool BattleVisitor::areAllOutOfRange()
{
    for (const auto &npc1 : npcs)
    {
        for (const auto &npc2 : npcs)
        {
            if (npc1 != npc2 && isInRange(*npc1, *npc2))
            {
                return false;
            }
        }
    }
    return true;
}
