#ifndef SOSNOWSKYSHOGWEED_H
#define SOSNOWSKYSHOGWEED_H
#include "Plant.h"
class SosnowskysHogweed : public Plant {
public:
	SosnowskysHogweed(World&);
	SosnowskysHogweed(World&, int, int);
	~SosnowskysHogweed();
	void reproduce() override;
	void defense(Organism& attacker) override;
};
#endif