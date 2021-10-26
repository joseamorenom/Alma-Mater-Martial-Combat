#include "mapas.h"

mapas::mapas()
{

}

void mapas::mapa1_vidaene()
{
    mapa1.load(":/Imagenes/Barras_vida_der/1.png");
    setPixmap(mapa1.scaled(380,80));
}

void mapas::mapa2_vidaene()
{
    mapa2.load(":/Imagenes/Barras_vida_izq/1.png");
    setPixmap(mapa2.scaled(380,80));
}

void mapas::mapa1_vidaper()
{
    mapa1.load(":/Imagenes/Barras_vida_izq/1.png");
    setPixmap(mapa1.scaled(380,80));

}

