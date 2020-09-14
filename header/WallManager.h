#ifndef WALLMANAGER_H
#define WALLMANAGER_H

// class pour placer des murs en vertical , horizontale etc...
// voir video youtube C++ game tutorial hexboard

#include <QList>
#include "Wall.h"

class WallManager{
public:
    //constructors
    WallManager();

    //getters/setters
    QList<Wall*> getWalls();

    //public methods
    void placeWallsInLine(int xPos,int yPos, int numberOfWalls);
    void placeWallsInColumns(int xPos,int yPos, int numberOfWalls);

private:
    QList<Wall*> walls;
};



#endif // WALLMANAGER_H
