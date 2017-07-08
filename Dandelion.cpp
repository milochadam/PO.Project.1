#include "Dandelion.h"



void Dandelion::action()
{
	if (isRoom()) {
		if (world.organisms[pos.x - 1][pos.y] == nullptr) {
			Dandelion* dandelion = new Dandelion(world);
			world.organisms[pos.x - 1][pos.y] = dandelion;
			world.addOrganism(dandelion);
		}
	}
}

void Dandelion::draw()
{
}

void Dandelion::collision()
{
}

void Dandelion::defense(Organism& o)
{
}

void Dandelion::reproduce()
{
}

void Dandelion::die()
{
}

bool Dandelion::isRoom()
{
	if (world.organisms[pos.x - 1][pos.y] == nullptr ||
		world.organisms[pos.x + 1][pos.y] == nullptr ||
		world.organisms[pos.x][pos.y + 1] == nullptr ||
		world.organisms[pos.x][pos.y - 1] == nullptr)
		return true;
	return false;
}

Dandelion::Dandelion(World& w) : world(w), id(2), initiative(0), symbol('D'), colour(0), pos(0,0)
{
}


Dandelion::~Dandelion()
{
}
