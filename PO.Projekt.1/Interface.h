#pragma once
#include <iostream>
#include <string>
#include "Utilities.h"
#include "World.h"
class World;
class Interface
{
public:
	const int startPosx;
	const int startPosy;
	const int width;
	const int height;
	int x;
	int y;
	World& world;
	//std::string Name;

	Interface(World& w);
	~Interface();

	void draw();
	void drawBorder();
	void drawData();
};

