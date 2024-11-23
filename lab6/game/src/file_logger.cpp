#include "../include/file_logger.h"
#include <fstream>

void FileLogger::update(const std::string &event)
{
    std::ofstream logFile("log/log.txt", std::ios::app);
    logFile << event << std::endl;
}