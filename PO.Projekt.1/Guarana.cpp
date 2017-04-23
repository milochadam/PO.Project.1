#include "Guarana.h"
#include "World.h"

Guarana::Guarana(World&) : Plant(0, 0, 0, "Guarana", 'U', 0, world) {}
Guarana::~Guarana() {}

Guarana::Guarana(World&, int x, int y) : Plant(0, 0, 0, "Guarana", 'U', 0, world) {
	this->pos.x = x;
	this->pos.y = y;
}

void Guarana::reproduce() {
	Guarana* child = nullptr;
	if (world.organisms[pos.x][pos.y - 1] != nullptr && pos.y > 0) {
		child = new Guarana(world, pos.x, pos.y - 1);
	}
	else if (world.organisms[pos.x][pos.y + 1] != nullptr && pos.y < world.getHeight() - 1) {
		child = new Guarana(world, pos.x, pos.y + 1);

	}
	else if (world.organisms[pos.x - 1][pos.y] != nullptr && pos.x > 0) {
		child = new Guarana(world, pos.x - 1, pos.y);

	}
	else if (world.organisms[pos.x + 1][pos.y] != nullptr && pos.x < world.getWidth()) {
		child = new Guarana(world, pos.x + 1, pos.y);
	}
	world.organisms[child->pos.x][child->pos.y] = child;
	world.listOfOrganisms.push_back(child);
	world.sortByInitiative();
}

void Guarana::defense(Organism& attacker) {
	attacker.setStrength(attacker.getStrength() + 3);
	this->die();
}

void Guarana::action() {
	Plant::action();
	Plant::action();
	Plant::action();
}
