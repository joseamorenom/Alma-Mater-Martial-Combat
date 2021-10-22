#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "enemigo.h"
#include "intro.h"
#include "mapas.h"
#include "personaje.h"
#include <iostream>
#include <QtDebug>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)


{
    ui->setupUi(this);
    menu =new QGraphicsScene;
    nivel1 =new QGraphicsScene;
    nivel2= new QGraphicsScene;
    multijugador=new QGraphicsScene;
    setGeometry(0,0,1002,1002);
    ui->graphicsView->setGeometry(0,0,1900,1005);
    menu->setSceneRect(0,0,1898,1003);

    menu->setBackgroundBrush(QImage(":/Imagenes/Menu/Fondo_menu.png").scaled(1550,820));
    ui->graphicsView->setScene(menu);
    timer= new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(nivel1_tiempo()));


    set_ventana();




    ui->btn_1_jug->setGeometry(1550/2-110,820/2-120,200,80);
    ui->btn_multi->setGeometry(1550/2-110,820/2-35,200,80);
    ui->btn_salir->setGeometry(1550/2-115,820/2+50,210,85);
    ui->btn_nueva_par->hide();
    ui->btn_cargar_par->hide();
    ui->btn_volver->hide();
    ui->btn_iniciar->hide();
    ui->lcdNumber->hide();




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_ventana()
{
    setWindowTitle("Alma Mater Martial Combat");
    setWindowIcon(QIcon(":/Imagenes/Menu/Logo.png"));

}




void MainWindow::on_btn_1_jug_clicked()
{


    ui->btn_1_jug->hide();
    ui->btn_multi->hide();
    ui->btn_salir->hide();
    ui->lcdNumber->hide();
    ui->btn_iniciar->hide();
    ui->btn_nueva_par->show();
    ui->btn_cargar_par->show();
    ui->btn_volver->show();
    ui->btn_nueva_par->setGeometry(1550/2-110,820/2-120,200,80);
    ui->btn_cargar_par->setGeometry(1550/2-110,820/2-35,200,80);
    ui->btn_volver->setGeometry(1550/2-110,820/2+50,210,90);


}

void MainWindow::on_btn_salir_clicked()
{
    setWindowTitle("Alma Mater Martial Combat");
    setWindowIcon(QIcon(":/Imagenes/Menu/Logo.png"));
    mensaje= new QMessageBox;
    QMessageBox::StandardButton respuesta;
    respuesta = QMessageBox::question(this, "Alma Mater Martial Combat", "¿Seguro que deseas Salir?",QMessageBox::Yes|QMessageBox::No);
      if (respuesta == QMessageBox::Yes) {
        QApplication::quit();
      }
      else {
        delete mensaje ;
      }

    /*
    int opcion = mensaje->exec() ;


       switch( opcion ){

           case QMessageBox::Yes:

               QApplication::quit() ;      //Comando para cerrar el juego

           break;

           case QMessageBox::No:

               delete mensaje ;

           break;

       }
       */

}



void MainWindow::on_btn_volver_clicked()
{
    ui->btn_1_jug->show();
    ui->btn_multi->show();
    ui->btn_salir->show();
    ui->btn_iniciar->hide();
    ui->btn_1_jug->setGeometry(1550/2-110,820/2-120,200,80);
    ui->btn_multi->setGeometry(1550/2-110,820/2-35,200,80);
    ui->btn_salir->setGeometry(1550/2-115,820/2+50,210,85);
    ui->btn_nueva_par->hide();
    ui->btn_cargar_par->hide();
    ui->btn_volver->hide();
    ui->lcdNumber->hide();
}

void MainWindow::on_btn_multi_clicked()
{
    ui->btn_iniciar->show();
    ui->btn_volver->show();
    ui->btn_iniciar->setGeometry(1550/2-110,820/2-100,200,80);
    ui->btn_volver->setGeometry(1550/2-110,820/2+20,210,90);
    ui->btn_nueva_par->hide();
    ui->btn_cargar_par->hide();
    ui->btn_1_jug->hide();
    ui->btn_multi->hide();
    ui->btn_salir->hide();
    ui->lcdNumber->hide();
}


