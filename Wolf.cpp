#include "Wolf.h"
#include "World.h"
Wolf::Wolf(World& world) : Animal(9, 5, 0, "wolf", 'W', 0, world) {
	allocate();
}
Wolf::Wolf(World& world, int x, int y) : Animal(9, 5, 0, "wolf", 'W', 0, world) {
	this->pos.x = x;
	this->pos.y = y;
}
Wolf::~Wolf() { }


void Wolf::reproduce()
{
	// TODO
	Wolf* child;
	if (world.organisms[pos.x][pos.y - 1] != nullptr && pos.y > 0) {
		child = new Wolf(world, pos.x, pos.y - 1);
	}
	else if (world.organisms[pos.x][pos.y + 1] != nullptr && pos.y < world.getHeight() - 1) {
		child = new Wolf(world, pos.x, pos.y + 1);

	}
	else if (world.organisms[pos.x - 1][pos.y] != nullptr && pos.x > 0) {
		child = new Wolf(world, pos.x - 1, pos.y);

	}
	else if (world.organisms[pos.x + 1][pos.y] != nullptr && pos.x < world.getWidth()) {
		child = new Wolf(world, pos.x + 1, pos.y);
	}
	world.organisms[child->pos.x][child->pos.y] = child;
}


