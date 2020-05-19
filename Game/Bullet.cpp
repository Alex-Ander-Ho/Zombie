#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QMediaPlayer>
#include "Player.h"
#include "Enemy.h"
#include "Game.h"

extern Game * game; // there is an external global object called game
extern bool pause;

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // drew the bullet (a rectangle)
    setPixmap(QPixmap(":/Source/Bullet_mini.png"));

    // make/connect a timer to move() the bullet every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);
}

void Bullet::move(){
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();
    //pl = new Player();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            // increase the score
            game->score->increase();

            QMediaPlayer * point = new QMediaPlayer();
            point->setMedia(QUrl("qrc:/Sounds/Collect_Coin.mp3"));
            point->setVolume(3);
            point->play();

            // remove them from the scene (still on the heap)
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // delete them from the heap to save memory
            delete colliding_items[i];
            delete this;

            // return (all code below refers to a non existint bullet)
            return;
        }
    }

    // if there was no collision with an Enemy, move the bullet forward
    if(!pause)
        setPos(x(),y()-10);
    // if the bullet is off the screen, destroy it
    if (pos().y() + pixmap().height() < 0){
    scene()->removeItem(this);
    delete this;
    }
}
