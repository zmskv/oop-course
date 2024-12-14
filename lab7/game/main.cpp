#include "./src/arena.cpp"
#include "./src/console_logger.cpp"
#include "./src/file_logger.cpp"
#include "./src/frog.cpp"
#include "./src/dragon.cpp"
#include "./src/knight.cpp"
#include "./src/battle_visitor.cpp"
#include "./src/battle_stream.cpp"
#include "./src/sync_arena.cpp"
#include "./src/npc.cpp"
#include <memory>
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <iostream>

int main()
{
    SynchronizedArena synchronizedArena(100, 100);

    for (int i = 0; i < 50; ++i)
    {
        std::string types[] = {"Dragon", "Knight", "Frog"};
        std::string type = types[rand() % 3];
        std::string name = type + std::to_string(i);
        synchronizedArena.addNPC(NPCFactory::createNPC(type, name, rand() % 100, rand() % 100));
    }

    bool gameOver = false;

    std::thread movementThread([&]()
                               {
        while (!gameOver) {
            synchronizedArena.moveNPCs();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        } });

    std::thread battleThread([&]()
                             {
        while (!gameOver) {
            synchronizedArena.processBattleTasks();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        } });

    sf::RenderWindow window(sf::VideoMode(800, 800), "Arena");
    sf::Clock gameClock;
    sf::Clock moveClock;

    while (window.isOpen() && !gameOver)
    {
        sf::Time elapsedGameTime = gameClock.getElapsedTime();
        sf::Time elapsedMoveTime = moveClock.getElapsedTime();

        if (elapsedGameTime >= sf::seconds(30))
        {
            gameOver = true;
            window.close();
        }

        if (elapsedMoveTime >= sf::seconds(1))
        {
            synchronizedArena.moveNPCs();
            moveClock.restart();
        }

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        std::shared_lock<std::shared_mutex> lock(synchronizedArena.getNpcMutex());
        window.clear();

        for (const auto &npc : synchronizedArena.getNPCs())
        {
            sf::Color npcColor;
            if (npc->getType() == "Dragon")
            {
                npcColor = sf::Color::Red;
            }
            else if (npc->getType() == "Knight")
            {
                npcColor = sf::Color::Blue;
            }
            else if (npc->getType() == "Frog")
            {
                npcColor = sf::Color::Green;
            }

            sf::CircleShape shape(5);
            shape.setPosition(npc->getX() * 8, npc->getY() * 8);
            shape.setFillColor(npcColor);
            window.draw(shape);
        }

        window.display();
        lock.unlock();
    }

    if (gameOver)
    {
        std::cout << "Игра завершена! Выжившие:" << std::endl;
        for (const auto &npc : synchronizedArena.getNPCs())
        {
            std::cout << npc->getName() << " (" << npc->getType() << ") на позиции ("
                      << npc->getX() << ", " << npc->getY() << ")" << std::endl;
        }
    }

    movementThread.join();
    battleThread.join();

    return 0;
}
