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
    dat_partida=new partida;
    dat_partida->leerArchivo();
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
    timerrese2=new QTimer(this);
    timercpu1g= new QTimer(this);
    timcpu1der=new QTimer(this);
    timresder1=new QTimer(this);
    timercpu2izq= new QTimer(this);
    timebola = new QTimer;
    timresder2=new QTimer(this);
    cpu1=new QTimer(this);
    n2timer=new QTimer(this);
    timercpu2g=new QTimer(this);
    timercpu2der=new QTimer(this);
    timeresizq2=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(nivel1_tiempo()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(resorte()));
    connect(timer3,SIGNAL(timeout()),this,SLOT(resorte_derecha()));
    connect(timer4,SIGNAL(timeout()),this,SLOT(resorte_j2_izq()));
    connect(timer5,SIGNAL(timeout()),this,SLOT(resorte_j2_der()));
    connect(timer6,SIGNAL(timeout()),this,SLOT(caida_libre_1j()));
    connect(timer7,SIGNAL(timeout()),this,SLOT(caida_libre_multi()));
    connect(n2timer,SIGNAL(timeout()),this,SLOT(nivel2_tiempo()));
    connect(cpu1,SIGNAL(timeout()),this,SLOT(mov_izq_cpu1()));
    connect(timerrese2,SIGNAL(timeout()),this,SLOT(resorte_e1_izq()));
    connect(timercpu1g,SIGNAL(timeout()),this,SLOT(golpe_cpu1()));
    connect(timcpu1der,SIGNAL(timeout()),this,SLOT(mov_der_cpu1()));
    connect(timresder1,SIGNAL(timeout()),this,SLOT(resorte_e1_der()));
    connect(timercpu2izq,SIGNAL(timeout()),this,SLOT(mov_izq_cpu2()));
    connect(timercpu2g,SIGNAL(timeout()),this,SLOT(golpe_cpu2()));
    connect(timercpu2der,SIGNAL(timeout()),this,SLOT(mov_der_cpu2()));
    connect(timresder2,SIGNAL(timeout()),this,SLOT(resorte_e2_der()));
    connect(timeresizq2,SIGNAL(timeout()),this,SLOT(resorte_e2_izq()));
    connect(timebola,SIGNAL(timeout()),this,SLOT(simulacion()));
    set_ventana();
    ui->btn_contr_rules->show();
    ui->btn_1_jug->setGeometry(1550/2-110,820/2-120,200,80);
    ui->btn_multi->setGeometry(1550/2-110,820/2-35,200,80);
    ui->btn_salir->setGeometry(1550/2-115,820/2+50,210,85);
    ui->btn_contr_rules->setGeometry(1550/2-115,820/2+128,220,85);
    ui->btn_reglas->hide();
    ui->btn_controles->hide();
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
    ui->btn_aceptar_2->hide();

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
    ui->btn_aceptar_2->hide();
    ui->btn_reglas->hide();
    ui->btn_controles->hide();
    ui->btn_contr_rules->hide();
    ui->btn_nueva_par->show();
    ui->btn_cargar_par->show();
    ui->btn_volver->show();
    ui->btn_nueva_par->setGeometry(1550/2-110,820/2-120,200,80);
    ui->btn_cargar_par->setGeometry(1550/2-110,820/2-35,200,80);
    ui->btn_volver->setGeometry(1550/2-110,820/2+50,210,90);

}

void MainWindow::on_btn_salir_clicked()
{
    dat_partida->guardarPartidaFinal();
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
    ui->btn_reglas->hide();
    ui->btn_controles->hide();
    ui->btn_contr_rules->hide();
    ui->ingresar_usuario->clear();
    ui->graphicsView->setScene(menu);
    ui->btn_aceptar_2->hide();

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
    ui->btn_aceptar_2->hide();
    ui->btn_reglas->hide();
    ui->btn_controles->hide();
    ui->btn_contr_rules->hide();
}


void MainWindow::on_btn_nueva_par_clicked()
{

    vidas_ene1=new partida;
    vidas_ene1->inicializar_partida();
    contador=1; //Se usa para poder tener las colisiones entre jugador y enemigo 1
    contj1j2=1;
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
    ui->btn_reglas->hide();
    ui->btn_controles->hide();
    ui->btn_contr_rules->hide();
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
    ui->btn_aceptar_2->hide();
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
       ui->btn_aceptar_2->hide();
       ui->rect->hide();
       ui->btn_reglas->hide();
       ui->btn_controles->hide();
       ui->btn_contr_rules->hide();
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
       h=ui->graphicsView->height();
       vidas_j1->inicializar_multi();
       vidas_j2->inicializar_multi_j2();
}



