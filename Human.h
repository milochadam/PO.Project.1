#ifndef HUMAN_H
#define HUMAN_H

#include "Animal.h"
class World;
class Human : public Animal {
   public:
    virtual void action() override;
    void defense(Organism& attacker) override;
    void reproduce() override;
    void draw() override;

    Human(World& w);
    ~Human();

    void debug();
};

#endif  // !HUMAN_H
