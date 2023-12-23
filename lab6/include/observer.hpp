#pragma once

#include "npc.hpp"

#include <iostream>
#include <fstream>
#include <vector>

namespace lab6 {

class BaseObserver {
public:
    virtual void notifyKill(const std::string& killerName, const std::string& victimName) = 0;
};

class ObserverStdout : public BaseObserver {
public:
    ObserverStdout() {
        std::cout << "=== LOG START ===\n";
    }

    void notifyKill(const std::string& killerName, const std::string& victimName) override {
        std::cout << killerName << " killed " << victimName << std::endl;
    }
};

class ObserverFile : public BaseObserver {
private:
    std::ofstream out;
public:
    ObserverFile() {
        try {
            out.open("log.txt");
        } catch (...) {
            throw std::logic_error("Can't open file...");
        }
        out << "=== LOG START ===\n";
    }

    void notifyKill(const std::string& killerName, const std::string& victimName) override {
        out << killerName << " killed " << victimName << std::endl;
    }
};

class ObserverPool {
private:
    std::vector<BaseObserver*> observers;
public:
    void attach(BaseObserver * obs) {
        observers.push_back(obs);
    }

    void notifyKill(const std::string& killerName, const std::string& victimName) {
        for (auto i : observers) {
            i->notifyKill(killerName, victimName);
        }
    }

};

}