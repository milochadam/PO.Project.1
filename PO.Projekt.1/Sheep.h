#ifndef SHEEP_H
#define SHEEP_H
#include "Animal.h"
class Sheep :
	public Animal
{
public:
	Sheep(World& world);
	Sheep(World& world, int x, int y);
	~Sheep();
	void reproduce() override;
};

#endif