#include "./src/arena.cpp"
#include "./src/console_logger.cpp"
#include "./src/file_logger.cpp"
#include "./src/frog.cpp"
#include "./src/dragon.cpp"
#include "./src/knight.cpp"
#include "./src/battle_visitor.cpp"
#include "./src/battle_stream.cpp"
#include <memory>

int main()
{
    Arena arena(500, 500);

    arena.spawnNPC("Frog", "Frog2");
    arena.spawnNPC("Dragon", "Dragon1");
    arena.spawnNPC("Knight", "Knight2");

    auto consoleLogger = std::make_shared<ConsoleLogger>();
    auto fileLogger = std::make_shared<FileLogger>();
    auto battleStream = std::make_shared<BattleStream>("kafka:9092", "battle_events");
    arena.addObserver(battleStream);
    arena.addObserver(consoleLogger);
    arena.addObserver(fileLogger);

    arena.startBattle(400);

    return 0;
}