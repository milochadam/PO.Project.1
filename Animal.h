#ifndef ANIMAL_H
#define ANIMAL_H
#include "Organism.h"
class Animal : public Organism {
   public:
    Animal(Stats, World&);
    virtual void action() override;
    virtual void defense(Organism& attacker) override;
};

#endif
