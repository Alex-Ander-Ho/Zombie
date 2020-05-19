#include "Score.h"
#include <QFont>
Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
   //Инициализация score
    score=0;
    //Отрисовка текста
    setPlainText("Score: " +QString::number(score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",24));
}

void Score::increase(){
    score++;
    setPlainText("Score: " +QString::number(score));
}

int Score::getScore()
{
    return score;
}
