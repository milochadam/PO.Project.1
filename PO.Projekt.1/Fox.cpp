#include "Fox.h"
#include "World.h"
#include "Utilities.h"

Fox::Fox(World& world) : Animal(9, 5, 0, "Fox", 'W', 0, world) {
	allocate();
}
Fox::Fox(World& world, int x, int y) : Animal(9, 5, 0, "Fox", 'W', 0, world) {
	this->pos.x = x;
	this->pos.y = y;
}
Fox::~Fox() { }
void Fox::action() {
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



void Fox::reproduce()
{
	Fox* child = nullptr;
	if (world.organisms[pos.x][pos.y - 1] != nullptr && pos.y > 0) {
		child = new Fox(world, pos.x, pos.y - 1);
	}
	else if (world.organisms[pos.x][pos.y + 1] != nullptr && pos.y < world.getHeight() - 1) {
		child = new Fox(world, pos.x, pos.y + 1);

	}
	else if (world.organisms[pos.x - 1][pos.y] != nullptr && pos.x > 0) {
		child = new Fox(world, pos.x - 1, pos.y);

	}
	else if (world.organisms[pos.x + 1][pos.y] != nullptr && pos.x < world.getWidth()) {
		child = new Fox(world, pos.x + 1, pos.y);
	}
	world.organisms[child->pos.x][child->pos.y] = child;
	world.listOfOrganisms.push_back(child);
	world.sortByInitiative();
}


