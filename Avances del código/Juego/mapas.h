#ifndef MAPAS_H
#define MAPAS_H
#include <QObject>
#include <QGraphicsPixmapItem>


class mapas:public QObject, public QGraphicsPixmapItem
{
public:
    mapas();
    void mapa1_vidaper();
    void mapa1_vidaene();


private:
    QPixmap mapa1,mapa2;

};

#endif // MAPAS_H
