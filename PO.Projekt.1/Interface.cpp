#include "Interface.h"
#include "Utilities.h"
#define DATAX 0
#define DATAY 1

Interface::Interface(/*World& w*/) : startPosx(1), startPosy(1), width(40), height(20)/*, world(w), */ {}
Interface::~Interface() {}

void Interface::draw(World& world)
{
	drawBorder(world);
	drawData(world);
}

void Interface::drawBorder(World& world) {
	int i, j;
	Utilities::gotoxy(0, 0);
	for (i = 0; i < world.getWidth() + 2; i++)
	{
		putchar('=');
	}
	putchar('\n');
	for (i = 0; i < world.getHeight(); i++)
	{
		putchar('|');
		for (j = 0; j < world.getWidth(); j++)
		{
			putchar(' ');
		}
		putchar('|');
		putchar('\n');
	}
	for (i = 0; i < world.getWidth() + 2; i++)
	{
		putchar('=');
	}
	putchar('\n');
}

void Interface::drawData(World& world)
{
	int x = world.getWidth() + 2;
	int y = 0;
	Utilities::gotoxy(DATAX+x, DATAY+y++);
	printf("==============================");
	Utilities::gotoxy(DATAX + x, DATAY + y++);
	printf("Autor: Adam");
	Utilities::gotoxy(DATAX + x, DATAY + y++);
	printf("==============================");

}



