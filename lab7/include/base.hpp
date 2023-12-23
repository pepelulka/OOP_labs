#pragma once

#include <iostream>
#include <cmath>
#include <random>
#include <ctime>

namespace lab7 {

struct Coords {
    size_t x, y;

    friend std::ostream& operator<<(std::ostream &stream, const Coords& cords) {
        stream << "Coords(" << cords.x << ", " << cords.y << ")";
        return stream;
    }

    static size_t sq_distance(Coords c1, Coords c2) {
        size_t dx = c1.x - c2.x, dy = c1.y - c2.y;
        return dx * dx + dy * dy;
    }

    static Coords makeRandWalk(Coords c, int dist, int c_x, int c_y) {
        std::mt19937 rng(time(0));
        auto dx = (rng() % 2 == 1 ? 1 : -1) * rng() % dist, dy = (rng() % 2 == 1 ? 1 : -1) * rng() % dist;
        Coords new_c = {std::max(0, (int)c.x + (int)dx), std::max(0, (int)c.y + (int)dy)};
        new_c.x = std::min(c_x - 1, (int)new_c.x);
        new_c.y = std::min(c_y - 1, (int)new_c.y);
    }

};

}
