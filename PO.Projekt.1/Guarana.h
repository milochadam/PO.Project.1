#ifndef GUARANA_H
#define GUARANA_H
#include "Plant.h"
class Guarana : public Plant {
public:
	Guarana(World&);
	Guarana(World&, int, int);
	~Guarana();
	void reproduce() override;
	void defense(Organism& attacker) override;
	void action() override;
};
#endif