#pragma once

#include <iostream>
#include <cmath>

namespace lab6 {

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

};

}
