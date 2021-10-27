#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "enemigo.h"
#include "intro.h"
#include "mapas.h"
#include "personaje.h"
#include <iostream>
#include <QtDebug>
#include <QThread>

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
    ganador=new QGraphicsScene;
    setGeometry(0,0,1002,1002);
    ui->graphicsView->setGeometry(0,0,1900,1005);
    menu->setSceneRect(0,0,1898,1003);
    menu->setBackgroundBrush(QImage(":/Imagenes/Menu/Fondo_menu.png").scaled(1550,820));
    ui->graphicsView->setScene(menu);
    timer= new QTimer(this);
    timer2=new QTimer(this);
    timer3=new QTimer(this);
    timer4=new QTimer(this);
    timer5=new QTimer(this);
    timer6=new QTimer(this);
    timer7=new QTimer(this);
    n2timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(nivel1_tiempo()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(resorte()));
    connect(timer3,SIGNAL(timeout()),this,SLOT(resorte_derecha()));
    connect(timer4,SIGNAL(timeout()),this,SLOT(resorte_j2_izq()));
    connect(timer5,SIGNAL(timeout()),this,SLOT(resorte_j2_der()));
    connect(timer6,SIGNAL(timeout()),this,SLOT(caida_libre_1j()));
    connect(timer7,SIGNAL(timeout()),this,SLOT(caida_libre_multi()));
    connect(n2timer,SIGNAL(timeout()),this,SLOT(nivel2_tiempo()));
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
    ui->rect->hide();
    dat_partida->leerArchivo();
    ui->btn_aceptar->hide();
    ui->btn_cancelar->hide();
    ui->ingrese_nom->hide();
    ui->ingresar_usuario->hide();

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
    ui->rect->hide();
    ui->btn_aceptar->hide();
    ui->btn_cancelar->hide();
    ui->ingrese_nom->hide();
    ui->ingresar_usuario->hide();
    ui->btn_nueva_par->show();
    ui->btn_cargar_par->show();
    ui->btn_volver->show();
    ui->btn_nueva_par->setGeometry(1550/2-110,820/2-120,200,80);
    ui->btn_cargar_par->setGeometry(1550/2-110,820/2-35,200,80);
    ui->btn_volver->setGeometry(1550/2-110,820/2+50,210,90);
}

void MainWindow::on_btn_salir_clicked()
{
   // dat_partida->guardarPartidaFinal();
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
    ui->n_enemigo1->clear();
    ui->n_jugador1->clear();
    ui->btn_reanudar->hide();
    ui->btn_guardar->hide();
    ui->btn_volver_menu->hide();
    ui->pausa->hide();
    ui->rect->hide();
    ui->btn_aceptar->hide();
    ui->btn_cancelar->hide();
    ui->ingrese_nom->hide();
    ui->ingresar_usuario->clear();
    ui->graphicsView->setScene(menu);
    menu->removeItem(jugador);
    menu->removeItem(enemigo1);
    menu->removeItem(enemigo2);


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
    ui->rect->hide();
    ui->btn_aceptar->hide();
    ui->btn_cancelar->hide();
    ui->ingrese_nom->hide();
    ui->ingresar_usuario->hide();
}


void MainWindow::on_btn_nueva_par_clicked()
{
    vidas_ene1=new partida;
    vidas_ene1->inicializar_partida();
    contador=1; //Se usa para poder tener las colisiones entre jugador y enemigo 1
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
    ui->rect->hide();
    ui->btn_nueva_par->hide();
    ui->btn_volver->hide();
    ui->ingresar_usuario->clear();
    ui->ingrese_nom->show();
    ui->ingresar_usuario->show();
     ui->ingresar_usuario->setDisabled(false);
    ui->ingresar_usuario->setGeometry(680,335,210,31);
    ui->ingrese_nom->setFont(QFont("Lucida Calligraphy",24,QFont::Bold));
    ui->ingrese_nom->setText("Ingrese su nombre");
    ui->ingrese_nom->setGeometry(620,110,400,400);
    ui->btn_aceptar->show();
    ui->btn_cancelar->show();
    ui->btn_aceptar->setGeometry(680,370,93,28);
    ui->btn_cancelar->setGeometry(800,370,93,28);
}

