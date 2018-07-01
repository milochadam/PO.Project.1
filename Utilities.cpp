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
            fgcolour = COLOR_BLACK;
            break;
        case Colour::RED:
            fgcolour = COLOR_RED;
            break;
        case Colour::GREEN:
            fgcolour = COLOR_GREEN;
            break;
        case Colour::YELLOW:
            fgcolour = COLOR_YELLOW;
            break;
        case Colour::BLUE:
            fgcolour = COLOR_BLUE;
            break;
        case Colour::MAGENTA:
            fgcolour = COLOR_MAGENTA;
            break;
        case Colour::CYAN:
            fgcolour = COLOR_CYAN;
            break;
        case Colour::WHITE:
            fgcolour = COLOR_WHITE;
            break;
        default:
            fgcolour = COLOR_BLACK;
            break;
    }
    switch (bg) {
        case Colour::BLACK:
            bgcolour = COLOR_BLACK;
            break;
        case Colour::RED:
            bgcolour = COLOR_RED;
            break;
        case Colour::GREEN:
            bgcolour = COLOR_GREEN;
            break;
        case Colour::YELLOW:
            bgcolour = COLOR_YELLOW;
            break;
        case Colour::BLUE:
            bgcolour = COLOR_BLUE;
            break;
        case Colour::MAGENTA:
            bgcolour = COLOR_MAGENTA;
            break;
        case Colour::CYAN:
            bgcolour = COLOR_CYAN;
            break;
        case Colour::WHITE:
            bgcolour = COLOR_WHITE;
            break;
        default:
            bgcolour = COLOR_BLACK;
            break;
    }
    init_pair(1, fgcolour, bgcolour);
    attron(COLOR_PAIR(1));
    // printf("%s%d;%dm", CSI, fgcolour, bgcolour);
}

void Utilities::hideCursor() {
    // HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    // CONSOLE_CURSOR_INFO info;
    // info.dwSize = 100;
    // info.bVisible = FALSE;
    // SetConsoleCursorInfo(consoleHandle, &info);
}

char Utilities::getUserInput() {
    char userInput;
    timeout(-1);
    userInput = getch();
    // endwin();
    return userInput;
}
