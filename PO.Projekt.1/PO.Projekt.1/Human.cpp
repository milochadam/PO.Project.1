#include "Human.h"
#include "World.h"
Human::Human(World& w) : Animal(10, 4, 0, "human", 'A', 0, w) { }
Human::~Human() { printf("YOU HAVE DIED\n"); }

enum {
	KEY_UP = 72,
	KEY_DOWN = 80,
	KEY_LEFT = 75,
	KEY_RIGHT = 77,
	QUIT = 113
};

void Human::action()
{
	ppos = pos;
	int key = getch();
	if (key == 0xE0)
		switch (getch()) {
		case KEY_UP:
			if (pos.y > 0)
				pos.y--;
			break;
		case KEY_DOWN:
			if (pos.y < world.getHeight() - 1)
				pos.y++;
			break;
		case KEY_LEFT:
			if (pos.x > 0)
				pos.x--;
			break;
		case KEY_RIGHT:
			if (pos.x < world.getWidth() - 1)
				pos.x++;
			break;
		}
	else if (key == 'q')
		world.theEnd = true;
	//else
		//printf("%d", world.getOrganismsSize());
	Organism* other = world.organisms[pos.x][pos.y];
	if (other != nullptr && other != this) {
		other->defense(*this);
	}
	else {
		world.organisms[ppos.x][ppos.y] = nullptr;
		world.organisms[pos.x][pos.y] = this;
	}
	//this->debug();
}






void Human::defense(Organism& attacker)
{
	if (attackReflected(attacker)) {
		world.organisms[attacker.getPosX()][attacker.getPosY()] = nullptr;
		attacker.die();
	}
	else {
		world.organisms[this->pos.x][this->pos.y] = nullptr;
		this->die();
	}
}

void Human::reproduce()
{
}


void Human::debug()
{
	Utilities::gotoxy(50, 20);
	printf("getposx: %d", this->pos.x);
	Utilities::gotoxy(50, 21);
	printf("getposx: %d", this->pos.y);
	Utilities::gotoxy(50, 22);
	if (world.organisms[15][15] == nullptr)
		printf("getposx: %d", this->pos.y);
}

//¶