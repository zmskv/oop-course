#include "../include/console_logger.h"
#include <iostream>

void ConsoleLogger::update(const std::string &event)
{
    std::cout << event << std::endl;
}