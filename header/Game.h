#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "WallManager.h"


class Game: public QGraphicsView{
    Q_OBJECT
public:
    // constructors
    Game(QWidget * parent =0);

    // public methods
    void displayMainMenu();

    //public attributes
    QGraphicsScene * scene;
    Player * player;
    WallManager* wallManager;

public slots:
    void start();
};



#endif // GAME_H
