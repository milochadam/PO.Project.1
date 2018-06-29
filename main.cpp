#include <ncurses.h>
#include <cstdio>
#include "Human.h"
#include "Utilities.h"
#include "World.h"
#define WIDTH 20
#define HEIGHT 10

int main() {
    // necessary for ncurses
    initscr();
    curs_set(0);
    World world(WIDTH, HEIGHT);
    Human* player = new Human(world);
    world.addOrganism(player);

    world.drawWorld();
    do {
        world.executeTurn();
        world.drawWorld();
    } while (!world.gameOver);
    endwin();
    return 0;
}
