#include "Player.h"
#include <QKeyEvent>
#include "Game.h"
#include <QTimer>
// !!! probleme de vérifier en amont si le personnage va rentrer dans un mur

#include <QDebug>
Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    //set graphic default
    setPixmap(QPixmap(":/images/lgd_w39_h40.png"));

}

void Player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){

        if (pos().x() > 0){
        setPos(x()-10,y());
        horientation = 0;  //horientation = 0 => Player horienter vers gauche
        setPixmap(QPixmap(":/images/lgl_w40_h41.png"));
        }

        //faire en sorte que le personnage n'avance pas si il est a coté d'un mur
        QList<QGraphicsItem *> colliding_items = collidingItems();
        qDebug() << colliding_items.size();
        for (size_t i = 0, n  = colliding_items.size(); i< n ; ++i){
            Wall * wall = dynamic_cast<Wall *>(colliding_items[i]);
            if(wall && !push){
                setPos(x()+10,y());
                push = true;
            }
        }
        push = false;
        colliding_items.clear();
    }

    else if (event->key() ==  Qt::Key_Right){

        if (pos().x() + 38 < scene()->width()){
        setPos(x()+10,y());
        horientation = 1;  //horientation = 1 => Player horienter vers droite
        setPixmap(QPixmap(":/images/lgr_w38_h39.png"));
        }

        //faire en sorte que le personnage n'avance pas si il est a coté d'un mur
        QList<QGraphicsItem *> colliding_items = collidingItems();
        qDebug() << colliding_items.size();
        for (size_t i = 0, n  = colliding_items.size(); i< n ; ++i){
            Wall * wall = dynamic_cast<Wall *>(colliding_items[i]);
            if(wall && !push){
                setPos(x()-10,y());
                push = true;
            }
        }
        push = false;
        colliding_items.clear();
    }

    else if (event->key() == Qt::Key_Up){

        if (pos().y()> 0){
            setPos(x(),y()-10);
            horientation = 2;  //horientation = 2 => Player horienter vers haut
            setPixmap(QPixmap(":/images/lgu_w33_h40.png"));
        }

        //faire en sorte que le personnage n'avance pas si il est a coté d'un mur
        QList<QGraphicsItem *> colliding_items = collidingItems();
        qDebug() << colliding_items.size();
        for (size_t i = 0, n  = colliding_items.size(); i< n ; ++i){
            Wall * wall = dynamic_cast<Wall *>(colliding_items[i]);
            if(wall && !push){
                setPos(x(),y()+10);
                push = true;
            }
        }
        push = false;
        colliding_items.clear();
    }

    else if (event->key() == Qt::Key_Down){

        if (pos().y() + 40 < scene()->height()){
        setPos(x(),y()+10);
        horientation = 3;  //horientation = 3 => Player horienter vers bas
        setPixmap(QPixmap(":/images/lgd_w39_h40.png"));
        }

        //faire en sorte que le personnage n'avance pas si il est a coté d'un mur
        QList<QGraphicsItem *> colliding_items = collidingItems();
        qDebug() << colliding_items.size();
        for (size_t i = 0, n  = colliding_items.size(); i< n ; ++i){
            Wall * wall = dynamic_cast<Wall *>(colliding_items[i]);
            if(wall && !push){
                setPos(x(),y()-10);
                push = true;
            }
        }
        push = false;
        colliding_items.clear();
    }

    else if (event->key() == Qt::Key_Space){
        if (pos().y() + 40 < scene()->height())
        setPos(x(),y()+10);
        horientation = 3;  //horientation = 3 => Player horienter vers bas
        setPixmap(QPixmap(":/images/lgsd_w40_h61.png"));
    }
}
