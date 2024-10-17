#include <gtest/gtest.h>
#include "../src/rhombus.cpp"
#include "../src/hexagon.cpp"
#include "../src/pentagon.cpp"

TEST(HexagonTest, DefaultConstructor)
{
    Hexagon hexagon;
    EXPECT_NO_THROW();
}

TEST(HexagonTest, ParametrizedConstructor)
{
    Point points[6] = {Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1), Point(-1, 1), Point(-1, 0)};
    Hexagon hexagon(points);
    EXPECT_NO_THROW();
}

TEST(HexagonTest, CopyAssignment)
{
    Point points[6] = {Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1), Point(-1, 1), Point(-1, 0)};
    Hexagon hexagon1(points);
    Hexagon hexagon2;
    hexagon2 = hexagon1;
    EXPECT_EQ(hexagon1, hexagon2);
}

TEST(HexagonTest, MoveAssignment)
{
    Point points[6] = {Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1), Point(-1, 1), Point(-1, 0)};
    Hexagon hexagon1(points);
    Hexagon hexagon2;
    hexagon2 = std::move(hexagon1);
    EXPECT_NO_THROW();
}

TEST(HexagonTest, EqualityOperator)
{
    Point points1[6] = {Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1), Point(-1, 1), Point(-1, 0)};
    Point points2[6] = {Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1), Point(-1, 1), Point(-1, 0)};
    Hexagon hexagon1(points1);
    Hexagon hexagon2(points2);
    EXPECT_TRUE(hexagon1 == hexagon2);
}

TEST(HexagonTest, GeometricCenter)
{
    Point points[6] = {Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2), Point(-2, 2), Point(-2, 0)};
    Hexagon hexagon(points);
    Point center = hexagon.geometricCenter();
    EXPECT_EQ(center, Point(0, 1));
}

TEST(HexagonTest, ConversionToDouble)
{
    Point points[6] = {Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2), Point(-2, 2), Point(-2, 0)};
    Hexagon hexagon(points);
    double area = static_cast<double>(hexagon);
    EXPECT_NEAR(area, 8.0, 0.001);
}

TEST(HexagonTest, OutputOperator)
{
    Point points[6] = {Point(0, 0), Point(2, 0), Point(2, 2), Point(0, 2), Point(-2, 2), Point(-2, 0)};
    Hexagon hexagon(points);
    std::stringstream ss;
    ss << hexagon;
    EXPECT_FALSE(ss.str().empty());
}

TEST(PentagonTest, DefaultConstructor)
{
    Pentagon pentagon;
    EXPECT_NO_THROW();
}

// TEST(PentagonTest, ParametrizedConstructor)
// {
//     Point points[5] = {
//         Point(-0.5, -0.5),
//         Point(0.5, -0.5),
//         Point(0.5, 0.5),
//         Point(-0.5, 0.5),
//         Point(0.0, 1.0)};
//     Pentagon pentagon(points);
//     EXPECT_NO_THROW();
// }

// TEST(PentagonTest, CopyAssignment)
// {
//     Point points[5] = {
//         Point(-0.5, -0.5),
//         Point(0.5, -0.5),
//         Point(0.5, 0.5),
//         Point(-0.5, 0.5),
//         Point(0.0, 1.0)};
//     Pentagon pentagon1(points);
//     Pentagon pentagon2;
//     pentagon2 = pentagon1;
//     EXPECT_EQ(pentagon1, pentagon2);
// }

// TEST(PentagonTest, MoveAssignment)
// {
//     Point points[5] = {
//         Point(-0.5, -0.5),
//         Point(0.5, -0.5),
//         Point(0.5, 0.5),
//         Point(-0.5, 0.5),
//         Point(0.0, 1.0)};
//     Pentagon pentagon1(points);
//     Pentagon pentagon2;
//     pentagon2 = std::move(pentagon1);
//     EXPECT_NO_THROW();
// }

