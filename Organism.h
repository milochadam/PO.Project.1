#ifndef ORGANISM_H
#define ORGANISM_H
#include <string>
#include "Position.h"
#include "Utilities.h"
class World;
class Organism {
   protected:
    struct Stats {
        int strength;
        int initiative;
        int age;
        Stats(int str, int init, int age) {
            strength = str;
            initiative = init;
            this->age = age;
        }
    };

    Stats stats;
    char symbol;
    int colour;

    Position pos;
    Position ppos;
    World& world;

   public:
    Organism(Stats, World&);
    virtual ~Organism();

    // virtual
    virtual void action() = 0;
    virtual void defense(Organism& o) = 0;
    virtual void reproduce() = 0;
    virtual void draw() = 0;

    // getters
    int getStrength();
    int getInitiative() const;
    int getAge();
    Position getCurrentPosition();
    Position getPreviousPosition();

    // settery
    void setPosition(Position p);
    void setAge(int a);
    void setStrength(int s);

    bool attackReflected(Organism& attacker);
    void grow();
    void die();

    void allocate();
    void reallocate();
    static void drawEmpty();
};
#endif
