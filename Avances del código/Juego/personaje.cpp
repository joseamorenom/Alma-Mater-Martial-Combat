#include "personaje.h"

personaje::personaje()
{
    for(short i = 0; i < 5; i++){
        movimien[i] = 0;
        pos[i] = true;
    }
}

void personaje::set_sprites()
{
    jugador1.load(":/Imagenes/Personaje 1/Parado/1.png");
    setPixmap(jugador1.scaled(130,300));

}

void personaje::sprites(short a)
{

        switch (a) {
            case 'w':
                if(movimien[0] == 2){
                    pos[0] = false;
                }
                else if (movimien[0] == 0){
                    pos[0] = true;
                }

                movimien[0] += (2*pos[0])-1;
                setPixmap(QPixmap(salto[movimien[0]]).scaled(130,300));
            break;



            case 'd':
                if(movimien[2] == 2){
                    pos[2] = false;
                }
                else if (movimien[2] == 0){
                    pos[2] = true;
                }

                movimien[2] += (2*pos[2])-1;
                setPixmap(QPixmap(movimiento[movimien[2]]).scaled(130,300));

            break;

            case 'a':
                if(movimien[3] == 2){
                    pos[3] = false;
                }
                else if (movimien[3] == 0){
                    pos[3] = true;
                }

                movimien[3] += (2*pos[3])-1;
                setPixmap(QPixmap(movimiento[movimien[3]]).scaled(130,300));
            break;

        case 'f':
            if(movimien[3] == 2){
                pos[3] = false;
            }
            else if (movimien[4] == 0){
                pos[3] = true;
            }

            movimien[3] += (2*pos[3])-1;
            setPixmap(QPixmap(patada[movimien[3]]).scaled(130,300));
        break;

        case 'q':
            if(movimien[3] == 2){
                pos[3] = false;
            }
            else if (movimien[3] == 0){
                pos[3] = true;
            }

            movimien[3] += (2*pos[3])-1;
            setPixmap(QPixmap(golpe[movimien[3]]).scaled(130,300));
        break;
        }
}

void personaje::borde()
{

    float resorte=0,a=300,w=0.2,desfase=3.146;
    for(int i=0;i<10;i++){
        resorte=360+a*sin(w*i+desfase);
        setPos(resorte,500);
    }
}

void personaje::subida()
{
    jugador1.load(":/Imagenes/Personaje 1/Salto/1.png");
    setPixmap(jugador1.scaled(130,300));
}

void personaje::bajada()
{

    jugador1.load(":/Imagenes/Personaje 1/Salto/2.png");
    setPixmap(jugador1.scaled(130,300));
}




