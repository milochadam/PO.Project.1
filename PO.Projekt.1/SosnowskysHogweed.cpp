#include "SosnowskysHogweed.h"
#include "World.h"

SosnowskysHogweed::SosnowskysHogweed(World&) : Plant(10, 0, 0, "SosnowskysHogweed", 'S', 0, world) {}
SosnowskysHogweed::~SosnowskysHogweed() {}

SosnowskysHogweed::SosnowskysHogweed(World&, int x, int y) : Plant(10, 0, 0, "SosnowskysHogweed", 'S', 0, world) {
	this->pos.x = x;
	this->pos.y = y;
}

void SosnowskysHogweed::reproduce() {
	SosnowskysHogweed* child = nullptr;
	if (world.organisms[pos.x][pos.y - 1] != nullptr && pos.y > 0) {
		child = new SosnowskysHogweed(world, pos.x, pos.y - 1);
	}
	else if (world.organisms[pos.x][pos.y + 1] != nullptr && pos.y < world.getHeight() - 1) {
		child = new SosnowskysHogweed(world, pos.x, pos.y + 1);

	}
	else if (world.organisms[pos.x - 1][pos.y] != nullptr && pos.x > 0) {
		child = new SosnowskysHogweed(world, pos.x - 1, pos.y);

	}
	else if (world.organisms[pos.x + 1][pos.y] != nullptr && pos.x < world.getWidth()) {
		child = new SosnowskysHogweed(world, pos.x + 1, pos.y);
	}
	world.organisms[child->pos.x][child->pos.y] = child;
	world.listOfOrganisms.push_back(child);
	world.sortByInitiative();
}

void SosnowskysHogweed::defense(Organism& attacker) {
	attacker.die();
}