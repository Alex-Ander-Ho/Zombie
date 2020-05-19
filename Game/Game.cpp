#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QPushButton>
#include <QFont>
#include <QMediaPlayer>
#include "Enemy.h"

extern bool pause;

Game::Game(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1920,1080); // make the scene 800x600 instead of infinity by infinity (default)

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1920,1080);

    phone = new Scene();
    phone->setPixmap(QPixmap(":/Source/grass.png"));
    scene->addItem(phone);

    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/Sounds/bgsound.mp3"));
    music->setVolume(3);
    music->play();

    // create the player
    player = new Player();
    player->setPixmap(QPixmap(":/Source/Pers_mini.png")); // change the rect from 0x0 (default) to 100x100 pixels
    player->setPos(400,880); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    // create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+40);
    scene->addItem(health);

    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    //QPushButton * btn = new QPushButton("X", this);
    //btn->setGeometry(1890,0,30,30);
    //QObject::connect(btn, SIGNAL(cliked()), SLOT(cliked()));

    showFullScreen();
}
