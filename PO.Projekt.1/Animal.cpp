#include "Animal.h"
#include "World.h"
#include "Utilities.h"


Animal::Animal(int str, int init, int age, std::string species, char symbol, int colour, World& world)
	: Organism(str, init, age, species, symbol, colour, world) { }
Animal::~Animal() { }

void Animal::action() {
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
		if (world.organisms[pos.x][pos.y] != this)
			world.organisms[pos.x][pos.y]->defense(*this);
	}
}

void Animal::defense(Organism & attacker) {
	//if (this->species == attacker.getSpecies()) {
	if (this->symbol == attacker.getSymbol()) {
		this->reproduce();
	}
	else {
		if (attackReflected(attacker)) {
			world.organisms[attacker.getPosX()][attacker.getPosY()] = nullptr;
			attacker.die();
		}
		else {
			world.organisms[this->pos.x][this->pos.y] = nullptr;
			this->die();
		}
	}
}

