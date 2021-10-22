#include "enemigo.h"

enemigo::enemigo()
{

}

void enemigo::set_sprites1()
{
    enemigo1.load(":/Imagenes/Enemigo 1/Parado/1.png");
    setPixmap(enemigo1.scaled(150,320));
}

void enemigo::set_sprites2()
{
    enemigo2.load(":/Imagenes/Enemigo 2/Parado/1.png");
    setPixmap(enemigo2.scaled(160,327));
}
