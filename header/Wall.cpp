#include "Wall.h"
#include "Game.h"

Wall::Wall(int xPos,int yPos,int xLen,int yLen): QGraphicsRectItem(){

    //set the graphics
    setRect(xPos,yPos,xLen,yLen);
}
