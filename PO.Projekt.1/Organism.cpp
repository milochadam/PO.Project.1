#include "Organism.h"
#include "World.h"


Organism::Organism(int str, int init, int age, std::string species, char symbol, int colour, World& world)
	: strength(str), initiative(init), age(age), symbol(symbol), colour(colour), world(world) {
}

Organism::~Organism() { }

void Organism::die() {
	if (this->species == "HUMAN") {
		world.theEnd = true;
		printf("You have died\n");
	}
	else
		age = -2;
}

void Organism::allocate() {
	//this->pos.x = Utilities::randomize(0, world.getWidth() - 1);
	//this->pos.y = Utilities::randomize(0, world.getHeight() - 1);
	this->pos.x = Utilities::randomize(0, world.getWidth() - 1);
	this->pos.y = Utilities::randomize(0, world.getHeight() - 1);
	//this->pos.x = x;
	//this->pos.y = y;
	if (world.organisms[pos.x][pos.y] == nullptr)
		world.organisms[pos.x][pos.y] = this;
	else {
		reallocate();
	}
}

void Organism::reallocate()
{
	if (world.organisms[pos.x][pos.y - 1] != nullptr && pos.y > 0) {
		world.organisms[pos.x][pos.y - 1] = this;
	}
	else if (world.organisms[pos.x][pos.y + 1] != nullptr && pos.y < world.getHeight() - 1) {
		world.organisms[pos.x][pos.y + 1] = this;
	}
	else if (world.organisms[pos.x - 1][pos.y] != nullptr && pos.x > 0) {
		world.organisms[pos.x - 1][pos.y] = this;
	}
	else if (world.organisms[pos.x + 1][pos.y] != nullptr && pos.x < world.getWidth()) {
		world.organisms[pos.x + 1][pos.y] = this;
	}
	else die();
}

void Organism::draw() {


	// TODO: colour
	Utilities::gotoxy(ppos.x + 1, ppos.y + 1);
	putchar(' ');
	Utilities::gotoxy(pos.x + 1, pos.y + 1);
	putchar(symbol);
	// TODO: set colour to default
}


int Organism::getStrength() { return this->strength; }
int Organism::getInitiative() const { return this->initiative; }
int Organism::getAge() { return this->age; }
std::string Organism::getSpecies() { return this->species; }

char Organism::getSymbol() { return this->symbol; }

int Organism::getPosX() { return this->pos.x; }
int Organism::getPosY() { return this->pos.y; }

// setters
void Organism::setPosx(int x) { this->pos.x = x; }
void Organism::setPosy(int y) { this->pos.y = y; }
void Organism::setAge(int a) { this->age = a; }
void Organism::setStrength(int s) { this->strength = s; }

bool Organism::attackReflected(Organism& attacker) {
	if (this->strength > attacker.getStrength())
		return true;
	return false;
}

void Organism::grow() { this->age++; }

