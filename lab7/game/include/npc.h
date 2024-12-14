#include <iostream>
#include <memory>
#pragma once

class NPC
{
public:
    NPC(std::string name, int x, int y, int movementDistance, int attackRange);
    virtual void move() = 0;
    virtual bool canAttack(NPC *other) = 0;
    virtual ~NPC() = default;

    std::string getName() const;
    int getX() const;
    int getY() const;
    void setX(int _x) { x = _x; }
    void setY(int _y) { y = _y; }
    int getAttackRange() { return attackRange; };
    int getMovementDistance() { return movementDistance; }

    virtual void accept(class Visitor &visitor) = 0;
    virtual std::string getType() const = 0;

protected:
    std::string name;
    int x, y;
    int movementDistance;
    int attackRange;
};
