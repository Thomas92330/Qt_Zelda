#include "Enemy.h"
#include <stdlib.h>  //rand() -> really large int
#include <QTimer>
#include "Game.h"


Enemy::Enemy(): QObject(), QGraphicsPixmapItem(){

    setPixmap(QPixmap(":/images/erd_w44_h43.png"));

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(1000);
}

void Enemy::move(){

    int random_direction = rand() % 4; // number between 0 and 3
    int random_distance = rand() % 20;

    if (random_direction == 0){
            for (int i = 0; i< random_distance; i++){
                if (pos().x() > 0){
                    setPos(x()-5,y());
                    setPixmap(QPixmap(":/images/erl_w42_h41.png"));
                }
    }
    }

    else if (random_direction == 1){
        for (int i = 0; i< random_distance; i++){
            if (pos().x() + 41 < scene()->width()){
                setPos(x()+5,y());
                setPixmap(QPixmap(":/images/err_w41_h41.png"));
            }
    }
    }

    else if (random_direction == 2){
        for (int i = 0; i< random_distance; i++){
            if (pos().y()> 0){
                setPos(x(),y()-5);
                setPixmap(QPixmap(":/images/eru_w41_h42.png"));
            }
    }
    }

    else if (random_direction == 3){
        for (int i = 0; i< random_distance; i++){
            if (pos().y() + 43 < scene()->height()){
                setPos(x(),y()+5);
                setPixmap(QPixmap(":/images/erd_w44_h43.png"));
            }
    }
    }
}
