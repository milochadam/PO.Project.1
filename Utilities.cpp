#include "Utilities.h"
#include <ncurses.h>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <random>

using namespace std;

enum class Colour;
static const char* CSI = "\33[";

void Utilities::print(char c) {
    printw("%c", c);
}
void Utilities::print(char const* c) {
    printw("%s", c);
}
void Utilities::gotoxy(int x, int y) {
    // printf("%s%d;%dH", CSI, y, x);
    move(y, x);
}

int Utilities::randomMovement() {
    std::default_random_engine generator;
    std::discrete_distribution<int> distribution{
        1,
        1,
        1,
        1,
    };
    return distribution(generator);
}
void Utilities::setColour(Colour fg, Colour bg) {
    int fgcolour;
    int bgcolour;
    switch (fg) {
        case Colour::BLACK:
            fgcolour = 30;
            break;
        case Colour::RED:
            fgcolour = 31;
            break;
        case Colour::GREEN:
            fgcolour = 32;
            break;
        case Colour::YELLOW:
            fgcolour = 33;
            break;
        case Colour::BLUE:
            fgcolour = 34;
            break;
        case Colour::MAGENTA:
            fgcolour = 35;
            break;
        case Colour::CYAN:
            fgcolour = 36;
            break;
        case Colour::WHITE:
            fgcolour = 37;
            break;
        case Colour::BBLACK:
            fgcolour = 90;
            break;
        case Colour::BRED:
            fgcolour = 91;
            break;
        case Colour::BGREEN:
            fgcolour = 92;
            break;
        case Colour::BYELLOW:
            fgcolour = 93;
            break;
        case Colour::BBLUE:
            fgcolour = 94;
            break;
        case Colour::BMAGENTA:
            fgcolour = 95;
            break;
        case Colour::BCYAN:
            fgcolour = 96;
            break;
        case Colour::BWHITE:
            fgcolour = 97;
            break;
        default:
            fgcolour = 39;
            break;
    }
    switch (bg) {
        case Colour::BLACK:
            bgcolour = 40;
            break;
        case Colour::RED:
            bgcolour = 41;
            break;
        case Colour::GREEN:
            bgcolour = 42;
            break;
        case Colour::YELLOW:
            bgcolour = 43;
            break;
        case Colour::BLUE:
            bgcolour = 44;
            break;
        case Colour::MAGENTA:
            bgcolour = 45;
            break;
        case Colour::CYAN:
            bgcolour = 46;
            break;
        case Colour::WHITE:
            bgcolour = 47;
            break;
        case Colour::BBLACK:
            bgcolour = 100;
            break;
        case Colour::BRED:
            bgcolour = 101;
            break;
        case Colour::BGREEN:
            bgcolour = 102;
            break;
        case Colour::BYELLOW:
            bgcolour = 103;
            break;
        case Colour::BBLUE:
            bgcolour = 104;
            break;
        case Colour::BMAGENTA:
            bgcolour = 105;
            break;
        case Colour::BCYAN:
            bgcolour = 105;
            break;
        case Colour::BWHITE:
            bgcolour = 107;
            break;
        default:
            bgcolour = 49;
            break;
    }
    printf("%s%d;%dm", CSI, fgcolour, bgcolour);
}

void Utilities::hideCursor() {
    // HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    // CONSOLE_CURSOR_INFO info;
    // info.dwSize = 100;
    // info.bVisible = FALSE;
    // SetConsoleCursorInfo(consoleHandle, &info);
}

KB Utilities::getUserInput() {
    KB userInput;
    timeout(-1);
    userInput.a = getch();
    //endwin();
    return userInput;
}
