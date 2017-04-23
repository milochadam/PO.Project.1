#pragma once
#include "World.h"
class World;
class Interface
{
public:
	const int startPosx;
	const int startPosy;
	const int width;
	const int height;
	//World& world;
	//std::string Name;

	Interface(/*World& w*/);
	~Interface();

	static void draw(World& world);
	static void drawBorder(World& world);
	static void drawData(World& world);
};