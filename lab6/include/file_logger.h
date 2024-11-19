#pragma once
#include "observer.h"

class FileLogger : public Observer
{
public:
    void update(const std::string &event) override;
};