void MainWindow::on_btn_iniciar_clicked()
{
       cont=90;
       timerid=0;
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
       ui->rect->hide();
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
       enemigo1=new enemigo;
       enemigo2->set_sprites2();
       enemigo2->setPos(1400,y3);
       multijugador->addItem(enemigo2);
       multijugador->addItem(enemigo1);
       mapa2=new mapas;
       mapa2->mapa1_vidaper();
       mapa2->setPos(0,0);
       multijugador->addItem(mapa2);
       mapa2e=new mapas;
       mapa2e->mapa1_vidaene();
       mapa2e->setPos(1155,15);
       multijugador->addItem(mapa2e);
       vidas_j1=new partida;
       multijugador->addItem(vidas_j1);
       vidas_j2=new partida;
       multijugador->addItem(vidas_j2);
       vidas_j1->inicializar_multi();
       vidas_j2->inicializar_multi_j2();
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
          nivel1->clear();
          multijugador->clear();
          timer->stop();
          cont=90;
    }
}

void MainWindow::resorte()
{
    float resorte=0,a=30,desfase=0,w=0.2,xf;
       resorte=360+a*sin(w*i+desfase);
       xf=abs(360-resorte);
       jugador->setPos(x1=xf,y1+10);
       i+=0.5;
       if(i>=10){
           timer2->stop();
       }
}

void MainWindow::resorte_derecha()
{

    float resorte=0,a=30,w=0.2;
       resorte=abs(((a*sin(w*i)+1400)));
       jugador->setPos(x1=resorte,y1+10);
       i-=0.5;
       if(i<=0){
           timer3->stop();
       }
}

void MainWindow::resorte_j2_izq()
{
     float resorte=0,a=30,desfase=0,w=0.2,xf;
       resorte=360+a*sin(w*i+desfase);
       xf=abs(360-resorte);
       enemigo2->setPos(x3=xf,y3);
       i+=0.5;
       if(i>=10){
           timer4->stop();
       }
}

void MainWindow::resorte_j2_der()
{
    float resorte=0,a=30,w=0.2;
       resorte=abs(((a*sin(w*i)+1400)));
       enemigo2->setPos(x3=resorte,y3);
       i-=0.5;
       if(i<=0){
           timer5->stop();
       }
}

void MainWindow::caida_libre_1j()
{
    jugador->subida();
    float vyo=50, y2,g=10;
    y2 = vyo*i*(0.001*T)-0.5*g*i*(0.001*T)*i*(0.001*T)+205;
    jugador->setPos(x1,int(abs(h-y2-300)));
    i++;
    if(i>=250){
        jugador->bajada();
    }
    if(i>=503){
     jugador->set_sprites();
     timer6->stop();
    }
}

