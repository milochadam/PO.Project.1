#include "Animal.h"
#include "World.h"

Animal::Animal(Stats stats, World& world) : Organism(stats, world) {
}

void Animal::action() {
    ppos = pos;
    // int direction = Utilities::randomize(0, 3);
    int direction = 0;
    switch (direction) {
        case 0:
            if (pos.y > 0)
                pos.y--;
            // go up
            break;
        case 1:
            if (pos.y < world.height() - 1)
                pos.y++;
            // go down
            break;
        case 2:
            if (pos.x > 0)
                pos.x--;
            // go left
            break;
        case 3:
            if (pos.x < world.width() - 1)
                pos.x++;
            // go right
            break;
    }
    world.moveOrganism(this);
}

void Animal::defense(Organism& attacker) {
}
