#include <gtest/gtest.h>
#include "../src/hexagon.cpp"
#include "../src/pentagon.cpp"
#include "../src/rhombus.cpp"
#include "../src/array.cpp"

TEST(HexagonTest, DefaultConstructor)
{
    Hexagon<double> hexagon;
    EXPECT_NO_THROW();
}

TEST(HexagonTest, ParametrizedConstructor)
{
    Point<double> points[6] = {Point<double>(0, 0), Point<double>(1, 0), Point<double>(1, 1), Point<double>(0, 1), Point<double>(-1, 1), Point<double>(-1, 0)};
    Hexagon<double> hexagon(points);
    EXPECT_NO_THROW();
}

TEST(HexagonTest, CopyAssignment)
{
    Point<double> points[6] = {Point<double>(0, 0), Point<double>(1, 0), Point<double>(1, 1), Point<double>(0, 1), Point<double>(-1, 1), Point<double>(-1, 0)};
    Hexagon<double> hexagon1(points);
    Hexagon<double> hexagon2;
    hexagon2 = hexagon1;
    EXPECT_EQ(hexagon1, hexagon2);
}

TEST(HexagonTest, MoveAssignment)
{
    Point<double> points[6] = {Point<double>(0, 0), Point<double>(1, 0), Point<double>(1, 1), Point<double>(0, 1), Point<double>(-1, 1), Point<double>(-1, 0)};
    Hexagon<double> hexagon1(points);
    Hexagon<double> hexagon2;
    hexagon2 = std::move(hexagon1);
    EXPECT_NO_THROW();
}

TEST(HexagonTest, GeometricCenter)
{
    Point<double> points[6] = {Point<double>(0, 0), Point<double>(2, 0), Point<double>(2, 2), Point<double>(0, 2), Point<double>(-2, 2), Point<double>(-2, 0)};
    Hexagon<double> hexagon(points);
    Point<double> center = hexagon.geometricCenter();
    EXPECT_EQ(center, Point<double>(0, 1));
}

TEST(HexagonTest, ConversionToDouble)
{
    Point<double> points[6] = {Point<double>(0, 0), Point<double>(2, 0), Point<double>(2, 2), Point<double>(0, 2), Point<double>(-2, 2), Point<double>(-2, 0)};
    Hexagon<double> hexagon(points);
    double area = static_cast<double>(hexagon);
    EXPECT_NEAR(area, 8.0, 0.001);
}

TEST(HexagonTest, OutputOperator)
{
    Point<double> points[6] = {Point<double>(0, 0), Point<double>(2, 0), Point<double>(2, 2), Point<double>(0, 2), Point<double>(-2, 2), Point<double>(-2, 0)};
    Hexagon<double> hexagon(points);
    std::stringstream ss;
    ss << hexagon;
    EXPECT_FALSE(ss.str().empty());
}

TEST(PentagonTest, DefaultConstructor)
{
    Pentagon<double> pentagon;
    EXPECT_NO_THROW();
}

TEST(PentagonTest, ParametrizedConstructor)
{
    Point<double> points[5] = {
        Point<double>(1, 0),
        Point<double>(0.309, 0.951),
        Point<double>(-0.809, 0.588),
        Point<double>(-0.809, -0.588),
        Point<double>(0.309, -0.951)};
    EXPECT_NO_THROW(Pentagon<double> pentagon(points));
}

TEST(PentagonTest, CopyAssignment)
{
    Point<double> points[5] = {
        Point<double>(1, 0),
        Point<double>(0.309, 0.951),
        Point<double>(-0.809, 0.588),
        Point<double>(-0.809, -0.588),
        Point<double>(0.309, -0.951)};
    Pentagon<double> pentagon1(points);
    Pentagon<double> pentagon2;
    pentagon2 = pentagon1;
    EXPECT_EQ(pentagon1, pentagon2);
}

