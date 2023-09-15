#include <gtest/gtest.h>

#include "gcd/gcd.h"

#include <iostream>

bool basicTest() {
    return gcd::gcd(2, 3) == 1 &&
           gcd::gcd(6, 12) == 6 &&
           gcd::gcd(15, 21) == 3;
}

bool negativeTest() {
    return gcd::gcd(-2, -3) == 1 &&
           gcd::gcd(6, -12) == 6 &&
           gcd::gcd(-15, 21) == 3;
}

bool bigIntTest() {
    return gcd::gcd(234325, 324000) == 25 &&
           gcd::gcd(324224, 1234160) == 16;
}

TEST(GCDTests, BasicTest) {
    EXPECT_TRUE(basicTest());
}

TEST(GCDTests, NegativeTest) {
    EXPECT_TRUE(negativeTest());
}

TEST(GCDTests, BigIntTest) {
    EXPECT_TRUE(bigIntTest());
}
