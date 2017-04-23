#ifndef WOLFBERRY_H
#define WOLFBERRY_H
#include "Plant.h"
class WolfBerry :
	public Plant
{
public:
	WolfBerry();
	WolfBerry(World&);
	~WolfBerry();
	WolfBerry(World&, int x, int y);
	void reproduce() override;
	void defense(Organism& attacker) override;
};

#endif