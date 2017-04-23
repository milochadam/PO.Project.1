#ifndef WORLD_H
#define WORLD_H
#include "Organism.h"
#include "Dandelion.h"
#include <vector>
#include <list>
class Organism;
class Human;
class Wolf;
class Danelion;
class World
{
	friend class Interface;
public:
	std::list<Organism*> listOfOrganisms;
	Organism*** organisms;
	bool theEnd = false;
private:
	const int width;
	const int height;
	int turn;

public:
	World(int width, int height);
	~World();
	void sortByInitiative();
	void drawWorld() const;
	void doTurn();
	void events() const;

	int getWidth() const;
	int getHeight() const;
	int getTurnCount() const;
	int getOrganismsSize() const;
};
#endif // !WORLD_H