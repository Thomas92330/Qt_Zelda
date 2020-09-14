#ifndef WALL_H
#define WALL_H

#include <QGraphicsRectItem>
#include <QObject>


class Wall: public QGraphicsRectItem{
public:
    Wall(int xPos,int yPos,int xLen,int yLen);
    int xPos;
    int yPos;
    int xLen;
    int yLen;
};

#endif // WALL_H
