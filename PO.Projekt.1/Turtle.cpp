#include "Turtle.h"
#include "World.h"
#include "Utilities.h"

Turtle::Turtle(World& world) : Animal(2, 1, 0, "Turtle", 'T', 0, world) {
	allocate();
}
Turtle::Turtle(World& world, int x, int y) : Animal(9, 5, 0, "Turtle", 'W', 0, world) {
	this->pos.x = x;
	this->pos.y = y;
}
Turtle::~Turtle() { }
void Turtle::action() {
	//dodaj wiek;
	age++;
	ppos = pos;
	//int direction = Utilities::randomize(0, 3);
	int direction = Utilities::randomize(0, 3);
	switch (direction) {
	case 0:
		if (pos.y > 0)
			pos.y--;
		//go up
		break;
	case 1:
		if (pos.y < world.getHeight() - 1)
			pos.y++;
		//go down
		break;
	case 2:
		if (pos.x > 0)
			pos.x--;
		//go left
		break;
	case 3:
		if (pos.x < world.getWidth() - 1)
			pos.x++;
		//go right
		break;
	}
	if (world.organisms[pos.x][pos.y] == nullptr) {
		world.organisms[ppos.x][ppos.y] = nullptr;
		world.organisms[pos.x][pos.y] = this;
	}
	else {
		if (world.organisms[pos.x][pos.y] != this) {
			if (world.organisms[pos.x][pos.y]->getStrength() > this->strength)
				reallocate();
			world.organisms[pos.x][pos.y]->defense(*this);
		}
	}
	age++;
}



void Turtle::reproduce()
{
	Turtle* child = nullptr;
	if (world.organisms[pos.x][pos.y - 1] != nullptr && pos.y > 0) {
		child = new Turtle(world, pos.x, pos.y - 1);
	}
	else if (world.organisms[pos.x][pos.y + 1] != nullptr && pos.y < world.getHeight() - 1) {
		child = new Turtle(world, pos.x, pos.y + 1);

	}
	else if (world.organisms[pos.x - 1][pos.y] != nullptr && pos.x > 0) {
		child = new Turtle(world, pos.x - 1, pos.y);

	}
	else if (world.organisms[pos.x + 1][pos.y] != nullptr && pos.x < world.getWidth()) {
		child = new Turtle(world, pos.x + 1, pos.y);
	}
	world.organisms[child->pos.x][child->pos.y] = child;
	world.listOfOrganisms.push_back(child);
	world.sortByInitiative();
}


bool Turtle::attackReflected(Organism& attacker) {
	if (attacker.getStrength()<5) {
		attacker.setPosx(attacker.getPPosX());
		attacker.setPosy(attacker.getPPosY());
		return true;
	}
	return false;
}
