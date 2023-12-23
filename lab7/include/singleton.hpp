#pragma once

namespace lab7 {

template<typename T>
class Singleton {
public:
    static T& get() {
        static T instance;
        return instance;
    }

protected:
    Singleton() { }
    ~Singleton() { }
public:
    Singleton(Singleton const &) = delete;
    Singleton& operator=(Singleton const &) = delete;
};

}