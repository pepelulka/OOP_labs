#include "field.hpp"

using namespace lab6;

void FieldMemento::parseFile(Field &field, const std::string& filename) {
    std::ifstream in(filename);
    size_t x, y;
    in >> x >> y;
    field = Field(x, y);
    size_t ncount;
    in >> ncount;
    for (int i = 0; i < ncount; i++) {
        std::string type, name;
        in >> type >> name >> x >> y;
        NPC * npc = Singleton<FactoryNPC>::get().create(type, name, {x, y}).get();
        if (!field.addNpc(npc)) {
            throw std::logic_error("Can't parse file properly!");
        }
    }
}

void FieldMemento::dumpFile(Field &field, const std::string& filename) {
    std::ofstream out(filename);
    Coords sz = field.getSize();
    out << sz.x << " " << sz.y << std::endl;
    size_t ncount = field.getNPCCount();
    out << ncount << std::endl;
    for (auto p : field.getNPCs()) {
        auto npc = p.second;
        out << npc->getType() << " " << npc->getName() << " " << npc->getPosition().x << " " << npc->getPosition().y << std::endl;
    }
}
