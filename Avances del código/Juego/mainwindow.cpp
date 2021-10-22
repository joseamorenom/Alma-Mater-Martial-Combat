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
    ui->n_enemigo1->hide();
    ui->btn_reanudar->hide();
    ui->btn_guardar->hide();
    ui->btn_volver_menu->hide();
    ui->pausa->hide();




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
    ui->n_enemigo1->hide();
    ui->btn_iniciar->hide();
    ui->btn_reanudar->hide();
    ui->btn_guardar->hide();
    ui->btn_volver_menu->hide();
    ui->pausa->hide();
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
    ui->n_enemigo1->hide();
    ui->btn_reanudar->hide();
    ui->btn_guardar->hide();
    ui->btn_volver_menu->hide();
    ui->pausa->hide();

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
    ui->n_enemigo1->hide();
    ui->lcdNumber->hide();
    ui->btn_reanudar->hide();
    ui->btn_guardar->hide();
    ui->btn_volver_menu->hide();
    ui->pausa->hide();

}


void MainWindow::on_btn_nueva_par_clicked()
{
    cont=90;
    timer->start(1000);
    ui->btn_nueva_par->hide();
    ui->btn_cargar_par->hide();
    ui->btn_1_jug->hide();
    ui->btn_multi->hide();
    ui->btn_salir->hide();
    ui->btn_volver->hide();
    ui->btn_reanudar->hide();
    ui->btn_guardar->hide();
    ui->btn_volver_menu->hide();
    ui->pausa->hide();
    ui->lcdNumber->show();
    ui->graphicsView->setGeometry(0,0,1900,1005);
    nivel1->setSceneRect(0,0,1898,1003);
    nivel1->setBackgroundBrush(QImage(":/Imagenes/Fondos/Tokyo2.jpg").scaled(1550,820));
    ui->graphicsView->setScene(nivel1);
    ui->n_enemigo1_2->show();
    ui->n_enemigo1_2->setFont(QFont("Lucida Calligraphy",22,QFont::Bold));
    ui->n_enemigo1_2->setText("Jonathan");
    ui->n_enemigo1_2->setGeometry(1340,-20,500,100);
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
    mapa1e->setPos(1090,0);
    nivel1->addItem(mapa1e);
}

void MainWindow::on_btn_iniciar_clicked()
{
    timer->start(1000);
    ui->btn_nueva_par->hide();
    ui->btn_cargar_par->hide();
    ui->btn_1_jug->hide();
    ui->btn_multi->hide();
    ui->btn_salir->hide();
    ui->btn_volver->hide();
    ui->btn_iniciar->hide();
    ui->btn_reanudar->hide();
    ui->btn_guardar->hide();
    ui->btn_volver_menu->hide();
    ui->n_enemigo1_2->hide();
    ui->lcdNumber->show();
    ui->lcdNumber->setGeometry(750,10,100,35);
    ui->graphicsView->setGeometry(0,0,1900,1005);
    multijugador->setSceneRect(0,0,1911,1003);
    multijugador->setBackgroundBrush(QImage(":/Imagenes/Fondos/China.jpg").scaled(1550,820));
    ui->graphicsView->setScene(multijugador);
    ui->n_enemigo1->show();
    ui->n_enemigo1->setFont(QFont("Lucida Calligraphy",22,QFont::Bold));
    ui->n_enemigo1->setText("Augusto");
    ui->n_enemigo1->setGeometry(1340,-20,500,100);
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
    mapa2e->setPos(1090,0);
    multijugador->addItem(mapa2e);
}

