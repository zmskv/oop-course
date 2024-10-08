#include <gtest/gtest.h>
#include "../src/rhombus.cpp"
#include "../src/hexagon.cpp"
#include "../src/pentagon.cpp"

TEST(RhombusTest, ConstructorAndEquality)
{
    Point points[4] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    Rhombus rhombus(points);

    ASSERT_NO_THROW(rhombus.geometricCenter());
    EXPECT_EQ(rhombus, rhombus);
}

TEST(RhombusTest, InvalidRhombus)
{
    Point points[4] = {{0, 0}, {1, 0}, {2, 1}, {0, 1}};
    Rhombus rhombus(points);

    EXPECT_THROW(rhombus.isValidRhombus(), std::invalid_argument);
}

TEST(PentagonTest, ConstructorAndEquality)
{
    Point points[5] = {{1.0, 0.0}, {0.309, 0.951}, {-0.809, 0.588}, {-0.809, -0.588}, {0.309, -0.951}};
    Pentagon pentagon(points);

    ASSERT_NO_THROW(pentagon.getInfo());
    EXPECT_EQ(pentagon, pentagon);
}

TEST(PentagonTest, InvalidPentagon)
{
    Point points[5] = {{1.0, 0.0}, {1.0, 1.0}, {1.0, 2.0}, {1.0, 3.0}, {1.0, 4.0}};
    Pentagon pentagon(points);

    EXPECT_THROW(pentagon.isValidPentagon(), std::invalid_argument);
}

TEST(HexagonTest, ConstructorAndEquality)
{
    Point points[6] = {{1.0, 0.0}, {0.5, 0.866}, {-0.5, 0.866}, {-1.0, 0.0}, {-0.5, -0.866}, {0.5, -0.866}};
    Hexagon hexagon(points);

    ASSERT_NO_THROW(hexagon.getInfo());
    EXPECT_EQ(hexagon, hexagon);
}

TEST(HexagonTest, InvalidHexagon)
{
    Point points[6] = {{1.0, 0.0}, {1.0, 1.0}, {1.0, 2.0}, {1.0, 3.0}, {1.0, 4.0}, {1.0, 5.0}};
    Hexagon hexagon(points);

    EXPECT_THROW(hexagon.isValidHexagon(), std::invalid_argument);
}