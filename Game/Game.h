#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Health.h"
#include "Scene.h"
#include "Score.h"
#include "Menu.h"

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;    
    Scene * phone;
    Health * health;
    Player * player;
    Menu * menu;
    Score * score;
};

#endif // GAME_H
