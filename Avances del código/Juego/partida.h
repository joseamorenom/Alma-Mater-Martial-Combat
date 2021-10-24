#ifndef PARTIDA_H
#define PARTIDA_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <iterator>
#include <QString>
#include <map>

class partida: public QObject, public QGraphicsPixmapItem
{
public:
   partida();
   void guardarPartidaFinal();
   void guardarPartida(QString nombre, int nivel, int vidas, int tiempo, int posicion);
   void leerArchivo();
   bool nuevaPartida(QString nombre, int nivel, int vidas, int tiempo, int posicion);

private:
   std::map<QString,int(*)[4]> infoMap;
   QString infoarchivo;
};
#endif // PARTIDA_H

