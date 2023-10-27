#include <gtest/gtest.h>

#include "figures/figures.h"

#include <iostream>
#include <sstream>

using namespace lab3;

TEST(FiguresTest, AreaTest) {
    std::vector<double> expectedOutput = {43.45584, 1.7320508075688772, 9}; 
    Octagon a = Octagon({2, 2}, {3, 2}, -1);
    Triangle b = Triangle({1, 1}, {1, -1}, 1);
    Square c = Square({0, 0}, {3, 3});
    EXPECT_TRUE(static_cast<double>(a) - expectedOutput[0] < EPS);
    EXPECT_TRUE(static_cast<double>(b) - expectedOutput[1] < EPS);
    EXPECT_TRUE(static_cast<double>(c) - expectedOutput[2] < EPS);
}

TEST(FiguresTest, CenterTest) {
    std::vector<Point> expectedOutput = {Point{2.5, 0.792893}, 
                                         Point{1.57735, 0},
                                         Point{1.5, 1.5}}; 
    Octagon a = Octagon({2, 2}, {3, 2}, -1);
    Triangle b = Triangle({1, 1}, {1, -1}, 1);
    Square c = Square({0, 0}, {3, 3});
    EXPECT_EQ(a.geometricCenter(), expectedOutput[0]);
    EXPECT_EQ(b.geometricCenter(), expectedOutput[1]);
    EXPECT_EQ(c.geometricCenter(), expectedOutput[2]);
}
