#ifndef GRASS_H
#define GRASS_H
#include "Plant.h"
//class World;

class Grass : public Plant {
public:
	Grass(World&);
	Grass(World&, int, int);
	~Grass();
	void reproduce() override;
	void defense(Organism& attacker) override;
	//void action() override;
};

#endif
