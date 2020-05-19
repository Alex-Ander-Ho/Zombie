#ifndef PAUSETXT_H
#define PAUSETXT_H

#include <QGraphicsTextItem>

class PauseTxt: public QGraphicsTextItem{
public:
    void onText();
    void offText();
};

#endif // PAUSETXT_H
