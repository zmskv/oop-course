#include <iostream>
#include <memory>
#pragma once

class NPC
{
public:
    NPC(std::string name, int x, int y) : name(name), x(x), y(y) {}
    virtual ~NPC() = default;

    std::string getName() const { return name; }
    int getX() const { return x; }
    int getY() const { return y; }

    virtual void accept(class Visitor &visitor) = 0;

protected:
    std::string name;
    int x, y;
};
