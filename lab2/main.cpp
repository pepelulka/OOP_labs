#include "hex/hex.h"

#include <iostream>

int main() {
    using Hex = pepe::Hex;
    Hex a, b;
    std::cin >> a >> b;
    std::cout << "Sum: " << (a + b) << std::endl;
    
    std::cout << "Diff: " << (a - b) << std::endl;
}