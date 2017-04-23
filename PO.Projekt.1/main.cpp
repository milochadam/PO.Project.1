#include "World.h"
#include "Interface.h"
#include "Utilities.h"

#define WIDTH 40
#define HEIGHT 20

// TODO: poprawiæ w reproduce() warunek != nullptr na == nullptr

int main() {
	// TODO: wymiary œwiata podane przez u¿ytkownika
	World world(WIDTH, HEIGHT);
	Interface::draw(world);
	
	do {
		world.drawWorld();
		world.doTurn();
	} while (!world.theEnd);
	system("pause");
	Utilities::gameOver(world.getTurnCount(),world.getOrganismsSize());
	return 0;
}