#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QMessageBox>
#include <QTimer>
#include <QPixmap>
#include <qevent.h>
#include <QtWidgets/QLCDNumber>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>
#include "personaje.h"
#include "enemigo.h"
#include "mapas.h"
#include "partida.h"
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent *event);
    ~MainWindow();
    void set_ventana();


private slots:

    void on_btn_1_jug_clicked();

    void on_btn_salir_clicked();

    void on_btn_volver_clicked();

    void on_btn_multi_clicked();

    void on_btn_nueva_par_clicked();

    void on_btn_iniciar_clicked();

    void nivel1_tiempo();

    void resorte();

    void resorte_derecha();

    void resorte_j2_izq();

    void resorte_j2_der();

    void caida_libre_1j();

    void caida_libre_multi();

    void on_btn_guardar_clicked();

    void on_btn_volver_menu_clicked();



    void on_btn_reanudar_clicked();

    void on_btn_aceptar_clicked();

    void on_btn_cancelar_clicked();

    void nivel2_tiempo();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *menu,*nivel1,*nivel2,*multijugador,*ganador;
    QPixmap Fondo_menu;
    QLCDNumber *lcdNumber;
    QWidget *centralwidget;
    QTimer *timer,*timer2,*timer3,*timer4,*timer5,*timer6,*timer7,*n2timer;
    QMessageBox *mensaje;
    personaje *jugador;
    enemigo *enemigo1,*enemigo2;
    mapas *mapa1,*mapa1e,*mapa2,*mapa2e;
    QThread *hilo;
    int cont=90;
    QLabel *nombre_ene1,rect;
    QString nombre_usuario;
    QLine *usuario;
    int x1=0,y1=500,x3=1400,y3=475,pos0xper=0,pos0yper=500,T=20,h,contador,pasar_nivel,contn2=60,timerid,ganadormulti,contadorn2,contmulti,contj1j2,vida_j2;
    bool colision_je,colision_je1,colision_je2,colision_j1j2;
    float y2;
    float i=0,resorte2,g=-9.81;
    partida *dat_partida;
    partida *vidas_ene1,*vidas_ene2,*vidas_j1,*vidas_j2;

};
#endif // MAINWINDOW_H
