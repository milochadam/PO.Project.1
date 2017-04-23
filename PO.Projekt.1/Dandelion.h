#ifndef DANDELION_H
#define DANDELION_H
#include "Plant.h"

class Dandelion : public Plant {
public:
	Dandelion(World&);
	Dandelion(World&, int, int);
	~Dandelion();
	void reproduce() override;
	void defense(Organism& attacker) override;
	void action() override;
};
#endif