#include "Health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    health = 3;

    // draw the text
    setPlainText("Health: " + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",24));
}

void Health::decrease(){
    health--;
    setPlainText("Health: " + QString::number(health)); // Health: 2
}

int Health::getHealth(){
    return health;
}
