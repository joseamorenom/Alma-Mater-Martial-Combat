#include "partida.h"
#include <QString>
#include <QVariant>
#include <string>
#include <QString>
#include <fstream>
#include <iterator>
#include <list>

using namespace std;

partida::partida()
{

}

void partida::guardarPartidaFinal()
{
   //Paso uno para "Va sacando la infoamcion del mapa y la deja en un archivo de texto"
   QString name;
   QList<int> provisional;
   map<QString,QList<int>>::iterator it = infoMap.begin();
   while (it != infoMap.end()){
       name = it->first;
       provisional = it->second;
       guardarPartida(name, provisional[0], provisional[1], provisional[2], provisional[3]);
       it++;
   }
}

void partida::guardarPartida(QString nombre, int nivel, int vidas, int tiempo, int posicion)
{
   //Pase dos para "Va sacando la infoamcion del mapa y la deja en un archivo de texto"
   string informacion;
   string auxiliar;
   informacion += nombre.toStdString();
   informacion += ' ';
   informacion += nombre.toStdString();
   informacion += ' ';
   informacion += to_string(nivel);
   informacion += ' ';
   informacion += to_string(vidas);
   informacion += ' ';
   informacion += to_string(tiempo);
   informacion += ' ';
   informacion += to_string(posicion);
   informacion += "\n";
   //lo abre y borra todo lo que hay
   ofstream out("historial.txt", std::ofstream::out | std::ofstream::trunc);
   out<< informacion;
   out.close();
}

void partida::leerArchivo()
{
   //Lee el archivo y agrega al mapa las parejas que no existan aun en él
   int cont;
   QString nameq;
   QList<int> listarchivo;
   listarchivo.clear();
   ifstream ingreso;
   ingreso.open("historial.txt");
   string renglon,nombre,word;
   while(getline(ingreso,renglon)){
       cont = 0;
           for (auto x : renglon) {
                   if (x == ' ')
                   {
                       if (cont==0) {
                           nombre = word;
                           nameq = QString::fromStdString(nombre);
                       }
                       else listarchivo.append(stoi(word));
                       cont++;
                       word = "";
                   }
                   else word = word + x;
               }

           if(infoMap.find(nameq)==infoMap.end()){
           infoMap.insert(std::pair<QString,QList<int>>(QString::fromStdString(nombre),listarchivo));
           }
   }
}

bool partida::nuevaPartida(QString nombre, int nivel, int vidas, int tiempo, int posicion)
{
   //Agrega una nueva pareja al mapa y
   //Revisar que no exista ya esa partida
   bool result = false;
   if(infoMap.find(nombre)==infoMap.end()){
       lista.clear();
       lista.append(nivel);
       lista.push_back(vidas);
       lista.push_back(tiempo);
       lista.push_back(posicion);
   infoMap.insert(std::pair<QString,QList<int>>(nombre,lista));
   result = true;
   }
   else result=false;
   return result;
}





