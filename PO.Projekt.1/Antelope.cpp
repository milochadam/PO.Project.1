#include "Antelope.h"
#include "World.h"
#include "Utilities.h"

Antelope::Antelope(World& world) : Animal(4, 4, 0, "wolf", 'W', 0, world) {
	allocate();
}
Antelope::Antelope(World& world, int x, int y) : Animal(4, 4, 0, "wolf", 'W', 0, world) {
	this->pos.x = x;
	this->pos.y = y;
	allocate();
}
Antelope::~Antelope() {}

bool Antelope::attackReflected(Organism& attacker) {
	if (Utilities::randomize(0, 1) == 1) {
		this->reallocate();
		return true;
	}
	return false;
}

void Antelope::reproduce() {
	Antelope* child = nullptr;
	if (world.organisms[pos.x][pos.y - 1] != nullptr && pos.y > 0) {
		child = new Antelope(world, pos.x, pos.y - 1);
	}
	else if (world.organisms[pos.x][pos.y + 1] != nullptr && pos.y < world.getHeight() - 1) {
		child = new Antelope(world, pos.x, pos.y + 1);

	}
	else if (world.organisms[pos.x - 1][pos.y] != nullptr && pos.x > 0) {
		child = new Antelope(world, pos.x - 1, pos.y);

	}
	else if (world.organisms[pos.x + 1][pos.y] != nullptr && pos.x < world.getWidth()) {
		child = new Antelope(world, pos.x + 1, pos.y);
	}
	world.organisms[child->pos.x][child->pos.y] = child;
	world.listOfOrganisms.push_back(child);
	world.sortByInitiative();
}
void Antelope::action() {
	Animal::action();
	Animal::action();
}