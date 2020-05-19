#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QFont>
#include "Bullet.h"
#include "PauseTxt.h"
#include "Enemy.h"
#include "Score.h"
#include "Game.h"
#include <QMediaPlayer>

Menu * menu;
bool pause = false;

void Player::keyPressEvent(QKeyEvent *event){

    if (!pause){
    // move the player left and right
        if (event->key() == Qt::Key_A){
            setPos(x()-10,y());
            if (!(pos().x() >= -110))
                setPos(2020,y());

        } else if (event->key() == Qt::Key_D){
            setPos(x()+10,y());
            if (!(pos().x() + 100 <= 2030))
                setPos(-100,y());

        } else if (event->key() == Qt::Key_Space){
            // create a bullet
            QMediaPlayer * fire = new QMediaPlayer();
            fire->setMedia(QUrl("qrc:/Sounds/Pew.mp3"));
            fire->setVolume(3);
            fire->play();
            Bullet * bullet = new Bullet();
            bullet->setPos(x()+67,y()-22);
            scene()->addItem(bullet);
        }
    }
    if (event->key() == Qt::Key_Escape){
        if (pause == false){
            menu = new Menu;
            menu->setPixmap(QPixmap(":/Source/Menu.png"));
            scene()->addItem(menu);

            PauseTxt().onText();
            pause = true;
        } else {
            scene()->removeItem(menu);

            PauseTxt().offText();
            pause = false;
        }
    }
}

void Player::spawn(){
    // create an enemy
    Enemy * enemy = new Enemy();
    if(!pause){

        scene()->addItem(enemy);

        QMediaPlayer * spawn = new QMediaPlayer();
        spawn->setMedia(QUrl("qrc:/Sounds/Zombie_spawn.mp3"));
        spawn->setVolume(3);
        spawn->play();
    }
}
