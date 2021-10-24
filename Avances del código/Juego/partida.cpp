#include "partida.h"
#include <QString>
#include <QVariant>
#include <string>
#include <QString>
#include <fstream>
#include <iterator>

using namespace std;

partida::partida()
{

}

void partida::guardarPartidaFinal()
{
   QString name;
   int *arreglo[4];
   map<QString,int(*)[4]>::iterator it = infoMap.begin();
   while (it != infoMap.end()){
       name = it->first;
    //   arreglo = it->second;
     //  guardarPartida(name, arreglo, arreglo+1, arreglo+2, arreglo+3);
       it++;
   }
}

void partida::guardarPartida(QString nombre, int nivel, int vidas, int tiempo, int posicion)
{
   string informacion;
   string auxiliar;
   informacion += nombre.toStdString();
   informacion += "    ";
   informacion += nombre.toStdString();
   informacion += "    ";
   informacion += to_string(nivel);
   informacion += "    ";
   informacion += to_string(vidas);
   informacion += "    ";
   informacion += to_string(tiempo);
   informacion += "    ";
   informacion += to_string(posicion);
   informacion += "\n";

   ofstream out("historial.txt");
   out<< informacion;
   out.close();
}

void partida::leerArchivo()
{
   int arreglo[4],cont;
   ifstream ingreso;
   ingreso.open("historial.txt");
   string renglon,nombre,word;
   while(getline(ingreso,renglon)){
       cont = 0;
           for (auto x : renglon) {
                   if (x == ' ')
                   {
                       if (cont==0) nombre = word;
                       else arreglo[cont-1] = stoi(word);
                       cont++;
                       word = "";
                   }
                   else word = word + x;
               }

           infoMap.insert(std::pair<QString,int(*)[4]>(QString::fromStdString(nombre),&arreglo));

   }
}

bool partida::nuevaPartida(QString nombre, int nivel, int vidas, int tiempo, int posicion)
{
   //Revisar que no exista ya esa partida
   bool result;
   if(infoMap.find(nombre)==infoMap.end()){
   int arreglo[4] = {nivel,vidas,tiempo,posicion};
   infoMap.insert(std::pair<QString,int(*)[4]>(nombre,&arreglo));
   result = true;
   }
   else result=false;
   return result;

}


