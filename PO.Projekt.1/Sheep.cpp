#include "Sheep.h"
#include "World.h"
Sheep::Sheep(World& world) : Animal(4, 4, 0, "sheep", '@', 0, world) {
	allocate();
}
Sheep::Sheep(World& world, int x, int y) : Animal(9, 5, 0, "Sheep", 'W', 0, world) {
	this->pos.x = x;
	this->pos.y = y;
}
Sheep::~Sheep() { }


void Sheep::reproduce()
{
	Sheep* child = nullptr;
	if (world.organisms[pos.x][pos.y - 1] != nullptr && pos.y > 0) {
		child = new Sheep(world, pos.x, pos.y - 1);
	}
	else if (world.organisms[pos.x][pos.y + 1] != nullptr && pos.y < world.getHeight() - 1) {
		child = new Sheep(world, pos.x, pos.y + 1);

	}
	else if (world.organisms[pos.x - 1][pos.y] != nullptr && pos.x > 0) {
		child = new Sheep(world, pos.x - 1, pos.y);

	}
	else if (world.organisms[pos.x + 1][pos.y] != nullptr && pos.x < world.getWidth()) {
		child = new Sheep(world, pos.x + 1, pos.y);
	}
	world.organisms[child->pos.x][child->pos.y] = child;
	world.listOfOrganisms.push_back(child);
	world.sortByInitiative();
}


