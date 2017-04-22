#include <iostream>
#include "World.h"
#include "Human.h"
#include "Interface.h"
#include "Utilities.h"
#include "Wolf.h"
#include "Grass.h"
#include <conio.h>
#define WIDTH 40
#define HEIGHT 20

int main() {

	// TODO: wymiary �wiata podane przez u�ytkownika

	World world(WIDTH, HEIGHT);

	
	//Wolf wolf(world);


	// TODO: przerobi� Interface na klas� statyczn�
	Interface i(world);
	i.draw();


	while (!world.theEnd) {
		world.drawWorld();
		world.doTurn();
		world.events();
		
	}
	//system("pause");
	return 0;
}