void MainWindow::caida_libre_multi()
{
    float vyo=50, y2=0,g=10;
    y2 = vyo*i*(0.001*T)-0.5*g*i*(0.001*T)*i*(0.001*T)+205;
   // qDebug()<<y2;
    //  y = yo+vyo*n*(0.001*T)-0.5*g*n*(0.001*T)*n*(0.001*T);
    enemigo2->caida_libre_e2(i);
    enemigo2->setPos(x3,int(abs(h-y2-327)));
    i++;
    if(i>=515){
     timer7->stop();
}
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()){
        case Qt::Key_Escape:
        ui->pausa->show();
        timer->stop();
        ui->pausa->setFont(QFont("Lucida Handwriting",26,QFont::Bold));
        ui->pausa->setText("Menu de pausa");
        ui->pausa->setGeometry(635,92,500,100);
        ui->btn_reanudar->show();
        ui->btn_guardar->show();
        ui->btn_volver_menu->show();
        ui->btn_salir->show();
        ui->btn_reanudar->setGeometry(620,170,350,130);
        ui->btn_guardar->setGeometry(620,305,350,130);
        ui->btn_volver_menu->setGeometry(610,440,373,130);
        ui->btn_salir->setGeometry(620,575,354,130);
        ui->rect->show();
        ui->rect->setGeometry(480,100,600,620);
    case Qt::Key_D:
        jugador->sprites('d');
        jugador->setPos(x1=x1+20,y1+10);
        if(x1>=1440){
               qDebug()<<"Tocó el borde";
               timer3->start(50);
               i=10;
               resorte_derecha();
           }
        break;
    case Qt::Key_A:
        jugador->sprites('a');
        jugador->setPos(x1=x1-20,y1+10);
        if(x1<5){
            timer2->start(50);
            i=0;
            resorte();
        }
        break;
    case Qt::Key_W:
        timer6->start(2);
        i=0;
        qDebug()<<y1;
        caida_libre_1j();
        break;

    case Qt::Key_F:

        jugador->sprites('f');
   //     jugador->collidesWithItem(enemigo1);
        colision_je=jugador->collidesWithItem(enemigo1);  //colision jugador-enemigo1
        colision_j1j2=jugador->collidesWithItem(enemigo2);
        qDebug()<<"Colision multi "<<colision_j1j2;
       if(colision_j1j2==true){
           timerid=0;
           contj1j2++;
}
        if(contj1j2%2==0){
          qDebug()<<"Timer n2: "<<timerid;
         vida_j2=vidas_j2->vidas_multi_j2(colision_j1j2);
        qDebug()<<"Vida jugador 2 "<<vida_j2;
           vidas_j2->setPos(1155,15);
           mapa2e->hide();
        }
        if(vida_j2==11){


        qDebug()<<"Ganador jugador 1";
        nivel2->clear();
        multijugador->clear();
        nivel1->clear();
        ui->n_jugador1->hide();
        ui->n_enemigo1->hide();
        ui->n_enemigo1_2->hide();
        timer->stop();
        ui->lcdNumber->hide();
        ganador->setSceneRect(0,0,1898,1003);
        ganador->setBackgroundBrush(QImage(":/Imagenes/Fondos/Ganador.png").scaled(1550,820));
        ui->graphicsView->setScene(ganador);
}
       // colision_je2=jugador->collidesWithItem(enemigo2); //colision jugador-enemigo2, es para el segundo nivel
       // qDebug()<<colision_je2;
        if(colision_je==true){
        contador++;

        if(contador%2==0){
         mapa1e->hide();
         pasar_nivel=vidas_ene1->vida_ene1(colision_je);
        qDebug()<<"Pasar nivel: "<<pasar_nivel;
           vidas_ene1->setPos(1152,15);
        }




        if(pasar_nivel==11){
            pasar_nivel=1;
            timer->stop();
            nivel1->removeItem(jugador);
            nivel1->removeItem(mapa1e);
            nivel1->removeItem(mapa1);
            nivel1->removeItem(vidas_ene1);
            vidas_ene1=new partida;
            contn2=60;
            n2timer->start(1000);
            timerid=startTimer(1000);
            qDebug()<<"Timer n2: "<<timerid;
            nombre_usuario=ui->ingresar_usuario->toPlainText();
            qDebug()<<nombre_usuario;
            nivel2->setSceneRect(0,0,1898,1003);
            nivel2->setBackgroundBrush(QImage(":/Imagenes/Fondos/FondoUdeA.jpeg").scaled(1550,820));
            ui->graphicsView->setScene(nivel2);
            ui->n_enemigo1->show();
            ui->n_enemigo1->setFont(QFont("Lucida Calligraphy",22,QFont::Bold));
            ui->n_enemigo1->setText(nombre_usuario);
            ui->n_enemigo1->setGeometry(50,-20,500,100);
            ui->n_enemigo1_2->setFont(QFont("Lucida Calligraphy",22,QFont::Bold));
            ui->n_enemigo1_2->show();
            ui->n_enemigo1_2->setFont(QFont("Lucida Calligraphy",22,QFont::Bold));
            ui->n_enemigo1_2->setText("Augusto");
            ui->n_enemigo1_2->setGeometry(1340,-20,500,100);
            nivel2->addItem(jugador);
            jugador->set_sprites();
            jugador->setPos(pos0xper,pos0yper);
            enemigo2 =new enemigo;
            enemigo2->set_sprites2();
            enemigo2->setPos(1400,y3);
            nivel2->addItem(enemigo2);
            mapa2= new mapas;
            mapa2->mapa1_vidaper();
            mapa2->setPos(0,15);
            nivel2->addItem(mapa2);
            mapa2e=new mapas;
            mapa2e->mapa2_vidaene();
            mapa2e->setPos(1152,15);
            nivel2->addItem(mapa2e);
            nivel2->addItem(vidas_ene1);
            qDebug()<<"pasar nivel inicial"<<pasar_nivel;

        }
     }
        if(timerid>4){
            nivel2->clear();
            multijugador->clear();
            nivel1->clear();
            ui->n_jugador1->hide();
            ui->n_enemigo1_2->hide();
            qDebug()<<"Ganaste";
            n2timer->stop();
            ui->lcdNumber->hide();
            ganador->setSceneRect(0,0,1898,1003);
            ganador->setBackgroundBrush(QImage(":/Imagenes/Fondos/Ganador.png").scaled(1550,820));
            ui->graphicsView->setScene(ganador);


        }




        break;

    case Qt::Key_Q:
        jugador->sprites('q');
        colision_je=jugador->collidesWithItem(enemigo1);  //colision jugador-enemigo1
       // colision_je1=jugador->collidesWithItem(enemigo2);

    if(contador%3==0){

     mapa1e->hide();
     pasar_nivel=vidas_ene1->vida_ene1(colision_je);
     vidas_ene1->setPos(1152,15);
}
    if(colision_je==true){
     contador++;
    }





    if(pasar_nivel==11){
        pasar_nivel+=1;
        nivel1->removeItem(jugador);
        nivel1->removeItem(mapa1e);

        nivel1->removeItem(mapa1);
        contadorn2=0;
        timer->stop();
        vidas_ene1->inicializar_partida();
        contn2=60;
        n2timer->start(1000);
        timerid=startTimer(1000);
        nombre_usuario=ui->ingresar_usuario->toPlainText();
        qDebug()<<nombre_usuario;
        nivel2->setSceneRect(0,0,1898,1003);
        nivel2->setBackgroundBrush(QImage(":/Imagenes/Fondos/FondoUdeA.jpeg").scaled(1550,820));
        ui->graphicsView->setScene(nivel2);
        ui->n_jugador1->show();
        ui->n_jugador1->setFont(QFont("Lucida Calligraphy",22,QFont::Bold));
        ui->n_jugador1->setText(nombre_usuario);
        ui->n_jugador1->setGeometry(50,-20,500,100);
        ui->n_enemigo1_2->setFont(QFont("Lucida Calligraphy",22,QFont::Bold));
        ui->n_enemigo1_2->show();
        ui->n_enemigo1_2->setFont(QFont("Lucida Calligraphy",22,QFont::Bold));
        ui->n_enemigo1_2->setText("Augusto");
        ui->n_enemigo1_2->setGeometry(1340,-20,500,100);
        vidas_ene1=new partida;
        jugador= new personaje;
        nivel2->addItem(jugador);
        jugador->set_sprites();
        jugador->setPos(pos0xper,pos0yper);
        enemigo2 =new enemigo;
        enemigo2->set_sprites2();
        enemigo2->setPos(1400,y3);
        mapa2= new mapas;
        mapa2->mapa1_vidaper();
        mapa2->setPos(0,15);
        nivel2->addItem(mapa2);
        mapa2e=new mapas;
        mapa2e->mapa2_vidaene();
        mapa2e->setPos(1152,15);
        nivel2->addItem(mapa2e);



    }
        break;
   case Qt::Key_L:
        enemigo2->sprites_e2('l');
        enemigo2->setPos(x3=x3+10,y3);
        if(x3>=1420){
               timer5->start(50);
               i=10;
               resorte_j2_der();
           }
        break;
   case Qt::Key_J:
        enemigo2->sprites_e2('j');
        enemigo2->setPos(x3=x3-10,y3);
        if(x3<5){
            timer4->start(50);
            i=0;
            resorte_j2_izq();
        }
        break;
   case Qt::Key_I:
        timer7->start(2);
        i=0;
        caida_libre_multi();
        break;
   case Qt::Key_P:
        enemigo2->sprites_e2('p');
        colision_je2=enemigo2->collidesWithItem(jugador);  //colision jugador-enemigo1
       // colision_je2=jugador->collidesWithItem(enemigo2); //colision jugador-enemigo2, es para el segundo nivel
        qDebug()<<colision_je2;

        if(colision_je2==true){
             qDebug()<<"contadorrn2 "<<contadorn2;
        contadorn2++;
        }
        if(contadorn2%2==0){
     //   mapa2->hide();
         ganadormulti=vidas_j1->vida_jugador_multi(colision_je2);
        qDebug()<<"Pasar nivel: "<<ganadormulti;
        vidas_j1->setPos(0,0);


        }




        if(contadorn2==21){
            qDebug()<<"Ganador jugador 2";
            nivel2->clear();
            multijugador->clear();
            nivel1->clear();
            ui->n_jugador1->hide();
            ui->n_enemigo1->hide();
            ui->n_enemigo1_2->hide();
            timer->stop();
            ui->lcdNumber->hide();
            ganador->setSceneRect(0,0,1898,1003);
            ganador->setBackgroundBrush(QImage(":/Imagenes/Fondos/Ganador.png").scaled(1550,820));
            ui->graphicsView->setScene(ganador);
        }

        break;
   case Qt::Key_M:
        enemigo2->sprites_e2('m');
        break;
}
}

