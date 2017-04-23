#include "Grass.h"
#include "World.h"

Grass::Grass(World&) : Plant(0, 0, 0, "Grass", 'G', 0, world) {}
Grass::~Grass() {}

Grass::Grass(World&, int x, int y) : Plant(0, 0, 0, "Grass", 'G', 0, world) {
	this->pos.x = x;
	this->pos.y = y;
}

void Grass::reproduce() {
	Grass* child = nullptr;
	if (world.organisms[pos.x][pos.y - 1] != nullptr && pos.y > 0) {
		child = new Grass(world, pos.x, pos.y - 1);
	}
	else if (world.organisms[pos.x][pos.y + 1] != nullptr && pos.y < world.getHeight() - 1) {
		child = new Grass(world, pos.x, pos.y + 1);

	}
	else if (world.organisms[pos.x - 1][pos.y] != nullptr && pos.x > 0) {
		child = new Grass(world, pos.x - 1, pos.y);

	}
	else if (world.organisms[pos.x + 1][pos.y] != nullptr && pos.x < world.getWidth()) {
		child = new Grass(world, pos.x + 1, pos.y);
	}
	world.organisms[child->pos.x][child->pos.y] = child;
	world.listOfOrganisms.push_back(child);
	world.sortByInitiative();
}

void Grass::defense(Organism& attacker) {
	this->die();
}
