#include "./src/arena.cpp"
#include "./src/console_logger.cpp"
#include "./src/file_logger.cpp"
#include "./src/frog.cpp"
#include "./src/dragon.cpp"
#include "./src/knight.cpp"
#include "./src/battle_visitor.cpp"
#include "./src/battle_stream.cpp"
#include <memory>

void printMenu()
{
    std::cout << "\n--- Arena Menu ---\n"
              << "1. Add NPC manually\n"
              << "2. Spawn random NPC\n"
              << "3. Print NPCs\n"
              << "4. Start battle\n"
              << "5. Connect Kafka\n"
              << "6. Save NPCs to file\n"
              << "7. Load NPCs from file\n"
              << "0. Exit\n"
              << "Choose an option: ";
}

int main()
{
    Arena arena(500, 500);
    std::ios::sync_with_stdio(false);

    auto consoleLogger = std::make_shared<ConsoleLogger>();
    auto fileLogger = std::make_shared<FileLogger>();

    arena.addObserver(consoleLogger);
    arena.addObserver(fileLogger);

    std::shared_ptr<BattleStream> battleStream = nullptr;

    int choice;
    do
    {
        printMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            std::string name, type;
            int x, y;
            std::cout << "Enter NPC type (Frog, Dragon, Knight): ";
            std::cin >> type;
            std::cout << "Enter NPC name: ";
            std::cin >> name;
            std::cout << "Enter X coordinate (0-500): ";
            std::cin >> x;
            std::cout << "Enter Y coordinate (0-500): ";
            std::cin >> y;

            if (x < 0 || x > 500 || y < 0 || y > 500)
            {
                std::cout << "Invalid coordinates. Must be between 0 and 500.\n";
                break;
            }

            arena.spawnNPC(type, name, x, y);
            std::cout << "NPC added successfully.\n";
            break;
        }
        case 2:
        {
            std::string type;
            std::cout << "Enter NPC type (Frog, Dragon, Knight): ";
            std::cin >> type;

            std::string name = type + std::to_string(rand() % 1000);
            int x = rand() % 501;
            int y = rand() % 501;

            arena.spawnNPC(type, name);
            std::cout << "Random NPC spawned successfully.\n";
            break;
        }
        case 3:
            std::cout << "NPCs in the arena:\n";
            arena.printNPCs();
            break;
        case 4:
        {
            int range;
            std::cout << "Enter battle range: ";
            std::cin >> range;
            arena.startBattle(range);
            std::cout << "Battle completed.\n";
            break;
        }
        case 5:
        {
            if (!battleStream)
            {
                std::string brokers, topic;
                std::cout << "Enter Kafka brokers (e.g., kafka:9092): ";
                std::cin >> brokers;
                std::cout << "Enter Kafka topic: ";
                std::cin >> topic;

                battleStream = std::make_shared<BattleStream>(brokers, topic);
                arena.addObserver(battleStream);
                std::cout << "Kafka observer connected successfully.\n";
            }
            else
            {
                std::cout << "Kafka observer is already connected.\n";
            }
            break;
        }
        case 6:
        {
            std::string filename;
            std::cout << "Enter file name to save NPCs: ";
            std::cin >> filename;
            arena.saveNPCsToFile(filename);
            std::cout << "NPCs saved to file.\n";
            break;
        }
        case 7:
        {
            std::string filename;
            std::cout << "Enter file name to load NPCs: ";
            std::cin >> filename;
            arena.loadNPCsFromFile(filename);
            std::cout << "NPCs loaded from file.\n";
            break;
        }
        case 0:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid option. Try again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}