void MainWindow::on_btn_guardar_clicked()
{
   // dat_partida->nuevaPartida(nombre,)
}

void MainWindow::on_btn_volver_menu_clicked()
{
    ui->lcdNumber->display(1000);
     n2timer->stop();
     timer->stop();
     cont=90;
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
     ui->ingrese_nom->hide();
     ui->ingresar_usuario->hide();
     ui->n_jugador1->hide();
     ui->n_enemigo1_2->hide();
     ui->pausa->hide();
     ui->rect->hide();
     x1=0;
     y1=500;
     x3=1400;
     y3=480;
     nivel1->clear();
     multijugador->clear();
     nivel2->clear();
     ui->graphicsView->setScene(menu);
}
MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
    delete timer2;
    delete timer3;
    delete timer4;
    delete timer5;
    delete timer6;
    delete timer7;
    delete nivel1;
    delete nivel2;
    delete multijugador;
    delete mensaje;
    delete jugador;
    delete enemigo1;
    delete enemigo2;
    delete mapa2;
    delete mapa2e;
    delete mapa1;
    delete mapa1e;
}

void MainWindow::on_btn_reanudar_clicked()
{
    timer->start();
    ui->btn_reanudar->hide();
    ui->btn_guardar->hide();
    ui->btn_volver_menu->hide();
    ui->btn_salir->hide();
    ui->pausa->hide();
    ui->rect->hide();
}


