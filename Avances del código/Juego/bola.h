#ifndef BOLA_H
#define BOLA_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include<QString>

class bola:  public QObject, public QGraphicsPixmapItem
{
public:
    bola();
    int get_h();
    void sprites(int cont_bola);

private:
    int h,w;
    QString secuen[6]={":/Imagenes/Personaje 1/Poder/Jugador 1.png",":/Imagenes/Personaje 1/Poder/Jugador 2.png",":/Imagenes/Personaje 1/Poder/Jugador 3.png" , ":/Imagenes/Personaje 1/Poder/Bola 1.png",":/Imagenes/Personaje 1/Poder/Bola 2.png",":/Imagenes/Personaje 1/Poder/Bola 3.png"};
};

#endif // BOLA_H