void MainWindow::on_btn_nueva_par_clicked()
{
    timer->start(200);
    ui->btn_nueva_par->hide();
    ui->btn_cargar_par->hide();
    ui->btn_1_jug->hide();
    ui->btn_multi->hide();
    ui->btn_salir->hide();
    ui->btn_volver->hide();
    ui->lcdNumber->show();

    ui->graphicsView->setGeometry(0,0,1900,1005);
    nivel1->setSceneRect(0,0,1898,1003);
    nivel1->setBackgroundBrush(QImage(":/Imagenes/Fondos/Tokyo2.jpg").scaled(1550,820));
    ui->graphicsView->setScene(nivel1);


  //  nivel1->addItem(lcdNumber);
     ui->lcdNumber->setGeometry(700,10,100,35);



    jugador= new personaje;
    jugador->set_sprites();
    jugador->setPos(0,500);
    nivel1->addItem(jugador);

    enemigo1 =new enemigo;
    enemigo1->set_sprites1();
    enemigo1->setPos(1400,470);
    nivel1->addItem(enemigo1);

    mapa1=new mapas;
    mapa1->mapa1_vidaper();
    mapa1->setPos(0,0);
    nivel1->addItem(mapa1);

    mapa1e=new mapas;
    mapa1e->mapa1_vidaene();
    //mapa1e->setPos(1150,-9);
    mapa1e->setPos(1165,0);
    nivel1->addItem(mapa1e);





 //  nivel1->addItem(personaje);






    /*
     temporizador = new QLCDNumber(centralwidget);
     temporizador->setObjectName(QString::fromUtf8("temporizador"));
     temporizador->setGeometry(QRect(420, 20, 64, 23));
     */




}

void MainWindow::on_btn_iniciar_clicked()
{
    ui->btn_nueva_par->hide();
    ui->btn_cargar_par->hide();
    ui->btn_1_jug->hide();
    ui->btn_multi->hide();
    ui->btn_salir->hide();
    ui->btn_volver->hide();
    ui->btn_iniciar->hide();
     ui->lcdNumber->show();
    ui->graphicsView->setGeometry(0,0,1900,1005);
    multijugador->setSceneRect(0,0,1911,1003);
    multijugador->setBackgroundBrush(QImage(":/Imagenes/Fondos/China.jpg").scaled(1550,820));
    ui->graphicsView->setScene(multijugador);

    jugador= new personaje;
    jugador->set_sprites();
    jugador->setPos(0,500);
    multijugador->addItem(jugador);
    enemigo2 =new enemigo;
    enemigo2->set_sprites2();
    enemigo2->setPos(1400,480);
    multijugador->addItem(enemigo2);

    mapa2=new mapas;
    mapa2->mapa1_vidaper();
    mapa2->setPos(0,0);
    multijugador->addItem(mapa2);

    mapa2e=new mapas;
    mapa2e->mapa1_vidaene();
    //mapa1e->setPos(1150,-9);
    mapa2e->setPos(1165,0);
    multijugador->addItem(mapa2e);


}

void MainWindow::nivel1_tiempo()
{
    ui->lcdNumber->display(cont);
    cont-=1;
    cout<<cont;
    if(cont<=0){
          menu->setBackgroundBrush(QImage(":/Imagenes/Menu/Fondo_menu.png").scaled(1550,820));
           ui->graphicsView->setScene(menu);
           ui->btn_1_jug->setGeometry(1550/2-110,820/2-120,200,80);
           ui->btn_multi->setGeometry(1550/2-110,820/2-35,200,80);
           ui->btn_salir->setGeometry(1550/2-115,820/2+50,210,85);
           ui->btn_nueva_par->hide();
           ui->btn_cargar_par->hide();
           ui->btn_volver->hide();
           ui->btn_iniciar->hide();
           timer->stop();
           ui->lcdNumber->hide();
    }

}