// TEST(PentagonTest, EqualityOperator)
// {
//     Point points1[5] = {
//         Point(-0.5, -0.5),
//         Point(0.5, -0.5),
//         Point(0.5, 0.5),
//         Point(-0.5, 0.5),
//         Point(0.0, 1.0)};
//     Point points2[5] = {
//         Point(-0.5, -0.5),
//         Point(0.5, -0.5),
//         Point(0.5, 0.5),
//         Point(-0.5, 0.5),
//         Point(0.0, 1.0)};
//     Pentagon pentagon1(points1);
//     Pentagon pentagon2(points2);
//     EXPECT_TRUE(pentagon1 == pentagon2);
// }

// TEST(PentagonTest, GeometricCenter)
// {
//     Point points[5] = {
//         Point(-0.5, -0.5),
//         Point(0.5, -0.5),
//         Point(0.5, 0.5),
//         Point(-0.5, 0.5),
//         Point(0.0, 1.0)};
//     Pentagon pentagon(points);
//     Point center = pentagon.geometricCenter();
//     EXPECT_EQ(center, Point(1, 1.5));
// }

// TEST(PentagonTest, ConversionToDouble)
// {
//     Point points[5] = {
//         Point(-0.5, -0.5),
//         Point(0.5, -0.5),
//         Point(0.5, 0.5),
//         Point(-0.5, 0.5),
//         Point(0.0, 1.0)};
//     Pentagon pentagon(points);
//     double area = static_cast<double>(pentagon);
//     EXPECT_NEAR(area, 6.0, 0.001);
// }

// TEST(PentagonTest, OutputOperator)
// {
//     Point points[5] = {
//         Point(-0.5, -0.5),
//         Point(0.5, -0.5),
//         Point(0.5, 0.5),
//         Point(-0.5, 0.5),
//         Point(0.0, 1.0)};
//     Pentagon pentagon(points);
//     std::stringstream ss;
//     ss << pentagon;
//     EXPECT_FALSE(ss.str().empty());
// }

TEST(RhombusTest, DefaultConstructor)
{
    Rhombus rhombus;
    EXPECT_NO_THROW();
}

TEST(RhombusTest, ParametrizedConstructor)
{
    Point points[4] = {Point(0, 0), Point(2, 1), Point(0, 2), Point(-2, 1)};
    Rhombus rhombus(points);
    EXPECT_NO_THROW();
}

TEST(RhombusTest, CopyAssignment)
{
    Point points[4] = {Point(0, 0), Point(2, 1), Point(0, 2), Point(-2, 1)};
    Rhombus rhombus1(points);
    Rhombus rhombus2;
    rhombus2 = rhombus1;
    EXPECT_EQ(rhombus1, rhombus2);
}

TEST(RhombusTest, MoveAssignment)
{
    Point points[4] = {Point(0, 0), Point(2, 1), Point(0, 2), Point(-2, 1)};
    Rhombus rhombus1(points);
    Rhombus rhombus2;
    rhombus2 = std::move(rhombus1);
    EXPECT_NO_THROW();
}

TEST(RhombusTest, EqualityOperator)
{
    Point points1[4] = {Point(0, 0), Point(2, 1), Point(0, 2), Point(-2, 1)};
    Point points2[4] = {Point(0, 0), Point(2, 1), Point(0, 2), Point(-2, 1)};
    Rhombus rhombus1(points1);
    Rhombus rhombus2(points2);
    EXPECT_TRUE(rhombus1 == rhombus2);
}

TEST(RhombusTest, GeometricCenter)
{
    Point points[4] = {Point(0, 0), Point(2, 1), Point(0, 2), Point(-2, 1)};
    Rhombus rhombus(points);
    Point center = rhombus.geometricCenter();
    EXPECT_EQ(center, Point(0, 1));
}

TEST(RhombusTest, ConversionToDouble)
{
    Point points[4] = {Point(0, 0), Point(2, 1), Point(0, 2), Point(-2, 1)};
    Rhombus rhombus(points);
    double area = static_cast<double>(rhombus);
    EXPECT_NEAR(area, 2.5, 0.001);
}

TEST(RhombusTest, OutputOperator)
{
    Point points[4] = {Point(0, 0), Point(2, 1), Point(0, 2), Point(-2, 1)};
    Rhombus rhombus(points);
    std::stringstream ss;
    ss << rhombus;
    EXPECT_FALSE(ss.str().empty());
}
