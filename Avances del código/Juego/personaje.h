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
private:
    QPixmap jugador1;
    //QString

};

#endif // PERSONAJE_H
