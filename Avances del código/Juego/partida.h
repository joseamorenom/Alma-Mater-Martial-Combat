#ifndef PARTIDA_H
#define PARTIDA_H
#include <iterator>
#include <QString>
#include <map>
#include <QList>
#include <fstream>
#include <string>

class partida
{
public:
    partida();
    void guardarPartidaFinal();
    std::string guardarPartida(QString nombre, int nivel, int vidas, int tiempo, int posicion, std::string informacion);
    void leerArchivo();
    bool nuevaPartida(QString nombre, int nivel, int vidas, int tiempo, int posicion);
    void actualizarPart(QString nombre, int nivel, int vidas, int tiempo, int posicion);
    bool revisarVacio();

private:
    std::map<QString,QList<int>> infoMap;
    QString infoarchivo;
    QList <int> lista;
};

#endif // PARTIDA_H
