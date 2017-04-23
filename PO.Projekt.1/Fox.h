#ifndef FOX_H
#define FOX_H
#include "Animal.h"
class Fox :
	public Animal
{
public:
	Fox();
	Fox(World& world);
	Fox(World& world, int x, int y);
	~Fox();
	void action() override;
	void reproduce() override;
};

#endif