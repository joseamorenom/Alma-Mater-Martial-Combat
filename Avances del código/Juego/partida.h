#ifndef PARTIDA_H
#define PARTIDA_H
#include <QObject>
#include <QGraphicsPixmapItem>


class partida: public QObject, public QGraphicsPixmapItem
{
public:
    partida();
};

#endif // PARTIDA_H
