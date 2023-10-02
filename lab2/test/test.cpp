#include <gtest/gtest.h>

#include "hex/hex.h"

#include <iostream>

using namespace pepe;

bool constructorTest() {
    Hex a = {15, 1, 10};
    Hex b = std::string("a1f");
    Hex c = {1, 1, 1};
    Hex d(3, 1);
    return (a == b) && (c == d);
}

bool arithmeticTest() {
    Hex a = "123", b = "321", c = "444";
    return (a + b) == c;
}

TEST(HexTest, ConstructorTest) {
    EXPECT_TRUE(constructorTest());
}

TEST(HexTest, ArithmeticTest) {
    EXPECT_TRUE(arithmeticTest());
}
