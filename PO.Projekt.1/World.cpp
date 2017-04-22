#include "World.h"
#define WOLF_COUNT 1

World::World(int width, int height) : turn(0), width(width), height(height) {
	int i, j;
	//int x, y;
	organisms = new Organism**[height];
	for (i = 0; i < width; i++) {
		organisms[i] = new Organism*[width];
		for (j = 0; j < height; j++) {
			organisms[i][j] = nullptr;
		}
	}

	addOrganism(new Human(*this));
	addOrganism(new Wolf(*this));
	//for (i = 0; i < WOLF_COUNT; i++) {
	//	x = Utilities::randomize(0, getWidth() - 1);
	//	y = Utilities::randomize(0, getHeight() - 1);
	//	
	//}
	Utilities::hideCursor();
	//listOfOrganisms.sort([](const Organism * a, const Organism *b) { return (*a).getInitiative() < (*b).getInitiative(); });
	sortByInitiative();
}


World::~World()
{
	listOfOrganisms.erase(listOfOrganisms.begin(), listOfOrganisms.end());
	int i;
	for (i = 0; i < width; i++) {
		delete[] organisms[i];
	}
	delete organisms;
}

void World::addOrganism(Organism* o) {
	listOfOrganisms.push_back(o);
}
void World::sortByInitiative() {
	listOfOrganisms.sort([](const Organism * a, const Organism * b) { return (*a).getInitiative() > (*b).getInitiative(); });
}


void World::drawWorld() {
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
}

void World::doTurn() {
	this->turn++;
	// usuwanie 
	std::list<Organism*>::iterator it;
	//std::list<Organism*>::reverse_iterator rit;
	for (it = listOfOrganisms.begin(); it != listOfOrganisms.end(); ++it) {
		(*it)->action();
	}
	/*for (rit = listOfOrganisms.rbegin(); rit != listOfOrganisms.rend(); ++rit) {
		if ((*it)->getAge() < 0)
			listOfOrganisms.erase(it);
	}*/
	for (it = listOfOrganisms.begin(); it != listOfOrganisms.end(); ++it) {
		if ((*it)->getAge() < 0)
			it=listOfOrganisms.erase(it);
	}
}

void World::events()
{
	Utilities::gotoxy(50, 5);
	printf("Tura nr: %d", turn);
}

int World::getWidth() {	return width; }
int World::getHeight() { return height; }


int World::getOrganismsSize()
{
	return listOfOrganisms.size();
}

