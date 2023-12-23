#include "visitor.hpp"

using namespace lab7;

int Visitor::whoWin(NPC * lhs, NPC * rhs) {
    std::map<std::pair<std::string, std::string>, int> results = {
        { {"Pegas", "Pegas"}, -1 },
        { {"Pegas", "Knight"}, -1 },
        { {"Pegas", "Dragon"}, 1 },
        { {"Knight", "Pegas"}, -1 },
        { {"Knight", "Knight"}, -1 },
        { {"Knight", "Dragon"}, 0 },
        { {"Dragon", "Pegas"}, 0 },
        { {"Dragon", "Knight"}, 1 },
        { {"Dragon", "Dragon"}, -1 }
    };
    return results[std::make_pair<std::string, std::string>(lhs->getType(), rhs->getType())];
}

void Visitor::runFight(Field &field, size_t distance) {
    std::vector<std::string> objects;
    std::map<std::string, bool> killed;
    std::map<std::string, std::string> killer;
    for (auto p : field.getNPCs()) {
        killed[p.first] = false;
        objects.push_back(p.first);
    }

    for (size_t i = 0; i < killed.size(); i++) {
        for (size_t j = i + 1; j < killed.size(); j++) {
            if (Coords::sq_distance(field.getNPCs()[objects[i]]->getPosition(), field.getNPCs()[objects[j]]->getPosition()) >= distance * distance) {
                continue;
            }
            auto result = whoWin(field.getNPCs()[objects[i]], field.getNPCs()[objects[j]]);
            if (result == 1) {
                killed[objects[i]] = true;
                killer[objects[i]] = objects[j];
            } else if (result == 0) {
                killed[objects[j]] = true;
                killer[objects[j]] = objects[i];
            }
        }
    }

    for (int i = 0; i < killed.size(); i++) {
        if (killed[objects[i]]) {
            if (!field.deleteNpc(objects[i])) {
                throw std::logic_error("Can't kill (why?)");
            }
            observerPool.notifyKill(killer[objects[i]], objects[i]);
        }
    }
}
