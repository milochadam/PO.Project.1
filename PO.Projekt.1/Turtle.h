#ifndef TURTLE_H
#define TURTLE_H
#include "Animal.h"
class Turtle :
	public Animal
{
public:
	Turtle(World& world);
	Turtle(World& world, int x, int y);
	~Turtle();
	void action() override;
	void reproduce() override;
	bool attackReflected(Organism& attacker);
};

#endif