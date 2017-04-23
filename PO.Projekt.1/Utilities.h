#ifndef UTIL_H
#define UTIL_H
//#include <string>
//#include <iostream>
class Utilities
{
	//static std::random_device generator;

public:

	Utilities();
	~Utilities();
	
	static void gotoxy(int x, int y);
	static int randomMovement();
	static void setColour(int k = 15);
	static void hideCursor();
	static int randomize(int a, int b);
	static void gameOver(int turnCount, int OrganismCount);
};

#endif