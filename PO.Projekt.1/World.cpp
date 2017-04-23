#include "World.h"
#include "Utilities.h"
#include "Human.h"
#include "Wolf.h"
#include <algorithm>
#include <iostream>
#define WOLF_COUNT 1

World::World(int width, int height) : width(width), height(height), turn(0) {
	//int x, y;
	organisms = new Organism**[height];
	for (int i = 0; i < width; i++) {
		organisms[i] = new Organism*[width];
	}
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			organisms[x][y] = nullptr;
		}
	}

	listOfOrganisms.push_back(new Human(*this));
	listOfOrganisms.push_back(new Wolf(*this));
	Utilities::hideCursor();
	sortByInitiative();
}


World::~World()
{
	listOfOrganisms.erase(listOfOrganisms.begin(), listOfOrganisms.end());
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (organisms[i][j])
				delete organisms[i][j];
		}
	}
	//for (int i = 0; i < width; i++) {
	//	delete[] organisms[i];
	//}
	//delete organisms;
}

void World::sortByInitiative() {
	listOfOrganisms.sort([](Organism *a, Organism *b) { return a->getInitiative() < b->getInitiative(); });
}


void World::drawWorld() const {
	int i, j;
	for (i = 0; i < width; i++)
	{
		for (j = 0; j < height; j++)
		{
			if (organisms[i][j]) {
				Utilities::gotoxy(i + 1, j + 1);
				organisms[i][j]->draw();
			}
		}
	}
	events();
}

void World::doTurn() {
	drawWorld();
	for (std::list<Organism*>::iterator it = listOfOrganisms.begin(); it != listOfOrganisms.end(); ++it) {
		(*it)->action();
	}

	//for (std::list<Organism*>::iterator it = listOfOrganisms.begin(); it != listOfOrganisms.end(); ++it) {
	//	if ((*it)->getAge() < 0)
	//		it=listOfOrganisms.erase(it);
	//}


	this->turn++;
}

void World::events() const {
	Utilities::gotoxy(50, 5);
	printf("Tura nr: %d", turn);
}

int World::getWidth() const { return width; }
int World::getHeight() const { return height; }


int World::getOrganismsSize() const { return listOfOrganisms.size(); }

int World::getTurnCount() const { return turn; }