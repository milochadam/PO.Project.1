#include "Plant.h"
#include "World.h"
#include "Utilities.h"

Plant::Plant(int str, int init, int age, std::string species, char symbol, int colour, World& world)
	: Organism(9, 5, 0, "wolf", 'W', 0, world) { }
Plant::~Plant() {}

void Plant::action() {
	if (canGrow) {
		age++;
		if (Utilities::randomize(1, chanceToGrow) == 1) {
			if (abilityToPropagate())
				reproduce();
		}

	}
}

bool Plant::abilityToPropagate() {
	if (age > 20) canGrow = false;
	if (pos.x > 0) {
		if (world.organisms[pos.x - 1][pos.y] == nullptr)
			return true;
	}
	else if (pos.x < world.getWidth()) {
		if (world.organisms[pos.x + 1][pos.y] == nullptr)
			return true;
	}
	else if (pos.y > 0) {
		if (world.organisms[pos.x][pos.y - 1] == nullptr)
			return true;
	}
	else if (pos.y < world.getHeight()) {
		if (world.organisms[pos.x][pos.y + 1] == nullptr)
			return true;
	}
	return false;
}