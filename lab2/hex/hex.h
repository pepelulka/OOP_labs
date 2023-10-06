#pragma once

#include <cstring>
#include <initializer_list>
#include <string>
#include <iostream>

namespace pepe {

class Hex {
public:
    using uchar = unsigned char;
private:
    inline static const int BASE = 16;

    uchar * _data = nullptr;
    size_t _size = 0, _capacity = 0;

    static char toChar(uchar x);
    static uchar toValue(char c);

    uchar& operator[] (const int index);
    uchar operator[] (const int index) const;
public:
    Hex();
    Hex(const unsigned int x);
    Hex(const size_t & n, uchar t);
    Hex(const std::initializer_list<uchar> & t);
    Hex(const std::string &t);
    Hex(const char* cStr);

    Hex(const Hex& other);
    Hex(Hex&& other) noexcept;
    virtual ~Hex() noexcept;
    Hex& operator=(const Hex& other);

    std::string toString() const;
    size_t size() const;
    void resize(const size_t newSize);
    void pushBack(const uchar x);

    // Boolean
    bool operator== (const Hex& other) const;
    bool operator!= (const Hex& other) const;
    bool operator< (const Hex& other) const;
    bool operator<= (const Hex& other) const;
    bool operator> (const Hex& other) const;
    bool operator>= (const Hex& other) const;

    // Arithmetic
    Hex operator+ (const Hex& other) const;
    Hex& operator+= (const Hex& other);
    Hex operator- (const Hex& other) const;
    Hex& operator-= (const Hex& other);

    // Streams
    friend std::ostream& operator<< (std::ostream& stream, const Hex& hex);
    friend std::istream& operator>> (std::istream& stream, Hex& hex);
};

}
