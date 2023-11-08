#pragma once

#include "point.h"

namespace lab4 {

template<Number T>
class Figure {
public:
    Figure() = 0;
    ~Figure() = 0;
    virtual Point<T> center() const = 0; 
    virtual operator double() const = 0;
};

template<Number T>
class Square : public Figure<T> {
private:
    Point<T> p1, p2;
public:
    Square() = default;
    
};

}
