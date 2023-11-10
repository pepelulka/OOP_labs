#include <iostream>
#include <array>

namespace lab5 {

template<class T, size_t BlockSize = 1>
class Allocator {
private:
    static constexpr maxCount = 100000;

    char *_buffer;
    std::array<void*, maxCount>;
    size_t _availiableCount;
public:

    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = std::size_t;

    Allocator() {
        _buffer = 
    }
};

}
