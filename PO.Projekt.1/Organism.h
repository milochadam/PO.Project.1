#ifndef ORGANISM_H
#define ORGANISM_H
#include <string>
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


	Organism(int str, int init, int age, std::string, char symbol, int, World&);
	virtual ~Organism();

	// getters
	int getStrength() const;
	int getInitiative() const;
	int getAge() const;
	std::string getSpecies() const;
	char getSymbol() const;
	int getPosX() const;
	int getPosY() const;
	int getPPosX() const;
	int getPPosY() const;

	//settery
	void setPosx(int x);
	void setPosy(int y);
	void setAge(int a);
	void setStrength(int s);
	
	bool attackReflected(Organism& attacker);
	void die();

	void allocate();
	void reallocate();
};
#endif
