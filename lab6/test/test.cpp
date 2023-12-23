#include <gtest/gtest.h>

#include "field.hpp"
#include "visitor.hpp"

using namespace lab6;

TEST(Lab6, Test1) {
    NPC * npc = NPCCreator::get().create("Knight", "meow", {1, 1}).get();
    EXPECT_EQ(npc->getType(), "Knight");
    npc = NPCCreator::get().create("Dragon", "meow", {1, 1}).get();
    EXPECT_EQ(npc->getType(), "Dragon");
    npc = NPCCreator::get().create("Pegas", "meow", {1, 1}).get();
    EXPECT_EQ(npc->getType(), "Pegas");
} 

TEST(Lab6, Test2) {
    Field field(100, 100);
    Visitor vis;
    field.addNpc(NPCCreator::get().create(
        "Knight", "obj1", {1, 5}
    ).get());
    field.addNpc(NPCCreator::get().create(
        "Dragon", "obj2", {2, 5}
    ).get());
    vis.runFight(field, 100);
    EXPECT_EQ(field.getNPCCount(), 1);
}

TEST(Lab6, Test3) {
    Field field(100, 100);
    Visitor vis;
    field.addNpc(NPCCreator::get().create(
        "Knight", "obj1", {1, 5}
    ).get());
    field.addNpc(NPCCreator::get().create(
        "Dragon", "obj2", {10, 5}
    ).get());
    vis.runFight(field, 1);
    EXPECT_EQ(field.getNPCCount(), 2);
}
