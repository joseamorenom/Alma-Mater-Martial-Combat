#include "partida.h"
#include <QString>
#include <QVariant>
#include <string>
#include <QString>
#include <iterator>
#include <list>

using namespace std;

partida::partida()
{
}

void partida::guardarPartidaFinal()
{
    //Paso uno para "Va sacando la infomacion del mapa y la deja en un archivo de texto"
    QString name;
    string informacion;
    //Abre el archivo y le borra todo lo que había en el
    ofstream out("historial.txt", std::ofstream::out | std::ofstream::trunc);
    QList<int> provisional;
    //recorrro el mapa y voy guardando la info de cada usuario
    map<QString,QList<int>>::iterator it = infoMap.begin();
    while (it != infoMap.end()){
        name = it->first;
        provisional = it->second;
        informacion = guardarPartida(name, provisional[0], provisional[1], provisional[2], provisional[3],informacion);
        it++;
    }
    out<<informacion;
    out.close();
}

std::string partida::guardarPartida(QString nombre, int nivel, int vidas, int tiempo, int posicion, string informacion)
{
    //Pase dos para "Va sacando la infoamcion del mapa y la deja en un archivo de texto"

    //string auxiliar;
    informacion += nombre.toStdString();
    informacion += ' ';
    informacion += to_string(nivel);
    informacion += ' ';
    informacion += to_string(vidas);
    informacion += ' ';
    informacion += to_string(tiempo);
    informacion += ' ';
    informacion += to_string(posicion);
    informacion += "*";
    informacion += "\n";
    return informacion;
}

void partida::leerArchivo()
{
    //Lee el archivo y agrega al mapa las parejas que no existan aun en él
    // (todas cuando al inicio no hay nada)
    int cont;//,tamanio;
    bool vacio = revisarVacio();
    QString nameq;
    string renglon,nombre,word;
    QList<int> listarchivo;
    listarchivo.clear();
    ifstream ingreso;
    ingreso.open("historial.txt");
    if (!vacio) {

        while(getline(ingreso,renglon)){
            cont = 0;
                for (auto x : renglon) {
                        if (x == ' ')
                        {
                            if (cont==0) {
                                nombre = word;
                                nameq = QString::fromStdString(nombre);
                                cont++;
                                word.clear();

                            }
                            else
                            {
                            listarchivo.append(stoi(word));
                            cont++;
                            word.clear();
                            }
                        }
                            if (x == '*'){
                                listarchivo.append(stoi(word));
                                word.clear();
                                if(infoMap.find(nameq)==infoMap.end()){
                                infoMap.insert(std::pair<QString,QList<int>>(QString::fromStdString(nombre),listarchivo));
                                renglon.clear();}
                        }
                        else word = word + x;

        }

    }
        ingreso.close();
    }
}


bool partida::nuevaPartida(QString nombre, int nivel, int vidas, int tiempo, int posicion)
{
    //Agrega una nueva pareja al mapa y
    //Revisar que no exista ya esa partida
    //Si ya existe la actualiza
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
    else {
           return result;
    }
    return result;
}

void partida::actualizarPart(QString nombre, int nivel, int vidas, int tiempo, int posicion)
{
    //Se llama cuando un jugador que ya existe vuelve a jugar y a guardar su informacion
    std::map<QString,QList<int>>::iterator itr;
    itr = infoMap.find(nombre);
    if(itr !=infoMap.end()){
        lista.clear();
        lista.append(nivel);
        lista.push_back(vidas);
        lista.push_back(tiempo);
        lista.push_back(posicion);
        itr->second = lista;
    }
}

bool partida::revisarVacio()
{
    //Retorna true si esta vacio y false si no
    ifstream ingreso;
    ingreso.open("historial.txt");
    ingreso.seekg(0, ios::end);
    if (ingreso.tellg() == 0) {
        return true;
    }
    else return false;
}
