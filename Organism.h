#ifndef ORGANISM_H
#define ORGANISM_H
#include <string>
#include "Utilities.h"
#include "Position.h"
class World;
class Organism
{
protected:
	int strength;
	int initiative;
	int age;

	std::string species;

	char symbol;
	int colour;


	Position pos;
	Position ppos;
	World& world;

public:
	// virtual
	virtual void action() = 0;
	virtual void defense(Organism& o) = 0;
	virtual void reproduce() = 0;
	virtual void draw();


	Organism(int, int, int, std::string, char, int, World&);
	~Organism();

	// getters
	int getStrength();
	int getInitiative() const;
	int getAge();
	std::string getSpecies();
	char getSymbol();
	int getPosX();
	int getPosY();

	//settery
	void setPosx(int x);
	void setPosy(int y);
	void setAge(int a);
	void setStrength(int s);
	
	bool attackReflected(Organism& attacker);
	void grow();
	void die();

	void allocate();
	void reallocate();
};
#endif
