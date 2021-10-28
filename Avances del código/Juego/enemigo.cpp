#include "enemigo.h"

enemigo::enemigo()
{
    for(short i = 0; i < 5; i++){
        movimien[i] = 0;
        pos[i] = true;
    }
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

void enemigo::sprites_e2(short a)
{
    switch (a) {


    case 'i':
        if(movimien[0] == 2){
            pos[0] = false;
        }
        else if (movimien[0] == 0){
            pos[0] = true;
        }

        movimien[0] += (2*pos[0])-1;
        setPixmap(QPixmap(salto_e2[movimien[0]]).scaled(160,327));
    break;



    case 'l':
        if(movimien[2] == 2){
            pos[2] = false;
        }
        else if (movimien[2] == 0){
            pos[2] = true;
        }

        movimien[2] += (2*pos[2])-1;
        setPixmap(QPixmap(movimiento_e2[movimien[2]]).scaled(160,327));

    break;

    case 'j':
        if(movimien[3] == 2){
            pos[3] = false;
        }
        else if (movimien[3] == 0){
            pos[3] = true;
        }

        movimien[3] += (2*pos[3])-1;
        setPixmap(QPixmap(movimiento_e2[movimien[3]]).scaled(160,327));
    break;

    case 'p':
        if(movimien[3] == 2){
            pos[3] = false;
        }
        else if (movimien[4] == 0){
            pos[3] = true;
        }

        movimien[3] += (2*pos[3])-1;
        setPixmap(QPixmap(patada_e2[movimien[3]]).scaled(160,327));
    break;

    case 'm':
        if(movimien[3] == 2){
            pos[3] = false;
        }
        else if (movimien[3] == 0){
            pos[3] = true;
        }

        movimien[3] += (2*pos[3])-1;
        setPixmap(QPixmap(golpe_e2[movimien[3]]).scaled(160,327));
    break;
    }
}

void enemigo::caida_libre_e2(float i)
{

        setPixmap(QPixmap(salto_e2[0]).scaled(160,327));
        if(i>150){
             setPixmap(QPixmap(salto_e2[1]).scaled(160,327));
             if(i>250){
                 setPixmap(QPixmap(salto_e2[2]).scaled(160,327));
                  if(i>350){
                     setPixmap(QPixmap(salto_e2[3]).scaled(160,327));
                     if(i>350){
                         setPixmap(QPixmap(salto_e2[3]).scaled(160,327));
                     }
                        if(i>450){
                            setPixmap(QPixmap(salto_e2[4]).scaled(160,327));
                     }
                        if(i>=490){
                                enemigo2.load(":/Imagenes/Enemigo 2/Parado/1.png");
                                setPixmap(enemigo2.scaled(160,327));
                        }
                 }
             }

        }


}

void enemigo::mov_izq_e1()
{
        if(movimien[3] == 2){
            pos[3] = false;
        }
        else if (movimien[3] == 0){
            pos[3] = true;
        }

        movimien[3] += (2*pos[3])-1;
        setPixmap(QPixmap(movimiento_e1[movimien[3]]).scaled(150,320));
}

void enemigo::golpe()
{

    int a=1+rand()%10;
    qDebug()<<"Numero aleatorio "<<a;
    /*if(a==7||a==9||a==3||a==1){
        a=4;
    }
    */
    int condic=a%2;
    if(condic==0){
               qDebug()<<"Numero par";

        if(movimien[3] == 2){
            pos[3] = false;
        }
        else if (movimien[3] == 0){
            pos[3] = true;
        }

        movimien[3] += (2*pos[3])-1;
        setPixmap(QPixmap(golpe_e1[movimien[3]]).scaled(160,327));

    }

    else{
        qDebug()<<"Numero impar";

        if(movimien[3] == 2){
            pos[3] = false;
        }
        else if (movimien[4] == 0){
            pos[3] = true;
        }

        movimien[3] += (2*pos[3])-1;
        setPixmap(QPixmap(patada_e1[movimien[3]]).scaled(130,300));

    }


}





