#include <gtest/gtest.h>
#include "../src/arena.cpp"
#include "../src/console_logger.cpp"
#include "../src/file_logger.cpp"
#include "../src/frog.cpp"
#include "../src/dragon.cpp"
#include "../src/knight.cpp"
#include "../src/battle_visitor.cpp"

TEST(NPCTest, CreateNPC)
{
    auto dragon = NPCFactory::createNPC("Dragon", "FireDragon", 100, 100);
    EXPECT_NE(dragon, nullptr);
    EXPECT_EQ(dragon->getName(), "FireDragon");
    EXPECT_EQ(dragon->getX(), 100);
    EXPECT_EQ(dragon->getY(), 100);
}

TEST(ArenaTest, AddNPC)
{
    Arena arena(500, 500);

    auto frog = NPCFactory::createNPC("Frog", "FrogKing", 50, 50);
    arena.addNPC(std::move(frog));

    testing::internal::CaptureStdout();
    arena.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("FrogKing"), std::string::npos);
}

TEST(ArenaTest, SpawnNPCRandomCoordinates)
{
    Arena arena(500, 500);

    arena.spawnNPC("Dragon", "RandomDragon");

    testing::internal::CaptureStdout();
    arena.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("RandomDragon"), std::string::npos);
}

TEST(ArenaTest, SpawnNPCAtGivenCoordinates)
{
    Arena arena(500, 500);

    arena.spawnNPC("Dragon", "FireDragon", 100, 100);

    testing::internal::CaptureStdout();
    arena.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("FireDragon"), std::string::npos);
    EXPECT_NE(output.find("100"), std::string::npos);
    EXPECT_NE(output.find("100"), std::string::npos);
}

TEST(ArenaTest, StartBattle)
{
    Arena arena(500, 500);

    auto frog = NPCFactory::createNPC("Frog", "FrogKing", 50, 50);
    auto dragon = NPCFactory::createNPC("Dragon", "FireDragon", 100, 100);
    arena.addNPC(std::move(frog));
    arena.addNPC(std::move(dragon));

    testing::internal::CaptureStdout();
    arena.startBattle(100);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output.find("FrogKing"), std::string::npos);
    EXPECT_EQ(output.find("FireDragon"), std::string::npos);
}

TEST(ArenaTest, LoadNPCs)
{
    Arena arena(500, 500);

    auto frog = NPCFactory::createNPC("Frog", "FrogKing", 50, 50);
    auto dragon = NPCFactory::createNPC("Dragon", "FireDragon", 100, 100);

    arena.addNPC(std::move(frog));
    arena.addNPC(std::move(dragon));

    testing::internal::CaptureStdout();
    arena.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("FrogKing"), std::string::npos);
    EXPECT_NE(output.find("FireDragon"), std::string::npos);
}

TEST(ArenaTest, NPCWithDamageDisappears)
{
    Arena arena(500, 500);

    auto frog = NPCFactory::createNPC("Frog", "FrogKing", 50, 50);
    arena.addNPC(std::move(frog));

    testing::internal::CaptureStdout();
    arena.startBattle(0);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output.find("FrogKing"), std::string::npos);
}

TEST(ArenaTest, PrintAllNPCs)
{
    Arena arena(500, 500);

    auto frog = NPCFactory::createNPC("Frog", "FrogKing", 50, 50);
    auto dragon = NPCFactory::createNPC("Dragon", "FireDragon", 100, 100);
    arena.addNPC(std::move(frog));
    arena.addNPC(std::move(dragon));

    testing::internal::CaptureStdout();
    arena.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("FrogKing"), std::string::npos);
    EXPECT_NE(output.find("FireDragon"), std::string::npos);
}
