#ifndef INTRO_H
#define INTRO_H
#include <QObject>
#include <QGraphicsPixmapItem>

class intro:public QObject, public QGraphicsPixmapItem
{
public:
    intro();
};

#endif // INTRO_H
