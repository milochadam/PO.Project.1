#include "Human.h"
#include <ncurses.h>
#include <iostream>
#include "World.h"
Human::Human(World& w) : Animal(Stats(10, 10, 0), w) {
    ppos.x = 0;
    ppos.y = 0;
    pos.x = 0;
    pos.y = 1;
}
Human::~Human() {
    printf("YOU HAVE DIED\n");
}

enum { KB_UP = 72, KB_DOWN = 80, KB_LEFT = 75, KB_RIGHT = 77, QUIT = 113 };

bool isEscape(char c) {
    return c == '\033';
}
bool isWASD(char c) {
    switch (c) {
        case 'w':
        case 'a':
        case 's':
        case 'd':
            return true;
        default:
            return false;
    }
}
void showPlayerPosition(int x, int y, int x1, int y1) {
    move(22, 0);
    char const* p = "       \r";
    Utilities::print(p);
    printw("%d, %d", x, y);
    move(23, 0);
    Utilities::print(p);
    printw("%d, %d", x1, y1);
}
void Human::action() {
    ppos = pos;
    Position newpos = pos;

    do {
        newpos = pos;
        KB userInput = Utilities::getUserInput();
        switch (userInput.a) {
            case 'w':
                newpos.y--;
                break;
            case 's':
                newpos.y++;
                break;
            case 'a':
                newpos.x--;
                break;
            case 'd':
                newpos.x++;
                break;
        }
        if (userInput.a == 'q')
            world.gameOver = true;
    } while (!world.isValid(newpos));
    pos = newpos;
    //showPlayerPosition(pos.x, pos.y, ppos.x, ppos.y);
    world.moveOrganism(this);
}

void Human::defense(Organism& attacker) {
    // if (attackReflected(attacker)) {
    // world.organisms[attacker.getPosX()][attacker.getPosY()] = nullptr;
    // attacker.die();
    //} else {
    // world.organisms[this->pos.x][this->pos.y] = nullptr;
    // this->die();
    //}
}

void Human::reproduce() {
}

void Human::draw() {
    Utilities::setColour(Colour::BWHITE, Colour::BBLACK);
    Utilities::print('H');
}

void Human::debug() {
    // Utilities::gotoxy(50, 20);
    // printf("getposx: %d", this->pos.x);
    // Utilities::gotoxy(50, 21);
    // printf("getposx: %d", this->pos.y);
    // Utilities::gotoxy(50, 22);
    // if (world.organisms[15][15] == nullptr)
    // printf("getposx: %d", this->pos.y);
}
