#include "WolfBerry.h"
#include "World.h"

WolfBerry::WolfBerry(World&) : Plant(99, 0, 0, "WolfBerry", 'S', 0, world) {}
WolfBerry::~WolfBerry() {}

WolfBerry::WolfBerry(World&, int x, int y) : Plant(99, 0, 0, "WolfBerry", 'S', 0, world) {
	this->pos.x = x;
	this->pos.y = y;
}

void WolfBerry::reproduce() {
	WolfBerry* child = nullptr;
	if (world.organisms[pos.x][pos.y - 1] != nullptr && pos.y > 0) {
		child = new WolfBerry(world, pos.x, pos.y - 1);
	}
	else if (world.organisms[pos.x][pos.y + 1] != nullptr && pos.y < world.getHeight() - 1) {
		child = new WolfBerry(world, pos.x, pos.y + 1);

	}
	else if (world.organisms[pos.x - 1][pos.y] != nullptr && pos.x > 0) {
		child = new WolfBerry(world, pos.x - 1, pos.y);

	}
	else if (world.organisms[pos.x + 1][pos.y] != nullptr && pos.x < world.getWidth()) {
		child = new WolfBerry(world, pos.x + 1, pos.y);
	}
	world.organisms[child->pos.x][child->pos.y] = child;
	world.listOfOrganisms.push_back(child);
	world.sortByInitiative();
}

void WolfBerry::defense(Organism& attacker) {
	attacker.die();
}