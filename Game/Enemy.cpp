#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"

extern Game * game;
extern bool pause;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //set random x position
    int random_number = rand() % 1800;
    setPos(random_number,0);

    // drew the rect
    setPixmap(QPixmap(":/Source/Zombie_mini.png"));

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Enemy::move(){
    // move enemy down

    if(!pause)
        setPos(x(),y()+5);

    // destroy enemy when it goes out of the screen
    if (pos().y() > 1075){
        //decrease the health
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}
