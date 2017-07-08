#ifndef WORLD_H
#define WORLD_H
#include <iostream>
#include <list>
#include <algorithm>

#include "Organism.h"
#include "Utilities.h"
#include "Human.h"
#include "Wolf.h"
#include "Dandelion.h"
class Organism;
class Human;
class Wolf;
class Danelion;
class World
{
	std::list <Organism*> listOfOrganisms;
public:
	Organism*** organisms;
	bool theEnd = false;
private:
	const int width;
	const int height;
	int turn;

public:
	World(int width, int height);
	~World();
	void addOrganism(Organism* o);
	void sortByInitiative();
	void drawWorld();
	void doTurn();
	void events();

	int getWidth();
	int getHeight();

	int getOrganismsSize();
};
#endif // !WORLD_H