#ifndef HUMAN_H
#define HUMAN_H

#include "Animal.h" // czlowiek dziedziczy od animala
class World;
class Human :
	public Animal
{
	const int baseStrength=5;
	bool eliksir = false;
	int cooldown;
public:
	void action() override;
	void defense(Organism& attacker) override;
	void reproduce() override;
	
	Human(World& w);
	~Human();

	void debug() const;
};

#endif // !HUMAN_H
