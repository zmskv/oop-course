#include <fstream>
#include <iostream>

#pragma once

class Observer
{
public:
    virtual void update(const std::string &event) = 0;
};
