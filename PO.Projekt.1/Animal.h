#ifndef ANIMAL_H
#define ANIMAL_H
#include "Organism.h"
class Animal :
	public Organism {
public:
	// id, strength, initiative, age, species, symbol, colour, world
	Animal(int str, int init, int age, std::string species,
		char symbol, int colour, World& world);
	~Animal();
	virtual void action();
	virtual void defense(Organism& attacker);

	/*virtual bool czyRozmnazanie(Organizm& other);
	virtual void rozmnazanie() = 0;*/
};


#endif

