#include "observer.h"

class ConsoleLogger : public Observer
{
public:
    void update(const std::string &event) override;
};