void MainWindow::nivel1_tiempo()
{
    ui->lcdNumber->display(cont);
    cont-=1;
    tiempo_lvl=cont;
    if(cont<=0){
          menu->setBackgroundBrush(QImage(":/Imagenes/Fondos/Game over.gif").scaled(1550,820));
          mensaje=new QMessageBox;
          QMessageBox::information(this,"Alma Mater Martial Combat","Se acabó el tiempo, perdiste. \nVolverás al menu.");
          ui->btn_1_jug->hide();
          ui->btn_multi->hide();
          ui->btn_salir->show();
          ui->btn_salir->setGeometry(1550/2-115,820/2+50,210,85);
          ui->btn_nueva_par->hide();
          ui->btn_cargar_par->hide();
          ui->btn_volver->hide();
          ui->btn_iniciar->hide();
          ui->lcdNumber->hide();
          ui->n_enemigo1->hide();
          ui->btn_reanudar->hide();
          ui->btn_guardar->hide();
          ui->btn_volver_menu->show();
          ui->btn_volver_menu->setGeometry(1550/2-110,820/2-35,200,80);
          ui->ingrese_nom->hide();
          ui->ingresar_usuario->hide();
          ui->btn_aceptar_2->hide();
          ui->n_jugador1->hide();
          ui->n_enemigo1_2->hide();
          ui->pausa->hide();
          ui->rect->hide();
          ui->btn_reglas->hide();
          ui->btn_controles->hide();
          ui->btn_contr_rules->hide();
          x1=0;
          y1=500;
          x3=1400;
          y3=480;
          ui->graphicsView->setScene(menu);
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

void MainWindow::resorte_e1_izq()
{
    float resorte=0,a=30,desfase=0,w=0.2,xf;
      resorte=360+a*sin(w*i+desfase);
      xf=abs(360-resorte);
      enemigo1->setPos(x2=xf,e2y2-200);
      i+=0.5;
      if(i>=10){
          timerrese2->stop();
      }
}

void MainWindow::resorte_e1_der()
{
    float resorte=0,a=30,w=0.2;
       resorte=abs(((a*sin(w*i)+1400)));
       enemigo1->setPos(x2=resorte,e2y2-225);
       i2-=0.5;
           cont_golpe_cpu1=0;
           timcpu1der->stop();
           timresder1->stop();
           cpu1->start(200);
       }


void MainWindow::resorte_e2_der()
{
    float resorte=0,a=30,w=0.2;
       resorte=abs(((a*sin(w*i)+1400)));
       enemigo2->setPos(poscpu2=resorte,y3);
       i2-=0.5;

       if(i2<=0){
           timercpu2der->stop();
           timresder2->stop();
           timercpu2izq->start(120);
       }
}

void MainWindow::resorte_e2_izq()
{
    float resorte=0,a=30,desfase=0,w=0.2,xf;
      resorte=360+a*sin(w*i+desfase);
      xf=abs(360-resorte);
      enemigo2->setPos(poscpu2=xf,y3-200);
      i+=0.5;
      if(i>=10){
          timerrese2->stop();
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
        timercpu2g->stop();
        timercpu2der->stop();
        timeresizq2->stop();
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
        cpu1->stop();
        timcpu1der->stop();
    case Qt::Key_D:
        jugador->sprites('d');
        jugador->setPos(x1=x1+20,y1+10);
        if(x1>=1440){
               timer3->start(50);
               i=10;
               resorte_derecha();
           }
        posjug=x1;
        break;
    case Qt::Key_A:
        jugador->sprites('a');
        jugador->setPos(x1=x1-20,y1+10);
        if(x1<5){
            timer2->start(50);
            i=0;
            resorte();
        }
        posjug=x1;
        break;
    case Qt::Key_W:
        timer6->start(2);
        i=0;
        caida_libre_1j();
        break;

    case Qt::Key_F:
        jugador->sprites('f'); 
        colision_je=jugador->collidesWithItem(enemigo1);  //colision jugador-enemigo1
        colision_j1j2=jugador->collidesWithItem(enemigo2);
        if(colision_j1j2==true){
           timerid=0;
           contj1j2++;
}
        if(contj1j2%2==0){
            mapa2e->hide();
         vida_j2=vidas_j2->vidas_multi_j2(colision_j1j2);
           vidas_j2->setPos(1155,15);

        }
        if(vida_j2==11){


        qDebug()<<"Ganador jugador 1";
        ui->n_jugador1->hide();
        ui->n_enemigo1->hide();
        ui->n_enemigo1_2->hide();
        timer->stop();
        ui->lcdNumber->hide();
        ui->btn_reglas->hide();
        ui->btn_controles->hide();
        ui->btn_contr_rules->hide();
        ganador->setSceneRect(0,0,1898,1003);
        ganador->setBackgroundBrush(QImage(":/Imagenes/Fondos/Ganador.png").scaled(1550,820));
        ui->graphicsView->setScene(ganador);
}
        if(colision_je==true){

        contador++;

        if(contador%2==0){
         mapa1e->hide();
         pasar_nivel=vidas_ene1->vida_ene1(colision_je);
           vidas_ene1->setPos(1152,15);
        }




        if(pasar_nivel==11){
     p = new bola();
            pasar_nivel+=1;
            nivel2->addItem(p);
            timercpu1g->stop();
            cpu1->stop();
            timcpu1der->stop();
            timercpu2izq->start(70);

                    nivel1->removeItem(jugador);
                    nivel1->removeItem(mapa1e);
                    cont_nivel=2;
                    nivel1->removeItem(mapa1);
                    contadorn2=0;
                    timer->stop();
                    contn2=60;
                    n2timer->start(1000);
                    timerid=startTimer(1000);
                    cont_mov_der_cpu2=1;
                    nombre_usuario=ui->ingresar_usuario->toPlainText();
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
                    vidas_j2=new partida;
                    vidas_j1=new partida;
                    vidaj1cpu2=new partida;
                    nivel2->addItem(vidas_j1);
                    nivel2->addItem(vidas_j2);
                    nivel2->addItem(vidas_ene1);
                    nivel2->addItem(vidaj1cpu2);
                    vidaj1cpu2->inicializar_cpu1();
                    vidas_ene1->inicializar_partida();
                    vidas_j2->inicializar_multi_j2();
                    cont_golpe_cpu2j2=1;
                    x1=0;
                    jugador= new personaje;
                    nivel2->addItem(jugador);
                    jugador->set_sprites();
                    jugador->setPos(pos0xper,pos0yper);
                    enemigo2 =new enemigo;
                    enemigo2->set_sprites2();
                    enemigo2->setPos(poscpu2,y3);
                    nivel2->addItem(enemigo2);
                    mapa2= new mapas;
                    mapa2->mapa1_vidaper();
                    mapa2->setPos(0,15);
                    nivel2->addItem(mapa2);
                    mapa2e=new mapas;
                    mapa2e->mapa2_vidaene();
                    mapa2e->setPos(1152,15);
                    nivel2->addItem(mapa2e);



        }
     }
        if(timerid==5){
            nivel2->clear();
            multijugador->clear();
            nivel1->clear();
            ui->n_jugador1->hide();
            ui->n_enemigo1_2->hide();
            qDebug()<<"Ganaste";
            n2timer->stop();
            ui->lcdNumber->hide();
            ui->pausa->show();
            ui->pausa->setFont(QFont("Lucida Calligraphy",30,QFont::Bold));
            ui->pausa->setText("Ganaste");
            ui->pausa->setGeometry(1340,-20,500,100);
            ganador->setSceneRect(0,0,1898,1003);
            ganador->setBackgroundBrush(QImage(":/Imagenes/Fondos/Ganador.png").scaled(1550,820));
            ui->graphicsView->setScene(ganador);


        }




        break;

    case Qt::Key_Q:

        jugador->sprites('q');
             colision_je=jugador->collidesWithItem(enemigo1);  //colision jugador-enemigo1
             colision_je2=jugador->collidesWithItem(enemigo2);
            // colision_je1=jugador->collidesWithItem(enemigo2);

             if(colision_je==true){
              contador++;
             }
         if(contador%3==0){
         qDebug()<<"Prueba 1";
          mapa1e->hide();
          pasar_nivel=vidas_ene1->vida_ene1(colision_je);
          vidas_ene1->setPos(1152,15);

     }


         if(colision_je2==true){
             contadore2n2++;

         }
         if(contadore2n2%3){
               mapa2e->hide();
             vida_j2=vidas_j2->vidas_multi_j2(colision_j1j2);
            qDebug()<<"Vida jugador 2 golpe "<<vida_j2;
               vidas_j2->setPos(1155,15);

         }

         if(vida_j2==11){


         qDebug()<<"Ganador jugador 1";
         ui->n_jugador1->hide();
         ui->n_enemigo1->hide();
         ui->n_enemigo1_2->hide();
         timer->stop();
         ui->lcdNumber->hide();
         ganador->setSceneRect(0,0,1898,1003);
         ganador->setBackgroundBrush(QImage(":/Imagenes/Fondos/Ganador.png").scaled(1550,820));
         ui->graphicsView->setScene(ganador);
     }

         /*
         if(contadore2n2%3){

         }

     */

         if(pasar_nivel==11){
             p = new bola();
                    pasar_nivel+=1;
                    nivel2->addItem(p);
                    timercpu1g->stop();
                    cpu1->stop();
                    timcpu1der->stop();
                    timercpu2izq->start(70);

                            nivel1->removeItem(jugador);
                            nivel1->removeItem(mapa1e);
                            cont_nivel=2;
                            nivel1->removeItem(mapa1);
                            contadorn2=0;
                            timer->stop();
                            contn2=60;
                            n2timer->start(1000);
                            timerid=startTimer(1000);
                          //  qDebug()<<"timerid "<<timerid;
                            cont_mov_der_cpu2=1;
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
                            vidas_j2=new partida;
                            vidas_j1=new partida;
                            vidaj1cpu2=new partida;
                            nivel2->addItem(vidas_j1);
                            nivel2->addItem(vidas_j2);
                            nivel2->addItem(vidas_ene1);
                            nivel2->addItem(vidaj1cpu2);
                            vidaj1cpu2->inicializar_cpu1();
                            vidas_ene1->inicializar_partida();
                            vidas_j2->inicializar_multi_j2();
                            cont_golpe_cpu2j2=1;
                            x1=0;
                            jugador= new personaje;
                            nivel2->addItem(jugador);
                            jugador->set_sprites();
                            jugador->setPos(pos0xper,pos0yper);
                            enemigo2 =new enemigo;
                            enemigo2->set_sprites2();
                            enemigo2->setPos(poscpu2,y3);
                            nivel2->addItem(enemigo2);
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

    case Qt::Key_X:
        iniciarbola();
        cont_bola=0;
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
     dat_partida->actualizarPart(nombre_usuario,cont_nivel,vidas,tiempo_lvl,posjug,pasar_nivel);
     n2timer->stop();
     timer->stop();
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
     ui->btn_reglas->hide();
     ui->btn_controles->hide();
     ui->btn_contr_rules->hide();
     ui->btn_iniciar->hide();
     ui->lcdNumber->hide();
     ui->n_enemigo1->hide();
     ui->btn_reanudar->hide();
     ui->btn_guardar->hide();
     ui->btn_volver_menu->hide();
     ui->ingrese_nom->hide();
     ui->ingresar_usuario->hide();
     ui->n_jugador1->hide();
     ui->btn_aceptar_2->hide();
     ui->n_enemigo1_2->hide();
     ui->pausa->hide();
     ui->rect->hide();
     ui->graphicsView->setScene(menu);

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
     ui->btn_reglas->hide();
     ui->btn_controles->hide();
     ui->btn_contr_rules->hide();
     ui->n_enemigo1_2->hide();
     ui->btn_aceptar_2->hide();
     ui->btn_contr_rules->show();
     ui->btn_contr_rules->setGeometry(1550/2-115,820/2+128,220,85);
     ui->pausa->hide();
     ui->rect->hide();
     //remove enemigo 1,2, jugador
     x1=0;
     y1=500;
     x3=1400;
     y3=480;
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
    ui->btn_aceptar_2->hide();
    ui->btn_reglas->hide();
    ui->btn_controles->hide();
    ui->btn_contr_rules->hide();
    cpu1->start();
    timeresizq2->start();
}


void MainWindow::on_btn_aceptar_clicked()
{
    cont_golpe_cpu1=1;
        qDebug()<<"Entro a aceptar";
        cont=90;
        timer->start(1000);
        qDebug()<<cont;
        nombre_usuario=ui->ingresar_usuario->toPlainText();
        qDebug()<<nombre_usuario;
        ui->btn_nueva_par->hide();
        ui->btn_cargar_par->hide();
        p = new bola();
        ui->btn_1_jug->hide();
        ui->btn_multi->hide();
        ui->btn_salir->hide();
        ui->btn_volver->hide();
        ui->btn_reanudar->hide();
        ui->btn_guardar->hide();
        ui->btn_volver_menu->hide();
        ui->pausa->hide();
        ui->btn_aceptar_2->hide();
        ui->rect->hide();
        ui->btn_aceptar->hide();
        ui->btn_cancelar->hide();
        ui->ingrese_nom->hide();
        ui->ingresar_usuario->hide();
        ui->btn_reglas->hide();
        ui->btn_controles->hide();
        ui->btn_contr_rules->hide();
        ui->ingresar_usuario->setDisabled(true);
        ui->lcdNumber->show();
        ui->graphicsView->setGeometry(0,0,1900,1005);
        nivel1->setSceneRect(0,0,1898,1003);
        nivel1->setBackgroundBrush(QImage(":/Imagenes/Fondos/Tokyo2.jpg").scaled(1550,820));
        ui->graphicsView->setScene(nivel1);
        ui->n_jugador1->show();
        ui->n_jugador1->setFont(QFont("Lucida Calligraphy",22,QFont::Bold));
        ui->n_jugador1->setText(nombre_usuario);
        ui->n_jugador1->setGeometry(50,-33,500,100);
        ui->n_enemigo1_2->setFont(QFont("Lucida Calligraphy",22,QFont::Bold));
        ui->n_enemigo1_2->show();
        ui->n_enemigo1_2->setFont(QFont("Lucida Calligraphy",22,QFont::Bold));
        ui->n_enemigo1_2->setText("Jonathan");
        ui->n_enemigo1_2->setGeometry(1340,-20,500,100);
        ui->lcdNumber->setGeometry(700,10,100,35);
        jugador= new personaje;
        nivel1->addItem(jugador);
        nivel1->addItem(p);
        jugador->set_sprites();
        jugador->setPos(pos0xper,pos0yper);
        enemigo1 =new enemigo;
        enemigo2 =new enemigo;
        enemigo1->set_sprites1();
        nivel1->addItem(enemigo1);
        cpu1->start(200);
        nivel1->addItem(enemigo2);
        mapa1=new mapas;
        mapa1->mapa1_vidaper();
        nivel1->addItem(mapa1);
        mapa1e=new mapas;
        mapa1e->mapa1_vidaene();
        mapa1e->setPos(1152,15);
        nivel1->addItem(mapa1e);
        h=ui->graphicsView->height();
        timerid=0;
        i=0;
        vidas_ene1=new partida;
        vidas_j1e1= new partida;
        vidas_j1e1->inicializar_cpu1();
        vidas_j2=new partida;
        nivel1->addItem(vidas_ene1);
        vidas_ene1->inicializar_partida();
        vidas_j2->inicializar_multi_j2();
        nivel1->addItem(vidas_j2);
        nivel1->addItem(vidas_j1e1);
        cont_mov_der=0;
        vidas_j1e1->inicializar_multi_j2();
        cont_nivel=1;
        vidas=11;
        tiempo_lvl=90;
        dat_partida->nuevaPartida(nombre_usuario,cont_nivel,vidas,tiempo_lvl,pos0xper,pasar_nivel);
        contadore1j1=0;
        i2=10;
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
    ui->btn_reglas->hide();
    ui->btn_controles->hide();
    ui->btn_contr_rules->hide();
    ui->ingresar_usuario->clear();
    ui->ingresar_usuario->hide();
    ui->btn_nueva_par->show();
    ui->btn_cargar_par->show();
    ui->btn_aceptar_2->hide();
    ui->btn_volver->show();
    ui->btn_nueva_par->setGeometry(1550/2-110,820/2-120,200,80);
    ui->btn_cargar_par->setGeometry(1550/2-110,820/2-35,200,80);
    ui->btn_volver->setGeometry(1550/2-110,820/2+50,210,90);
}

void MainWindow::nivel2_tiempo()
{
    ui->lcdNumber->display(contn2);
    contn2-=1;
    tiempo_lvl=contn2;
    if(contn2<=0){
          menu->setBackgroundBrush(QImage(":/Imagenes/Fondos/Game over.gif").scaled(1550,820));
          mensaje=new QMessageBox;
          QMessageBox::information(this,"Alma Mater Martial Combat","Se acabó el tiempo, perdiste. \nVolverás al menu.");
          ui->btn_1_jug->hide();
          ui->btn_multi->hide();
          ui->btn_salir->show();
          ui->btn_salir->setGeometry(1550/2-115,820/2+50,210,85);
          ui->btn_nueva_par->hide();
          ui->btn_cargar_par->hide();
          ui->btn_volver->hide();
          ui->btn_iniciar->hide();
          ui->lcdNumber->hide();
          ui->n_enemigo1->hide();
          ui->btn_reanudar->hide();
          ui->btn_guardar->hide();
          ui->btn_reglas->hide();
          ui->btn_controles->hide();
          ui->btn_contr_rules->hide();
          ui->btn_volver_menu->show();
          ui->btn_volver_menu->setGeometry(1550/2-110,820/2-35,200,80);
          ui->ingrese_nom->hide();
          ui->ingresar_usuario->hide();
          ui->btn_aceptar_2->hide();
          ui->n_jugador1->hide();
          ui->n_enemigo1_2->hide();
          ui->pausa->hide();
          ui->rect->hide();
          x1=0;
          y1=500;
          x3=1400;
          y3=480;
          ui->graphicsView->setScene(menu);
    }
}

void MainWindow::mov_izq_cpu1()
{
    enemigo1->mov_izq_e1();
    enemigo1->setPos(x2=x2-20,e2y2-225);
    if(x2<x1+100){
        cpu1->stop();
        timercpu1g->start(300);


    }
    if(x2<5){
        timerrese2->start(50);
        i=0;

    }
}

void MainWindow::mov_der_cpu1()
{
    cont_mov_der+=1;
     enemigo1->mov_izq_e1();
     i=10;
     enemigo1->setPos(x2=x2+20,e2y2-225);
     if(cont_mov_der>1000){

         timcpu1der->stop();
     }
     if(x2>=1440){
            timresder1->start(50);

            resorte_e1_der();
        }



}

void MainWindow::golpe_cpu1()
{
    cont_golpe_cpu1+=1;
    enemigo1->golpe();
    if (cont_golpe_cpu1>7){
        timercpu1g->stop();
        timcpu1der->start(200);
    }
    colision_e1j1=enemigo1->collidesWithItem(jugador);

    if(colision_e1j1==true){
       contadore1j1++;
}
    if(contadore1j1%2==0){
     vida_j1n1=vidas_j1e1->vida_jugador1(colision_e1j1);
     vidas=vida_j1n1;
     mapa1->hide();
  // qDebug()<<"Vida jugador 2 "<<vida_j1n1;
       vidas_j1e1->setPos(0,15);
      // mapa2e->hide();
    }
    if(vida_j1n1==10){
        qDebug()<<"Perdió";
        ui->lcdNumber->display(1000);
         n2timer->stop();
         timer->stop();
         cont=90;
         menu->setBackgroundBrush(QImage(":/Imagenes/Fondos/Game over.gif").scaled(1550,820));
         ui->btn_1_jug->hide();
         ui->btn_multi->hide();
         ui->btn_salir->show();
         ui->btn_salir->setGeometry(1550/2-115,820/2+50,210,85);
         ui->btn_nueva_par->hide();
         ui->btn_cargar_par->hide();
         ui->btn_volver->hide();
         ui->btn_iniciar->hide();
         ui->lcdNumber->hide();
         ui->n_enemigo1->hide();
         ui->btn_reanudar->hide();
         ui->btn_guardar->hide();
         ui->btn_volver_menu->show();
         ui->btn_volver_menu->setGeometry(1550/2-110,820/2-35,200,80);
         ui->ingrese_nom->hide();
         ui->ingresar_usuario->hide();
         ui->btn_aceptar_2->hide();
         ui->btn_reglas->hide();
         ui->btn_controles->hide();
         ui->btn_contr_rules->hide();
         ui->n_jugador1->hide();
         ui->n_enemigo1_2->hide();
         ui->pausa->hide();
         ui->rect->hide();
         x1=0;
         y1=500;
         x3=1400;
         y3=480;
         ui->graphicsView->setScene(menu);
    }

}

void MainWindow::mov_izq_cpu2()
{
    enemigo2->mov_izq_e2();
    enemigo2->setPos(poscpu2=poscpu2-25,y3);
    if(poscpu2<x1+100){
        timercpu2izq->stop();
        timercpu2g->start(200);


    }
    if(x2<5){
        timerrese2->start(50);
        i=0;

    }
}


void MainWindow::on_btn_cargar_par_clicked()
{
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
    ui->btn_reglas->hide();
    ui->btn_controles->hide();
    ui->btn_contr_rules->hide();
    ui->btn_volver->hide();
    ui->ingresar_usuario->clear();
    ui->ingrese_nom->show();
    ui->ingresar_usuario->show();
    ui->ingresar_usuario->setDisabled(false);
    ui->ingresar_usuario->setGeometry(680,335,210,31);
    ui->ingrese_nom->setFont(QFont("Lucida Calligraphy",24,QFont::Bold));
    ui->ingrese_nom->setText("Ingrese su nombre");
    ui->ingrese_nom->setGeometry(620,110,400,400);
    ui->btn_aceptar_2->show();
    ui->btn_cancelar->show();
    ui->btn_aceptar_2->setGeometry(680,370,93,28);
    ui->btn_cancelar->setGeometry(800,370,93,28);
    /*int nivel,vidasj1,tiempo,posicion;
    QString nombre_cargar;

    nivel=dat_partida->nivel(nombre_cargar);
    vidasj1=dat_partida->vidas(nombre_cargar);
    tiempo=dat_partida->tiempo(nombre_cargar);
    posicion=dat_partida->posicion(nombre_cargar);
    */
}

void MainWindow::on_btn_aceptar_2_clicked()
{
    int nivel,vidasj1,tiempo,posicion;
         nombre_cargar=ui->ingresar_usuario->toPlainText();
        qDebug()<<"Nombre cargar"<<nombre_cargar;
        nivel=dat_partida->nivel(nombre_cargar);
        vidasj1=dat_partida->vidas(nombre_cargar);
        tiempo=dat_partida->tiempo(nombre_cargar);
        posicion=dat_partida->posicion(nombre_cargar);

        qDebug()<<"Nivel"<<nivel;
        qDebug()<<"Vidas"<<vidasj1;
        qDebug()<<"Tiempo"<<tiempo;
        qDebug()<<"posicion"<<posicion;
}

void MainWindow::on_btn_contr_rules_clicked()
{
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
    ui->btn_aceptar_2->hide();
    ui->rect->hide();
    ui->btn_contr_rules->hide();
    ui->btn_reglas->show();
    ui->btn_controles->show();
    ui->btn_controles->setGeometry(1550/2-110,820/2-100,220,100);
    ui->btn_reglas->setGeometry(1550/2-110,820/2+20,220,90);

}

void MainWindow::on_btn_reglas_clicked()
{

    ui->btn_volver_menu->show();
    ui->btn_volver_menu->setGeometry(1550/2+500,30,220,100);
    ui->btn_nueva_par->hide();
    ui->btn_cargar_par->hide();
    ui->btn_1_jug->hide();
    ui->btn_multi->hide();
    ui->btn_salir->hide();
    ui->btn_volver->hide();
    ui->btn_iniciar->hide();
    ui->btn_reanudar->hide();
    ui->btn_guardar->hide();
    ui->n_enemigo1_2->hide();
    ui->btn_aceptar_2->hide();
    ui->rect->hide();
    ui->btn_contr_rules->hide();
    ui->btn_reglas->hide();
    ui->btn_controles->hide();
    ui->graphicsView->setGeometry(0,0,1900,1005);
    menu->setSceneRect(0,0,1898,1003);
    menu->setBackgroundBrush(QImage(":/Imagenes/Menu/GAME RULES.jpg").scaled(1550,820));
    ui->graphicsView->setScene(menu);
}

void MainWindow::on_btn_controles_clicked()
{
    ui->btn_volver_menu->show();
    ui->btn_volver_menu->setGeometry(1550/2,650,220,100);
    ui->btn_nueva_par->hide();
    ui->btn_cargar_par->hide();
    ui->btn_1_jug->hide();
    ui->btn_multi->hide();
    ui->btn_salir->hide();
    ui->btn_volver->hide();
    ui->btn_iniciar->hide();
    ui->btn_reanudar->hide();
    ui->btn_guardar->hide();
    ui->n_enemigo1_2->hide();
    ui->btn_aceptar_2->hide();
    ui->rect->hide();
    ui->btn_contr_rules->hide();
    ui->btn_reglas->hide();
    ui->btn_controles->hide();
    ui->graphicsView->setGeometry(0,0,1900,1005);
    menu->setSceneRect(0,0,1898,1003);
    menu->setBackgroundBrush(QImage(":/Imagenes/Menu/menuControles.png").scaled(1550,820));

    ui->graphicsView->setScene(menu);
}

void MainWindow::golpe_cpu2()
{
   cont_golpe_cpu2j2+=1;
    //qDebug()<<"Entro a golpe cpu2";
    enemigo2->golpe_cpu2();
    enemigo2->setPos(poscpu2,y3+5);

    if (cont_golpe_cpu2j2>13){
        timercpu2g->stop();
       timercpu2der->start(120);
    }
    colision_cpu2j1=enemigo2->collidesWithItem(jugador);
    if(colision_cpu2j1==true){
       cont_golpe_cpu2j2++;
}
    if(cont_golpe_cpu2j2%2==0){
     vida_j1n2=vidaj1cpu2->vida_jugador1(colision_cpu2j1);
     vida_j1n2tot=vida_j1n2;
     mapa2->hide();
       vidas_j1e1->setPos(0,15);
    }
    if(vida_j1n2==10){
        qDebug()<<"Perdió n2";
        ui->lcdNumber->display(1000);
         n2timer->stop();
         timer->stop();
         cont=90;
         menu->setBackgroundBrush(QImage(":/Imagenes/Fondos/Game over.gif").scaled(1550,820));
         ui->btn_1_jug->hide();
         ui->btn_multi->hide();
         ui->btn_salir->show();
         ui->btn_salir->setGeometry(1550/2-115,820/2+50,210,85);
         ui->btn_nueva_par->hide();
         ui->btn_cargar_par->hide();
         ui->btn_volver->hide();
         ui->btn_iniciar->hide();
         ui->lcdNumber->hide();
         ui->n_enemigo1->hide();
         ui->btn_reanudar->hide();
         ui->btn_guardar->hide();
         ui->btn_volver_menu->show();
         ui->btn_volver_menu->setGeometry(1550/2-110,820/2-35,200,80);
         ui->ingrese_nom->hide();
         ui->ingresar_usuario->hide();
         ui->btn_aceptar_2->hide();
         ui->n_jugador1->hide();
         ui->n_enemigo1_2->hide();
         ui->pausa->hide();
         ui->rect->hide();
         x1=0;
         y1=500;
         x3=1400;
         y3=480;
         ui->graphicsView->setScene(menu);
    }
}

void MainWindow::mov_der_cpu2()
{
     cont_mov_der_cpu2+=1;
      enemigo2->mov_izq_e2();
      cont_golpe_cpu2j2=0;
      i=10;
      enemigo2->setPos(poscpu2=poscpu2+25,y3);
      if(poscpu2>x1+300){

          timercpu2der->stop();
          timercpu2izq->start(150);
      }
      if(poscpu2>=1440){
             timresder2->start(50);

             resorte_e2_der();
         }

}

void MainWindow::simulacion()
{

 float vyo=75, y2,g=10,T=20,x;

        x = x1+vxo*i*(0.0007*T);
        y2 = vyo*i*(0.001*T)-0.5*g*i*(0.001*T)*i*(0.001*T)+300;
        xo=int(x);
        iniciarbola();


        if(i<60){
            p->setPos(x1,y1-40);

        }
      if(i>62){
          p->setPos(int(xo),int(h-y2-80));

      }

        if (i>700){
            pararbola();
        }
        i++;

}

void MainWindow::iniciarbola()
{

    if(xo==x1){
        cont_col_bola+=1;
        vidas_ene1->vida_ene1(cont_col_bola);
        vidas_ene1->setPos(1152,15);
    }
      p->sprites(i);
      timebola->start(1);
}

void MainWindow::pararbola()
{
     timebola->stop();
     xo=0;
     i=0;
}
