#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QString>
class personaje: public QObject, public QGraphicsPixmapItem
{
public:
    personaje();
    void set_sprites();
    void sprites(short a);
private:
    QPixmap jugador1;
    QString movimiento[5]={":/Imagenes/Personaje 1/Caminando/1.png",":/Imagenes/Personaje 1/Caminando/2.png",":/Imagenes/Personaje 1/Caminando/3.png",":/Imagenes/Personaje 1/Caminando/4.png",":/Imagenes/Personaje 1/Caminando/5.png"};
    QString muerte[4]={":/Imagenes/Personaje 1/Muerte/1.png",":/Imagenes/Personaje 1/Muerte/2.png",":/Imagenes/Personaje 1/Muerte/3.png",":/Imagenes/Personaje 1/Muerte/4.png"};
    QString parado[4]={":/Imagenes/Personaje 1/Parado/1.png",":/Imagenes/Personaje 1/Parado/2.png",":/Imagenes/Personaje 1/Parado/3.png",":/Imagenes/Personaje 1/Parado/4.png"};
    QString salto[2]={":/Imagenes/Personaje 1/Salto/1.png",":/Imagenes/Personaje 1/Salto/2.png"};
    QString golpe[3]={":/Imagenes/Personaje 1/Golpe/1.png",":/Imagenes/Personaje 1/Golpe/2.png",":/Imagenes/Personaje 1/Golpe/3.png"};
    QString patada[3]={":/Imagenes/Personaje 1/Patada/1.png",":/Imagenes/Personaje 1/Patada/2.png",":/Imagenes/Personaje 1/Patada/3.png"};
    short movimien[5];
    bool pos[5];
    int x1=500,y1=0;


};

#endif // PERSONAJE_H