void MainWindow::on_btn_aceptar_clicked()
{
    qDebug()<<"Entro a aceptar";
    cont=90;
    timer->start(1000);
    qDebug()<<cont;
    nombre_usuario=ui->ingresar_usuario->toPlainText();
    qDebug()<<nombre_usuario;
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
    ui->rect->hide();
    ui->btn_aceptar->hide();
    ui->btn_cancelar->hide();
    ui->ingrese_nom->hide();
    ui->ingresar_usuario->hide();
    ui->ingresar_usuario->setDisabled(true);
    ui->lcdNumber->show();
    ui->graphicsView->setGeometry(0,0,1900,1005);
    nivel1->setSceneRect(0,0,1898,1003);
    nivel1->setBackgroundBrush(QImage(":/Imagenes/Fondos/Tokyo2.jpg").scaled(1550,820));
    ui->graphicsView->setScene(nivel1);
    ui->n_jugador1->show();
    ui->n_jugador1->setFont(QFont("Lucida Calligraphy",22,QFont::Bold));
    ui->n_jugador1->setText(nombre_usuario);
    ui->n_jugador1->setGeometry(50,-20,500,100);
    ui->n_enemigo1_2->setFont(QFont("Lucida Calligraphy",22,QFont::Bold));
    ui->n_enemigo1_2->show();
    ui->n_enemigo1_2->setFont(QFont("Lucida Calligraphy",22,QFont::Bold));
    ui->n_enemigo1_2->setText("Jonathan");
    ui->n_enemigo1_2->setGeometry(1340,-20,500,100);
    ui->lcdNumber->setGeometry(700,10,100,35);
    jugador= new personaje;
    nivel1->addItem(jugador);
    jugador->set_sprites();
    jugador->setPos(pos0xper,pos0yper);
    enemigo1 =new enemigo;
    enemigo2 =new enemigo;
    enemigo1->set_sprites1();
    enemigo1->setPos(1400,470);
    nivel1->addItem(enemigo1);
    nivel1->addItem(enemigo2);
    mapa1=new mapas;
    mapa1->mapa1_vidaper();
    mapa1->setPos(0,15);
    nivel1->addItem(mapa1);
    mapa1e=new mapas;
    mapa1e->mapa1_vidaene();
    mapa1e->setPos(1152,15);
    nivel1->addItem(mapa1e);
    h=ui->graphicsView->height();
    nivel1->addItem(vidas_ene1);
}

void MainWindow::on_btn_cancelar_clicked()
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
    ui->rect->hide();
    ui->btn_aceptar->hide();
    ui->btn_cancelar->hide();
    ui->ingrese_nom->hide();
    ui->ingresar_usuario->clear();
    ui->ingresar_usuario->hide();
    ui->btn_nueva_par->show();
    ui->btn_cargar_par->show();
    ui->btn_volver->show();
    ui->btn_nueva_par->setGeometry(1550/2-110,820/2-120,200,80);
    ui->btn_cargar_par->setGeometry(1550/2-110,820/2-35,200,80);
    ui->btn_volver->setGeometry(1550/2-110,820/2+50,210,90);
}

void MainWindow::nivel2_tiempo()
{
    ui->lcdNumber->display(contn2);
    contn2-=1;
    if(contn2<=0){
          mensaje=new QMessageBox;
          QMessageBox::information(this,"Alma Mater Martial Combat","Se acabó el tiempo, perdiste. \nVolverás al menu.");
          ui->lcdNumber->hide();
          menu->setBackgroundBrush(QImage(":/Imagenes/Menu/Fondo_menu.png").scaled(1550,820));
          ui->n_enemigo1->hide();
          ui->n_enemigo1_2->hide();
          ui->n_jugador1->hide();
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
          nivel1->clear();
          multijugador->clear();
          timer->stop();
          contn2=60;
    }
}
