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


    void on_btn_reanudar_clicked();

    void on_btn_guardar_clicked();

    void on_btn_volver_menu_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *menu,*nivel1,*nivel2,*multijugador;
    QPixmap Fondo_menu;
    QLCDNumber *lcdNumber;
    QWidget *centralwidget;
    QTimer *timer;
    QMessageBox *mensaje;
    personaje *jugador;
    enemigo *enemigo1,*enemigo2;
    mapas *mapa1,*mapa1e,*mapa2,*mapa2e;
    int cont=90;
    QLabel *nombre_ene1;
    int x1=0,y1=500,x3=1400,y3=480;

};
#endif // MAINWINDOW_H
