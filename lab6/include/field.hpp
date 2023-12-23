#pragma once

#include "npc.hpp"

#include <vector>
#include <fstream>
#include <unordered_map>

namespace lab6 {

class Field {
private:
    size_t x, y;
    size_t npcCount = 0;
    std::unordered_map<std::string, NPC*> npcs; 
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

    // True if succeed
    bool addNpc(NPC * npc) {
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

