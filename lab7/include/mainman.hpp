#pragma once

#include "field.hpp"
#include "fightman.hpp"

namespace lab7 {

class MainManager {
private:
    Field &field;
    FightManager &fightman;

public:

    MainManager(Field &_field, FightManager &_fightman) : field(_field), fightman(_fightman) { } 

    void operator()() {

        while (true) {
            field.randomWalk();

            using namespace std::chrono_literals;
            std::this_thread::sleep_for(200ms);
        }

    }

};

};
