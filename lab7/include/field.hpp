#pragma once

#include "npc.hpp"

#include <vector>
#include <fstream>
#include <unordered_map>
#include <thread>
#include <mutex>

namespace lab7 {

class Field {
private:
    size_t x, y;
    size_t npcCount = 0;
    std::unordered_map<std::string, NPC*> npcs; 
    
    std::mutex mut;
    
public:
    Field(size_t _x, size_t _y) {
        x = _x;
        y = _y;
    }

    Field() {
        x = 100, y = 100;
    }

    Coords getSize() {
        return {x, y};
    }

    void randomWalk() {
        // const std::lock_guard<std::mutex> lock(mut);
        for (auto p : npcs) {
            auto npc = p.second;
            npc->setPosition(Coords::makeRandWalk(npc->getPosition(), 10, x, y));
        }
    }

    void printField() {
        std::cout << std::endl;
        std::vector<std::vector<char>> a(x, std::vector<char>(y));
        for (size_t i = 0; i < x; i++) {
            for (size_t j = 0; j < y; j++) {
                a[i][j] = '.';
            }
        }
        {
            const std::lock_guard<std::mutex> lock(mut);
            for (auto p : npcs) {
                auto npc = p.second;
                char c;
                if (npc->getType() == "Knight") {
                    c = 'K';
                } else if (npc->getType() == "Pegas") {
                    c = 'P';
                } else if (npc->getType() == "Dragon") {
                    c = 'D';
                }
                auto pos = npc->getPosition();
                a[pos.x][pos.y] = c;
            }
        }
        for (size_t i = 0; i < x; i++) {
            for (size_t j = 0; j < y; j++) {
                std::cout << a[i][j];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    // True if succeed
    bool addNpc(NPC * npc) {
        const std::lock_guard<std::mutex> lock(mut);
        if (npcs.find(npc->getName()) == npcs.end()) {
            auto pos = npc->getPosition();
            if (pos.x >= x || pos.y >= y) {
                return false;
            } 
            npcs[npc->getName()] = npc;
            npcCount++;
            return true;
        }
        return false;
    }

    bool deleteNpc(const std::string &name) {
        const std::lock_guard<std::mutex> lock(mut);
        if (npcs.find(name) != npcs.end()) {
            npcs.erase(name);
            npcCount--;
            return true;
        }
        return false;
    }

    std::unordered_map<std::string, NPC*> getNPCs() {
        return npcs;
    }

    size_t getNPCCount() {
        return npcCount;
    }
};

class FieldMemento {
public:

    // Format of file:
    // ===========================
    // 1 x y
    // 2 npcCount
    // 3 npc1_type, npc1_name, npc1_pos_x, npc1_pos_y
    // 4 ... 
    // 5 ...

    static void parseFile(Field &field, const std::string& filename);

    static void dumpFile(Field &field, const std::string& filename);

};

};

