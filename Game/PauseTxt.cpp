#include "PauseTxt.h"
#include <QFont>

void PauseTxt::onText(){
    // draw the text
    setPlainText("PAUSE");
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 24)); //, 540));
}

void PauseTxt::offText(){
    setPlainText(0);
}
