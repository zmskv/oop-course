#include <gtest/gtest.h>
#include "../src/arena.cpp"
#include "../src/console_logger.cpp"
#include "../src/file_logger.cpp"
#include "../src/frog.cpp"
#include "../src/dragon.cpp"
#include "../src/knight.cpp"
#include "../src/battle_visitor.cpp"

TEST(ArenaTest, AddSingleNPC)
{
    Arena arena(500, 500);
    auto frog = NPCFactory::createNPC("Frog", "FrogKing", 50, 50);
    arena.addNPC(std::move(frog));

    testing::internal::CaptureStdout();
    arena.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("FrogKing"), std::string::npos);
}

TEST(ArenaTest, AddMultipleNPCs)
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
}

TEST(ArenaTest, SpawnNPCWithSpecificCoordinates)
{
    Arena arena(500, 500);
    arena.spawnNPC("Dragon", "FireDragon", 200, 200);

    testing::internal::CaptureStdout();
    arena.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("FireDragon"), std::string::npos);
}

TEST(ArenaTest, SpawnNPCWithRandomCoordinates)
{
    Arena arena(500, 500);
    arena.spawnNPC("Frog", "RandomFrog", -1, -1);

    testing::internal::CaptureStdout();
    arena.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("RandomFrog"), std::string::npos);
}

TEST(ArenaTest, StartBattleRemovesNPCs)
{
    Arena arena(500, 500);

    auto frog = NPCFactory::createNPC("Frog", "FrogKing", 50, 50);
    auto dragon = NPCFactory::createNPC("Dragon", "FireDragon", 100, 100);

    arena.addNPC(std::move(frog));
    arena.addNPC(std::move(dragon));
    arena.startBattle(100);

    testing::internal::CaptureStdout();
    arena.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output.empty(), true);
}

TEST(ArenaTest, StartBattleWithoutNPCs)
{
    Arena arena(500, 500);

    testing::internal::CaptureStdout();
    arena.startBattle(100);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output.empty(), false);
}

TEST(ArenaTest, SaveNPCsToFile)
{
    Arena arena(500, 500);
    arena.spawnNPC("Dragon", "FireDragon", 100, 100);

    EXPECT_NO_THROW(arena.saveNPCsToFile("npcs.txt"));
}

TEST(ArenaTest, AddObserver)
{
    Arena arena(500, 500);
    auto observer = std::make_shared<ConsoleLogger>();
    EXPECT_NO_THROW(arena.addObserver(observer));
}

TEST(ArenaTest, PrintNPCsAfterBattle)
{
    Arena arena(500, 500);
    arena.spawnNPC("Frog", "FrogKing", 50, 50);
    arena.startBattle(100);

    testing::internal::CaptureStdout();
    arena.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output.empty(), true);
}

TEST(ArenaTest, SpawnMultipleNPCs)
{
    Arena arena(500, 500);
    arena.spawnNPC("Dragon", "FireDragon1", 100, 100);
    arena.spawnNPC("Dragon", "FireDragon2", 200, 200);

    testing::internal::CaptureStdout();
    arena.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("FireDragon2"), std::string::npos);
}

TEST(ArenaTest, BattleDoesNotCrashWithEmptyArena)
{
    Arena arena(500, 500);
    EXPECT_NO_THROW(arena.startBattle(100));
}

TEST(ArenaTest, BattleDoesNotCrashWithSingleNPC)
{
    Arena arena(500, 500);
    arena.spawnNPC("Frog", "FrogKing", 50, 50);

    EXPECT_NO_THROW(arena.startBattle(100));
}

TEST(ArenaTest, RandomSpawnDoesNotExceedBounds)
{
    Arena arena(500, 500);
    arena.spawnNPC("Frog", "FrogKing", -1, -1);

    testing::internal::CaptureStdout();
    arena.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("FrogKing"), std::string::npos);
}

TEST(ArenaTest, NPCsRemainAfterBattleIfOutOfRange)
{
    Arena arena(500, 500);

    auto frog = NPCFactory::createNPC("Frog", "FrogKing", 50, 50);
    auto dragon = NPCFactory::createNPC("Dragon", "FireDragon", 300, 300);

    arena.addNPC(std::move(frog));
    arena.addNPC(std::move(dragon));
    arena.startBattle(100);

    testing::internal::CaptureStdout();
    arena.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("FireDragon"), std::string::npos);
}

TEST(ArenaTest, StartBattleDoesNotAffectEmptyArena)
{
    Arena arena(500, 500);

    testing::internal::CaptureStdout();
    arena.startBattle(0);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output.empty(), false);
}

TEST(ArenaTest, AddMultipleSameTypeNPCs)
{
    Arena arena(500, 500);
    arena.spawnNPC("Dragon", "FireDragon1", 100, 100);
    arena.spawnNPC("Dragon", "FireDragon2", 200, 200);

    testing::internal::CaptureStdout();
    arena.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("FireDragon1"), std::string::npos);
    EXPECT_NE(output.find("FireDragon2"), std::string::npos);
}

TEST(ArenaTest, NPCsPositionAreCorrectAfterSpawn)
{
    Arena arena(500, 500);
    arena.spawnNPC("Knight", "BraveKnight", 150, 250);

    testing::internal::CaptureStdout();
    arena.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("150"), std::string::npos);
    EXPECT_NE(output.find("250"), std::string::npos);
}

TEST(ArenaTest, AddNPCUpdatesArenaCorrectly)
{
    Arena arena(500, 500);

    auto dragon = NPCFactory::createNPC("Dragon", "FireDragon", 300, 300);
    arena.addNPC(std::move(dragon));

    testing::internal::CaptureStdout();
    arena.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("FireDragon"), std::string::npos);
}

TEST(ArenaTest, RandomSpawnPlacesNPCInBounds)
{
    Arena arena(500, 500);

    arena.spawnNPC("Frog", "RandomFrog", -1, -1);
    testing::internal::CaptureStdout();
    arena.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("RandomFrog"), std::string::npos);
}

TEST(ArenaTest, StartBattleRemovesAllNPCsInRange)
{
    Arena arena(500, 500);

    auto frog = NPCFactory::createNPC("Frog", "FrogKing", 50, 50);
    auto dragon = NPCFactory::createNPC("Dragon", "FireDragon", 100, 100);

    arena.addNPC(std::move(frog));
    arena.addNPC(std::move(dragon));
    arena.startBattle(200);

    testing::internal::CaptureStdout();
    arena.printNPCs();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output.empty(), true);
}
