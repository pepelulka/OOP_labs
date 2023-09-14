#include <gcd.h>

int gcd::gcd(int a, int b) {
    return b ? gcd (b, a % b) : a;
}
