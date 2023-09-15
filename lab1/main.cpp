#include "gcd/gcd.h"

#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << gcd::gcd(a, b) << std::endl;
}
