#pragma once

#include "field.hpp"
#include "observer.hpp"

#include <map>

namespace lab6 {

class Visitor {
public:
    ObserverPool observerPool;
private:

// -1 - nobody was killed
// 0 - first won (second died)
// 1 - second won (first died)
int whoWin(NPC * lhs, NPC * rhs);

public:
    void runFight(Field &field, size_t distance);

};

}