#ifndef ANTELOPE_H
#define ANTELOPE_H
#include "Animal.h"
class Antelope :
	public Animal
{
public:
	Antelope(World& world);
	Antelope(World& world, int x, int y);
	~Antelope();
	bool attackReflected(Organism& attacker);
	void reproduce() override;
	void action() override;
};

#endif