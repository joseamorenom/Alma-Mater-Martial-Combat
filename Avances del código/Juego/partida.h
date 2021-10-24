#ifndef PARTIDA_H
#define PARTIDA_H
#include <iterator>
#include <QString>
#include <map>
#include <QList>

class partida
{
public:
   partida();
   void guardarPartidaFinal();
   void guardarPartida(QString nombre, int nivel, int vidas, int tiempo, int posicion);
   void leerArchivo();
   bool nuevaPartida(QString nombre, int nivel, int vidas, int tiempo, int posicion);

private:
   std::map<QString,QList<int>> infoMap;
   QString infoarchivo;
   QList <int> lista;
};


#endif // PARTIDA_H
