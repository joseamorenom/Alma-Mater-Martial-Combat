#include "personaje.h"

personaje::personaje()
{
  //  jugador1.load(":/Imagenes/Personaje 1/Parado/1.png");
}

void personaje::set_sprites()
{
    jugador1.load(":/Imagenes/Personaje 1/Parado/1.png");
    setPixmap(jugador1.scaled(130,300));

}
