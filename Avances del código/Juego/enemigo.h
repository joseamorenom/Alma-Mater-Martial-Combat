#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QString>
#include <time.h>
#include <cstdlib>

class enemigo: public QObject, public QGraphicsPixmapItem
{
public:
    enemigo();
    void set_sprites1();
    void set_sprites2();
    void sprites_e1(short a);
    void sprites_e2(short a);
    void caida_libre_e2(float i);
    void mov_izq_e1();

    void golpe();
private:
    QPixmap enemigo1,enemigo2;
    QString movimiento_e2[5]={":/Imagenes/Enemigo 2/Caminando/1.png",":/Imagenes/Enemigo 2/Caminando/2.png",":/Imagenes/Enemigo 2/Caminando/3.png",":/Imagenes/Enemigo 2/Caminando/4.png",":/Imagenes/Enemigo 2/Caminando/5.png"};
    QString muerte_e2[4]={":/Imagenes/Enemigo 2/Muerte/1.png",":/Imagenes/Enemigo 2/Muerte/2.png",":/Imagenes/Enemigo 2/Muerte/3.png",":/Imagenes/Enemigo 2/Muerte/4.png"};
    QString salto_e2[5]={":/Imagenes/Enemigo 2/Saltar/1.png",":/Imagenes/Enemigo 2/Saltar/2.png",":/Imagenes/Enemigo 2/Saltar/3.png",":/Imagenes/Enemigo 2/Saltar/4.png",":/Imagenes/Enemigo 2/Saltar/5.png"};
    QString golpe_e2[3]={":/Imagenes/Enemigo 2/Golpe/1.png",":/Imagenes/Enemigo 2/Golpe/2.png",":/Imagenes/Enemigo 2/Golpe/3.png"};
    QString patada_e2[5]={":/Imagenes/Enemigo 2/Patada/1.png",":/Imagenes/Enemigo 2/Patada/2.png",":/Imagenes/Enemigo 2/Patada/3.png",":/Imagenes/Enemigo 2/Patada/4.png",":/Imagenes/Enemigo 2/Patada/5.png"};
    QString movimiento_e1[3]={":/Imagenes/Enemigo 1/Caminando/1.png",":/Imagenes/Enemigo 1/Caminando/2.png",":/Imagenes/Enemigo 1/Caminando/3.png"};
    QString muerte_e1[4]={":/Imagenes/Enemigo 1/Muerte/1.png",":/Imagenes/Enemigo 1/Muerte/2.png",":/Imagenes/Enemigo 1/Muerte/3.png",":/Imagenes/Enemigo 1/Muerte/4.png"};
    QString salto_e1[2]={":/Imagenes/Enemigo 1/Saltar/1.png",":/Imagenes/Enemigo 1/Saltar/2.png"};
    QString golpe_e1[3]={":/Imagenes/Enemigo 1/Golpe/1.png",":/Imagenes/Enemigo 1/Golpe/2.png",":/Imagenes/Enemigo 1/Golpe/3.png"};
    QString patada_e1[2]={":/Imagenes/Enemigo 1/Patada/1.png",":/Imagenes/Enemigo 1/Patada/2.png"};

    short movimien[5];
    bool pos[5];


};

#endif // ENEMIGO_H
