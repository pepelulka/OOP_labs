#pragma once

#include "field.hpp"

#include <random>
#include <thread>
#include <mutex>
#include <map>

namespace lab7 {

class FightManager {
private:
    std::mt19937 rng;
    Field &field;

    // 0 (defender win)
    // 1 (attacker win) defender was killed...
    int fight(/* defender, attacker */) {
        size_t d = rng() % 6;
        size_t a = rng() % 6;
        if (a > d) {
            return 1;
        }
        return 0;
    }

    void doTask(const std::string &f, const std::string &s) {
        // -1 - no fight
        // 0 - actual fight (f = d, s = a)
        // 1 - inverse fight (f = a, s = d)
        std::map<std::pair<std::string, std::string>, int> actions = {
            { {"Pegas", "Pegas" }, -1 },
            { {"Pegas", "Knight" }, -1 },
            { {"Pegas", "Dragon" }, 0 },
            { {"Knight", "Pegas" }, -1 },
            { {"Knight", "Knight" }, -1 },
            { {"Knight", "Dragon" }, 1 },
            { {"Dragon", "Pegas" }, 1 },
            { {"Dragon", "Knight" }, 0 },
            { {"Dragon", "Dragon" }, -1 }
        };
        std::pair<std::string, std::string> _temp_;
        _temp_.first = f;
        _temp_.second = s;
        int p = actions[_temp_];
        if (fight() == 1) {
            if (p == 0) {
                field.deleteNpc(f);
            } else {
                field.deleteNpc(s);
            }
        }
    }

    std::mutex mut;
    bool isTask = false;
    std::string first, second;
public:

    FightManager(Field& _field) : rng(time(0)), field(_field) { }

    void addTaskFight(const std::string &f, const std::string &s) {
        const std::lock_guard<std::mutex> lock(mut);
        first = f, second = s;
        isTask = true;
    }

    void operator()() {

        while (true) {
            {
                const std::lock_guard<std::mutex> lock(mut);
                if (isTask) {
                    doTask(first, second);
                }
            }
        }

    }

};

}
