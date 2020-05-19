#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class Scene:public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
};

#endif // SCENE_H
