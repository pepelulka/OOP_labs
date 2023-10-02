#include "gcd/gcd.h"

#include <cmath>

unsigned ugcd(unsigned a, unsigned b) {
    // return b ? ugcd (b, a % b) : a;
    while (b != 0) {
        unsigned temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int gcd::gcd(int a, int b) {
    return ugcd(std::abs(a), std::abs(b));
}
