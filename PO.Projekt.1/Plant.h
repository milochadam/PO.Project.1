#ifndef PLANT_H
#define PLANT_H
#include "Organism.h"

class Plant : public Organism {
protected:
	bool canGrow = true;
	int chanceToGrow;
public:
	Plant(int str, int init, int age, std::string species, char symbol, int colour, World& world);
	~Plant();
	virtual void action();
	bool abilityToPropagate();

};
#endif