TEST(PentagonTest, MoveAssignment)
{
    Point<double> points[5] = {
        Point<double>(1, 0),
        Point<double>(0.309, 0.951),
        Point<double>(-0.809, 0.588),
        Point<double>(-0.809, -0.588),
        Point<double>(0.309, -0.951)};
    Pentagon<double> pentagon1(points);
    Pentagon<double> pentagon2;
    pentagon2 = std::move(pentagon1);
    EXPECT_NO_THROW();
}


TEST(PentagonTest, ConversionToDouble)
{
    Point<double> points[5] = {
        Point<double>(1, 0),
        Point<double>(0.309, 0.951),
        Point<double>(-0.809, 0.588),
        Point<double>(-0.809, -0.588),
        Point<double>(0.309, -0.951)};
    Pentagon<double> pentagon(points);
    double area = static_cast<double>(pentagon);
    EXPECT_NEAR(area, 2.4, 0.1);
}

TEST(RhombusTest, DefaultConstructor)
{
    Rhombus<double> rhombus;
    EXPECT_NO_THROW();
}

TEST(RhombusTest, ParametrizedConstructor)
{
    Point<double> points[4] = {Point<double>(0, 0), Point<double>(2, 1), Point<double>(0, 2), Point<double>(-2, 1)};
    Rhombus<double> rhombus(points);
    EXPECT_NO_THROW();
}

TEST(RhombusTest, CopyAssignment)
{
    Point<double> points[4] = {Point<double>(0, 0), Point<double>(2, 1), Point<double>(0, 2), Point<double>(-2, 1)};
    Rhombus<double> rhombus1(points);
    Rhombus<double> rhombus2;
    rhombus2 = rhombus1;
    EXPECT_EQ(rhombus1, rhombus2);
}

TEST(RhombusTest, MoveAssignment)
{
    Point<double> points[4] = {Point<double>(0, 0), Point<double>(2, 1), Point<double>(0, 2), Point<double>(-2, 1)};
    Rhombus<double> rhombus1(points);
    Rhombus<double> rhombus2;
    rhombus2 = std::move(rhombus1);
    EXPECT_NO_THROW();
}


TEST(RhombusTest, GeometricCenter)
{
    Point<double> points[4] = {Point<double>(0, 0), Point<double>(2, 1), Point<double>(0, 2), Point<double>(-2, 1)};
    Rhombus<double> rhombus(points);
    Point<double> center = rhombus.geometricCenter();
    EXPECT_EQ(center, Point<double>(0, 1));
}

TEST(RhombusTest, ConversionToDouble)
{
    Point<double> points[4] = {Point<double>(0, 0), Point<double>(2, 1), Point<double>(0, 2), Point<double>(-2, 1)};
    Rhombus<double> rhombus(points);
    double area = static_cast<double>(rhombus);
    EXPECT_NEAR(area, 2.5, 0.001);
}

TEST(RhombusTest, OutputOperator)
{
    Point<double> points[4] = {Point<double>(0, 0), Point<double>(2, 1), Point<double>(0, 2), Point<double>(-2, 1)};
    Rhombus<double> rhombus(points);
    std::stringstream ss;
    ss << rhombus;
    EXPECT_FALSE(ss.str().empty());
}

TEST(ArrayTest, PushBackAndRemove)
{
    Array<Figure<double>> arr;
    Point<double> hexPoints[6] = {
        Point<double>(0, 0), Point<double>(1, 0), Point<double>(1.5, 0.866), Point<double>(1, 1.732), Point<double>(0, 1.732), Point<double>(-0.5, 0.866)};
    auto hex = std::make_shared<Hexagon<double>>(hexPoints);
    arr.push_back(hex);


    arr.remove(0);
    EXPECT_EQ(arr.getSize(), 0);
}

TEST(ArrayTest, MoveConstructor)
{
    Array<Figure<double>> arr1;
    Point<double> hexPoints[6] = {
        Point<double>(0, 0), Point<double>(1, 0), Point<double>(1.5, 0.866), Point<double>(1, 1.732), Point<double>(0, 1.732), Point<double>(-0.5, 0.866)};
    auto hex = std::make_shared<Hexagon<double>>(hexPoints);
    arr1.push_back(hex);

    EXPECT_EQ(arr1.getSize(), 1);
}