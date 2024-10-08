#include <gtest/gtest.h>
#include "../src/rhombus.cpp"
#include "../src/hexagon.cpp"
#include "../src/pentagon.cpp"

TEST(RhombusTest, Constructor)
{
    Point points[4] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    Rhombus rhombus(points);

    ASSERT_NO_THROW(rhombus.getInfo());
    ASSERT_NO_THROW(rhombus.geometricCenter());
}

TEST(RhombusTest, InvalidRhombus)
{
    Point points[4] = {{0, 0}, {1, 0}, {2, 1}, {0, 1}};

    EXPECT_THROW(Rhombus rhombus(points), std::invalid_argument);
}

TEST(PentagonTest, Constructor)
{
    Point points[5] = {{1.0, 0.0}, {0.309016994, 0.951056516}, {-0.809016994, 0.587785252}, {-0.809016994, -0.587785252}, {0.309016994, -0.951056516}};
    Pentagon pentagon(points);

    ASSERT_NO_THROW(pentagon.getInfo());
    ASSERT_NO_THROW(pentagon.geometricCenter());
}

TEST(PentagonTest, InvalidPentagon)
{
    Point points[5] = {{1.0, 0.0}, {1.0, 1.0}, {1.0, 2.0}, {1.0, 3.0}, {1.0, 4.0}};

    EXPECT_THROW(Pentagon pentagon(points), std::invalid_argument);
}

TEST(HexagonTest, Constructor)
{
    Point points[6] = {{1.0, 0.0}, {0.5, std::sqrt(3) / 2}, {-0.5, std::sqrt(3) / 2}, {-1.0, 0.0}, {-0.5, -std::sqrt(3) / 2}, {0.5, -std::sqrt(3) / 2}};
    Hexagon hexagon(points);

    ASSERT_NO_THROW(hexagon.getInfo());
    ASSERT_NO_THROW(hexagon.geometricCenter());
}

TEST(HexagonTest, InvalidHexagon)
{
    Point points[6] = {{1.0, 0.0}, {1.0, 1.0}, {1.0, 2.0}, {1.0, 3.0}, {1.0, 4.0}, {1.0, 5.0}};

    EXPECT_THROW(Hexagon hexagon(points), std::invalid_argument);
}