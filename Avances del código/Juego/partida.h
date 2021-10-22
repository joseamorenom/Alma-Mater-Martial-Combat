#ifndef PARTIDA_H
#define PARTIDA_H
#include <QObject>
#include <QGraphicsPixmapItem>


class partida: public QObject, public QGraphicsPixmapItem
{
public:
    partida();
    void tecla_pausa(short tecla);
};

#endif // PARTIDA_H
