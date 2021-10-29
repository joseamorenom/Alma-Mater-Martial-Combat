#include "bola.h"

bola::bola()
{
    QPixmap j(":/new/prefix1/Bola 2 (1).png");
    setPixmap(j.scaled(10,10));
}

int bola::get_h()
{
    return h;
}

void bola::sprites(int cont_bola)
{
    if(cont_bola>0&&cont_bola<20){
        qDebug()<<"pixmap";
        setPixmap(QPixmap(secuen[0]).scaled(130,400));
}
 // setPixmap(QPixmap(patada_e1[movimien[3]]).scaled(130,300));

    else if(cont_bola>21&&cont_bola<35){
        setPixmap(QPixmap(secuen[1]).scaled(130,500));
    }
    else if(cont_bola>36&&cont_bola<48){
        setPixmap(QPixmap(secuen[2]).scaled(130,350));
    }
    else if(cont_bola>49&&cont_bola<150){
        setPixmap(QPixmap(secuen[3]).scaled(80,80));
    }
    else if(cont_bola>151&&cont_bola<500){
        setPixmap(QPixmap(secuen[4]).scaled(80,80));
    }
    else if(cont_bola>500&&cont_bola<750){
        setPixmap(QPixmap(secuen[5]).scaled(80,80));
    }

}

