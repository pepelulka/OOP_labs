#pragma once

#include "base.hpp"
#include "singleton.hpp"

#include <memory>
#include <vector>

namespace lab7 {

class NPC {
protected:
    Coords position;
    std::string name;
public:
    virtual std::string getType() const = 0;

    Coords getPosition() {
        return position;
    }

    std::string getName() {
        return name;
    }

    void setPosition(Coords pos) {
        position = pos;
    }

    void setName(const std::string& _name) {
        name = _name;
    }
};

class Knight : public NPC {
public:

    std::string getType() const override {
        return "Knight";
    }

    friend std::ostream& operator<< (std::ostream &stream, const Knight &obj) {
        stream << "NPC_Knight( name = " << obj.name << " " << ", position = " << obj.position << " )";
        return stream;
    }

};

class Pegas : public NPC {
public:

    std::string getType() const override {
        return "Pegas";
    }

    friend std::ostream& operator<< (std::ostream &stream, const Pegas &obj) {
        stream << "NPC_Pegas( name = " << obj.name << " " << ", position = " << obj.position << " )";
        return stream;
    }

};

class Dragon : public NPC {
public:

    std::string getType() const override {
        return "Dragon";
    }

    friend std::ostream& operator<< (std::ostream &stream, const Dragon &obj) {
        stream << "NPC_Dragon( name = " << obj.name << " " << ", position = " << obj.position << " )";
        return stream;
    }

};

class FactoryNPC {
public:
    friend class Singleton<FactoryNPC>;
private:
    std::vector<std::shared_ptr<NPC>> objects;

    FactoryNPC() = default;
    ~FactoryNPC() = default;
public:
    std::shared_ptr<NPC> create(const std::string &type, const std::string& name, Coords position) {
        std::shared_ptr<NPC> npc;
        if (type == "Knight") {
            npc = std::make_shared<Knight>();
        } else if (type == "Pegas") {
            npc = std::make_shared<Pegas>();
        } else if (type == "Dragon") {
            npc = std::make_shared<Dragon>();
        } else {
            throw std::logic_error("Undefined npc type");
        }
        npc->setName(name);
        npc->setPosition(position);
        objects.push_back(npc);
        return npc;
    }
};

using NPCCreator = Singleton<FactoryNPC>;

}