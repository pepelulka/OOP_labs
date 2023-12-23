#include <iostream>

#include "field.hpp"
#include "visitor.hpp"

using namespace lab6;

int main() {
    // Prerequisites
    ObserverStdout obs;
    ObserverFile obsFile;
    Visitor vis;
    vis.observerPool.attach(&obs);
    vis.observerPool.attach(&obsFile);
    Field field;
    //
    FieldMemento::parseFile(field, "in.txt");
    vis.runFight(field, 10);
    std::shared_ptr<NPC> npc = Singleton<FactoryNPC>::get().create("Knight", "meow", {2, 5});
    field.addNpc(npc.get());
    FieldMemento::dumpFile(field, "out.txt");
}