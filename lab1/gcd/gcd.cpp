#include "gcd/gcd.h"

#include <cmath>

unsigned ugcd(unsigned a, unsigned b) {
    return b ? ugcd (b, a % b) : a;
}

int gcd::gcd(int a, int b) {
    return ugcd(std::abs(a), std::abs(b));
}
