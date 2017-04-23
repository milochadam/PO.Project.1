#include "Dandelion.h"
#include "World.h"

Dandelion::Dandelion(World&) : Plant(0, 0, 0, "Dandelion", 'G', 0, world) {}
Dandelion::~Dandelion() {}

Dandelion::Dandelion(World&, int x, int y) : Plant(0, 0, 0, "Dandelion", 'G', 0, world) {
	this->pos.x = x;
	this->pos.y = y;
}

void Dandelion::reproduce() {
	Dandelion* child = nullptr;
	if (world.organisms[pos.x][pos.y - 1] != nullptr && pos.y > 0) {
		child = new Dandelion(world, pos.x, pos.y - 1);
	}
	else if (world.organisms[pos.x][pos.y + 1] != nullptr && pos.y < world.getHeight() - 1) {
		child = new Dandelion(world, pos.x, pos.y + 1);

	}
	else if (world.organisms[pos.x - 1][pos.y] != nullptr && pos.x > 0) {
		child = new Dandelion(world, pos.x - 1, pos.y);

	}
	else if (world.organisms[pos.x + 1][pos.y] != nullptr && pos.x < world.getWidth()) {
		child = new Dandelion(world, pos.x + 1, pos.y);
	}
	world.organisms[child->pos.x][child->pos.y] = child;
	world.listOfOrganisms.push_back(child);
	world.sortByInitiative();
}

void Dandelion::defense(Organism& attacker) {
	this->die();
}

void Dandelion::action() {
	Plant::action();
	Plant::action();
	Plant::action();
}
