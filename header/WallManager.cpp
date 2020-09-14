#include "WallManager.h"
#include "Game.h"

extern Game * game;

WallManager::WallManager()
{

}

QList<Wall*> WallManager:: getWalls(){
    return walls;
}

void WallManager::placeWallsInLine(int xPos,int yPos, int numberOfWalls)
{
    //create a cilumn of wall at the specified location
    //number of walls
    for (size_t i = 0,n = numberOfWalls; i<n;i++){
        Wall* wall = new Wall(xPos*i,yPos,100*i,100);
        walls.append(wall);
        game->scene->addItem(wall);
    }
}

void WallManager::placeWallsInColumns(int xPos,int yPos, int numberOfWalls)
{
    //create a cilumn of wall at the specified location
    //number of walls
    for (size_t i = 0,n = numberOfWalls; i<n;i++){
        Wall* wall = new Wall(xPos,yPos*i,100,100*i);
        walls.append(wall);
        game->scene->addItem(wall);
    }
}
