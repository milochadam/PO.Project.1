#ifndef WORLD_H
#define WORLD_H
#include <list>
#include "Array2D.h"

class Organism;
class Position;
class World {
    std::list<Organism*> listOfOrganisms;

   public:
    bool gameOver = false;

   private:
    const int _width;
    const int _height;
    Array2D<Organism*> _map;
    int _turn;

   public:
    World(int width, int height);
    ~World();

    bool isValid(Position p);

    void drawWorld();
    void executeTurn();
    void initPlayer(Position p);
    void addOrganism(Organism* o);
    void moveOrganism(Organism* o);
    void destroyOrganisms();

    int width();
    int height();
};
#endif  // !WORLD_H
