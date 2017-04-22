#ifndef WOLF_H
#define WOLF_H

#include "Animal.h"

class World;
class Wolf :
	public Animal
{
public:
	void reproduce();
	
	Wolf(World& w);
	Wolf(World& w, int x, int y);
	~Wolf();
	//void action();
};

#endif // !WOLF_H