void MainWindow::nivel1_tiempo()
{
    ui->lcdNumber->display(cont);
    cont-=1;
    if(cont<=0){
          mensaje=new QMessageBox;
          QMessageBox::information(this,"Alma Mater Martial Combat","Se acabó el tiempo, perdiste. \nVolverás al menu.");
          ui->lcdNumber->hide();
          menu->setBackgroundBrush(QImage(":/Imagenes/Menu/Fondo_menu.png").scaled(1550,820));
          ui->btn_1_jug->show();
          ui->btn_multi->show();
          ui->btn_salir->show();
          ui->btn_1_jug->setGeometry(1550/2-110,820/2-120,200,80);
          ui->btn_multi->setGeometry(1550/2-110,820/2-35,200,80);
          ui->btn_salir->setGeometry(1550/2-115,820/2+50,210,85);
          ui->btn_nueva_par->hide();
          ui->btn_cargar_par->hide();
          ui->btn_volver->hide();
          ui->btn_iniciar->hide();
          ui->lcdNumber->hide();
          ui->btn_reanudar->hide();
          ui->btn_guardar->hide();
          ui->btn_volver_menu->hide();
          ui->pausa->hide();
          ui->n_enemigo1->hide();
          ui->graphicsView->setScene(menu);
          nivel1->removeItem(jugador);
          timer->stop();
          cont=90;
     }
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

    QPen pen(Qt::red,6,Qt::SolidLine);
    QBrush color(QColor(255,77,77));
    switch (event->key()){
        case Qt::Key_Escape:
        ui->pausa->show();
        timer->stop();
        ui->pausa->setFont(QFont("Lucida Handwriting",26,QFont::Bold));
        ui->pausa->setText("Menu de pausa");
        ui->pausa->setGeometry(635,92,500,100);
        nivel1->addRect(480,100,600,620,pen,color);
        multijugador->addRect(480,100,600,620,pen,color);
        ui->btn_reanudar->show();
        ui->btn_guardar->show();
        ui->btn_volver_menu->show();
        ui->btn_salir->show();
        ui->btn_reanudar->setGeometry(620,170,350,130);
        ui->btn_guardar->setGeometry(620,305,350,130);
        ui->btn_volver_menu->setGeometry(610,440,373,130);
        ui->btn_salir->setGeometry(620,575,354,130);
        ui->graphicsView->setGeometry(0,0,1900,1005);
    case Qt::Key_D:
        jugador->sprites('d');
        jugador->setPos(x1=x1+20,y1);
        break;
    case Qt::Key_A:
        jugador->sprites('a');
        jugador->setPos(x1=x1-20,y1);
        break;
    case Qt::Key_W:
        jugador->sprites('w');
        jugador->setPos(x1,y1=y1-10);
        break;

    case Qt::Key_F:
        jugador->sprites('f');
        break;

    case Qt::Key_Q:
        jugador->sprites('q');
        break;
   case Qt::Key_L:
        enemigo2->sprites_e2('l');
        enemigo2->setPos(x3=x3+10,y3);
        break;
   case Qt::Key_J:
        enemigo2->sprites_e2('j');
        enemigo2->setPos(x3=x3-10,y3);
        break;
   case Qt::Key_I:
        enemigo2->sprites_e2('i');
        enemigo2->setPos(x3,y3=y3-10);
        break;
   case Qt::Key_P:
        enemigo2->sprites_e2('p');
        break;
   case Qt::Key_M:
        enemigo2->sprites_e2('m');
        break;


}
}

void MainWindow::on_btn_reanudar_clicked()
{
    timer->start();
    QPainter *rectan;
    rectan=new QPainter;
    rectan->eraseRect(480,100,600,620);
    ui->btn_reanudar->hide();
    ui->btn_guardar->hide();
    ui->btn_volver_menu->hide();
    ui->btn_salir->hide();
    ui->pausa->hide();
}

void MainWindow::on_btn_guardar_clicked()
{

}

void MainWindow::on_btn_volver_menu_clicked()
{
     menu->setBackgroundBrush(QImage(":/Imagenes/Menu/Fondo_menu.png").scaled(1550,820));
     ui->btn_1_jug->show();
     ui->btn_multi->show();
     ui->btn_salir->show();
     ui->btn_1_jug->setGeometry(1550/2-110,820/2-120,200,80);
     ui->btn_multi->setGeometry(1550/2-110,820/2-35,200,80);
     ui->btn_salir->setGeometry(1550/2-115,820/2+50,210,85);
     ui->btn_nueva_par->hide();
     ui->btn_cargar_par->hide();
     ui->btn_volver->hide();
     ui->btn_iniciar->hide();
     ui->lcdNumber->hide();
     ui->n_enemigo1->hide();
     ui->btn_reanudar->hide();
     ui->btn_guardar->hide();
     ui->btn_volver_menu->hide();
     ui->pausa->hide();
     jugador->set_sprites();
     jugador->setPos(0,500);
     nivel1->removeItem(jugador);
     ui->graphicsView->setScene(menu);



}
