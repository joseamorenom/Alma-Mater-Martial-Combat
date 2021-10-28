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

   std::string guardarPartida(QString nombre, int nivel, int vidas, int tiempo, int posicion, std::string informacion);
    void leerArchivo();
    bool nuevaPartida(QString nombre, int nivel, int vidas, int tiempo, int posicion);
    void actualizarPart(QString nombre, int nivel, int vidas, int tiempo, int posicion);
    bool revisarVacio();

   int vida_ene1(bool colision_je);
   int vida_ene2(bool colision_je);
   int vidas_multi_j2(bool colision_j1j2);
   void inicializar_partida();
   void inicializar_nivel2();
   int vida_jugador_multi(bool colision_je2);
   void inicializar_multi();
   void inicializar_multi_j2();
   void inicializar_cpu1();
   int vida_jugador1(bool colision_e1j1);
   int nivel(QString nombre);
   int vidas(QString nombre);
   int tiempo(QString nombre);
   int posicion(QString nombre);


private:
   std::map<QString,QList<int>> infoMap;
   QString infoarchivo;
   QList <int> lista;
   int cont_vidas_ene1,cont_vidas_multi_j1,cont_vidas_multi_j2,cont_vidas_jugador1;
   QString barras_vida_der[11]={":/Imagenes/Barras_vida_der/1.png",":/Imagenes/Barras_vida_der/2.png",":/Imagenes/Barras_vida_der/3.png",":/Imagenes/Barras_vida_der/4.png",":/Imagenes/Barras_vida_der/5.png",":/Imagenes/Barras_vida_der/6.png",":/Imagenes/Barras_vida_der/7.png",":/Imagenes/Barras_vida_der/8.png",":/Imagenes/Barras_vida_der/9.png",":/Imagenes/Barras_vida_der/10.png",":/Imagenes/Barras_vida_der/11.png"};
   QString barras_vida_izq[11]={":/Imagenes/Barras_vida_izq/1.png",":/Imagenes/Barras_vida_izq/2.png",":/Imagenes/Barras_vida_izq/3.png",":/Imagenes/Barras_vida_izq/4.png",":/Imagenes/Barras_vida_izq/5.png",":/Imagenes/Barras_vida_izq/6.png",":/Imagenes/Barras_vida_izq/7.png",":/Imagenes/Barras_vida_izq/8.png",":/Imagenes/Barras_vida_izq/9.png",":/Imagenes/Barras_vida_izq/10.png",":/Imagenes/Barras_vida_izq/11.png"};
};


#endif // PARTIDA_H
