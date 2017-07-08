#ifndef HUMAN_H
#define HUMAN_H

#include <conio.h>
#include "Animal.h" // czlowiek dziedziczy od animala
class World;
class Human :
	public Animal
{
public:
	void action() override;
	void defense(Organism& attacker);
	void reproduce();
	
	Human(World& w);
	~Human();

	void debug();
};

#endif // !HUMAN_H
