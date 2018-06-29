#include "Organism.h"
#include "Utilities.h"
#include "World.h"

Organism::Organism(Stats s, World& world) : stats(s), world(world) {
}

Organism::~Organism() {
}

void Organism::die() {
}

void Organism::allocate() {
}

void Organism::reallocate() {
}
// getters
int Organism::getStrength() {
    return this->stats.strength;
}
int Organism::getInitiative() const {
    return this->stats.initiative;
}
int Organism::getAge() {
    return this->stats.age;
}
Position Organism::getCurrentPosition() {
    return this->pos;
}
Position Organism::getPreviousPosition() {
    return this->ppos;
}

// setters
void Organism::setPosition(Position p) {
    this->pos.x = p.x;
    this->pos.y = p.y;
}
void Organism::setAge(int a) {
    this->stats.age = a;
}
void Organism::setStrength(int s) {
    this->stats.strength = s;
}

bool Organism::attackReflected(Organism& attacker) {
    if (this->stats.strength > attacker.getStrength())
        return true;
    return false;
}

void Organism::grow() {
    this->stats.age++;
}

void Organism::drawEmpty() {
    Utilities::setColour(Colour::BLACK, Colour::BLACK);
    printf(" ");
}
