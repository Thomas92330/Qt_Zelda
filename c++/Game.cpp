#include "Game.h"
#include "Enemy.h"
#include <QGraphicsScene>
#include "Button.h"
#include "Wall.h"
#include <QGraphicsTextItem>



Game::Game(QWidget *parent){


        //create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,900,800);

        //define scene size and
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(900,800);
}

void Game::start(){
        //clear scene
    scene->clear();

        //create the player
    player = new Player();
    player->setPos(scene->width()/2,9 * scene->height()/10);
        //make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
        //add the player to the scene
    scene->addItem(player);


        //create the enemy1
    Enemy * enemy1 = new Enemy();
    enemy1->setPos(scene->width()/4, scene->height()/10);

        //add the enemy1 to the scene
    scene->addItem(enemy1);



        //create the enemy2
    Enemy * enemy2 = new Enemy();
    enemy2->setPos(scene->width()/2, scene->height()/10);

        //add the player to the scene
    scene->addItem(enemy2);


        //create the enemy3
    Enemy * enemy3 = new Enemy();
    enemy3->setPos(3 * scene->width()/4, scene->height()/10);

        //add the player to the scene
    scene->addItem(enemy3);

    Wall * wall = new Wall();
    wall->setPos(0,0);
    scene->addItem(wall);
}

void Game ::displayMainMenu(){
    //create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Zelda"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // create the play button
    Button* playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // create the quit button
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
}



