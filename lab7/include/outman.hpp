#pragma once

#include "field.hpp"

namespace lab7 {

class OutManager {
private:
    Field &field;

public:

    OutManager(Field &_field) : field(_field) { }

    void operator()() {
        while (true) {
            field.printField();

            using namespace std::chrono_literals;
            std::this_thread::sleep_for(1000ms);
        }
    }

};

}