#include "World.h"
#include <ncurses.h>
#include "Human.h"
#include "Utilities.h"
#define WOLF_COUNT 1

World::World(int width, int height)
    : _width(width), _height(height), _map(width, height) {
    _turn = 1;
    for (int i = 0; i < _width; i++) {
        for (int j = 0; j < _height; j++) {
            _map(i, j) = nullptr;
        }
    }
}

World::~World() {
    destroyOrganisms();
}

bool World::isValid(Position p) {
    if (p.x < 0 || p.y < 0)
        return false;
    if (p.x >= _width || p.y >= _height)
        return false;
    return true;
}

void World::drawWorld() {
    // Utilities::gotoxy(0, 0);
    // for (int j = 0; j < _height; ++j) {
    // for (int i = 0; i < _width; ++i) {
    // Utilities::print(' ');
    //}
    // Utilities::print('\n');
    //}
    // for (auto it = listOfOrganisms.begin(); it != listOfOrganisms.end();
    // ++it) { Position pos = (*it)->getCurrentPosition();
    // Utilities::gotoxy(pos.x, pos.y);
    //(*it)->draw();
    //}

    Position startDrawing(1, 1);
    for (int j = 0; j < _height; ++j) {
        Utilities::gotoxy(startDrawing.x, startDrawing.y + j);

        for (int i = 0; i < _width; ++i) {
            if (_map(i, j) == nullptr) {
                Utilities::setColour(Colour::DEFAULT, Colour::DEFAULT);
                Utilities::print(' ');
            } else {
                _map(i, j)->draw();
            }
        }
        Utilities::print('\n');
    }
}

void World::executeTurn() {
    this->_turn++;
    for (auto it = listOfOrganisms.begin(); it != listOfOrganisms.end(); ++it) {
        (*it)->action();
    }
}

void World::initPlayer(Position p) {
    Human* player = new Human(*this);
    player->setPosition(p);
    addOrganism(player);
}
void World::addOrganism(Organism* o) {
    Position pos = o->getCurrentPosition();
    _map(pos.x, pos.y) = o;
    listOfOrganisms.push_back(o);
}

void World::moveOrganism(Organism* o) {
    Position pos = o->getCurrentPosition();
    Position ppos = o->getPreviousPosition();
    _map(ppos.x, ppos.y) = nullptr;
    _map(pos.x, pos.y) = o;
}

void World::destroyOrganisms() {
    for (auto it = listOfOrganisms.begin(); it != listOfOrganisms.end(); ++it) {
        delete *it;
    }
}

int World::width() {
    return _width;
}
int World::height() {
    return _height;
}
