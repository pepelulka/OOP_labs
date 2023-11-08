#pragma once

#include <concepts>
#include <iostream>

namespace lab4 {

template<class T>
concept Number = std::is_convertible_v<T, double>;

template<Number T>
struct Point {
    T x, y;

    Point(T _x, T _y) : x(_x), y(_y) { }
    Point() : x(0), y(0) { }

    Point(const Point &other) = default;
    Point(Point &&other) = default;

    friend std::ostream& operator<<(std::ostream &out, const Point &point) {
        out << "Point(" << point.x << ", " << point.y << ")";
        return out;
    }

    friend std::istream& operator>>(std::istream &in, Point &point) {
        in >> point.x >> point.y;
        return in;
    }

    Point& operator+(const Point &other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Point& operator-() {
        x = -x;
        y = -y;
        return *this;
    }

    Point& operator-(const Point &other) {
        return (*this = *this + (-other));
    }

    template<Number U>
    Point& operator*(U value) {
        x *= value;
        y *= value;
        return *this;
    }

    // =============================== //
    //  STATIC                         //
    // =============================== //

    static double distance(const Point &a, const Point &b) {
        double x1 = static_cast<double>(a.x),
               y1 = static_cast<double>(a.y),
               x2 = static_cast<double>(b.x),
               y2 = static_cast<double>(b.y);
        return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
    }

    static double distance(const Point &p) {
        return distance(Point<T>(0, 0), p);
    }

};

};
