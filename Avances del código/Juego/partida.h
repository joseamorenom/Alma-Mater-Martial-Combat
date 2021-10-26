#ifndef PARTIDA_H
#define PARTIDA_H
#include <iterator>
#include <QString>
#include <map>
#include <QList>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QString>

class partida:public QObject, public QGraphicsPixmapItem
{
public:
   partida();
   void guardarPartidaFinal();
   void guardarPartida(QString nombre, int nivel, int vidas, int tiempo, int posicion);
   void leerArchivo();
   bool nuevaPartida(QString nombre, int nivel, int vidas, int tiempo, int posicion);
   void vida_ene1(bool colision_je);
   void imprimir_vidas_ene1(int contador);
   void inicializar_partida();

private:
   std::map<QString,QList<int>> infoMap;
   QString infoarchivo;
   QList <int> lista;
   int cont_vidas_ene1;
   QString barras_vida_der[11]={":/../Imagenes/Barras_vida_der/1.png",":/../Imagenes/Barras_vida_der/2.png",":/../Imagenes/Barras_vida_der/3.png",":/Imagenes/Barras_vida_der/4.png",":/Imagenes/Barras_vida_der/5.png",":/Imagenes/Barras_vida_der/6.png",":/Imagenes/Barras_vida_der/7.png",":/Imagenes/Barras_vida_der/8.png",":/Imagenes/Barras_vida_der/9.png",":/Imagenes/Barras_vida_der/10.png",":/Imagenes/Barras_vida_der/11.png"};
   QString barras_vida_izq[11]={":/Imagenes/Barras_vida_izq/1.png",":/Imagenes/Barras_vida_izq/2.png",":/Imagenes/Barras_vida_izq/3.png",":/Imagenes/Barras_vida_izq/4.png",":/Imagenes/Barras_vida_izq/5.png",":/Imagenes/Barras_vida_izq/6.png",":/Imagenes/Barras_vida_izq/7.png",":/Imagenes/Barras_vida_izq/8.png",":/Imagenes/Barras_vida_izq/9.png",":/Imagenes/Barras_vida_izq/10.png",":/Imagenes/Barras_vida_izq/11.png"};
};


#endif // PARTIDA_H
