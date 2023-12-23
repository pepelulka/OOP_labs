#include <iostream>

#include "field.hpp"
#include "visitor.hpp"
#include "fightman.hpp"
#include "outman.hpp"
#include "mainman.hpp"

using namespace lab7;

int main() {
    // Prerequisites
    Field field(10, 10);
    FightManager fman(field);
    OutManager oman(field);
    MainManager mman(field, fman);
    //
    FieldMemento::parseFile(field, "in.txt");
    std::thread t1 = std::thread(oman);
    std::thread t2 = std::thread(mman);
    t1.join();
    t2.join();
}