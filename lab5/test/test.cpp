#include <gtest/gtest.h>

#include "include/allocator.h"
#include "include/vector.h"

#include <iostream>
#include <map>
#include <vector>

using namespace lab5;

static int fact(int n) {
    if (n == 0)
        return 1;
    int result = 1;
    for (; n > 0; n--) {
        result *= n;
    }
    return result;
}

TEST(Lab5, AllocatorMapTest) {
    std::map<int, int, std::less<int>, BinAllocator<std::pair<const int, int>>> m;
    m[0] = 1;
    for (int i = 1; i < 10; i++) {
        m[i] = m[i - 1] * i;
    }
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(m[i], fact(i));
    }
}

TEST(Lab5, VectorTest) {
    Vector<int> a = {0, 1, 2, 3, 4};
    a.pushBack(5);
    a.pushBack(6);
    int sum = 0;
    for (const auto& i : a) {
        sum += i;
    }
    EXPECT_EQ(sum, 21);
    std::vector<std::string> meow = {
        "aa1",
        "pepelul",
        "fff",
        ""
    };
    Vector<std::string> mmeow;
    for (size_t i = 0; i < meow.size(); i++) {
        std::cout << "{";
        mmeow.pushBack(meow[i]);
        std::cout << "}";
    }
    std::cout << std::endl;
    // for (size_t i = 0; i < mmeow.size(); i++) {
    //     EXPECT_EQ(meow[i], mmeow[i]);
    // }
}
