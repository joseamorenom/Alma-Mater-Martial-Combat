#ifndef ENEMIGO_H
#define ENEMIGO_H
#include <QObject>
#include <QGraphicsPixmapItem>

class enemigo: public QObject, public QGraphicsPixmapItem
{
public:
    enemigo();
    void set_sprites1();
    void set_sprites2();

private:
    QPixmap enemigo1,enemigo2;
};

#endif // ENEMIGO_H
