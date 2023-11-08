#include "point.h"

#include <iostream>

using namespace lab4;

int main() {
    using P = Point<int>;
    P a(1, 3);
    char b = 3;
    P c = a * b;
    std::cout << c << std::endl;
}