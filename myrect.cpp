#include "myrect.h"
#include "drums.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include <cstdlib>
#include "mytimer.h"
#include "game.h"

extern Game * game;

MyRect::MyRect(QGraphicsItem *parent): QGraphicsRectItem(parent){
    drumsound_dong = new QMediaPlayer();
    drumsound_dong->setMedia(QUrl("qrc:/sounds/dong.wav"));

    drumsound_ka = new QMediaPlayer();
    drumsound_ka->setMedia(QUrl("qrc:/sounds/ka.wav"));

    A_tag = 0;

}

void MyRect::keyPressEvent(QKeyEvent *event){
    qDebug() << (this->rect().x() - getCollide_x() );
    if(event->key() == Qt::Key_F){

        // play drumsound_dong
        if(drumsound_dong->state() == QMediaPlayer::PlayingState){
            drumsound_dong->setPosition(0);
        }else if(drumsound_dong->state() == QMediaPlayer::StoppedState){
            drumsound_dong->play();
        }

        //qDebug() << "L is Pressed!"<<this->rect().x();

        if( abs(this->rect().x() - getCollide_x() ) <= 30){
            qDebug() <<"L_A";
            this->setA_tag(1);
        }else{
            qDebug() <<"L_B";
            this->setA_tag(0);
        }

    }else if(event->key() == Qt::Key_J){
        // play drumsound_ka
        if(drumsound_ka->state() == QMediaPlayer::PlayingState){
            drumsound_ka->setPosition(0);
        }else if(drumsound_ka->state() == QMediaPlayer::StoppedState){
            drumsound_ka->play();
        }

        //qDebug() << "R is Pressed!" <<this->rect().x();
        if( abs(this->rect().x() - getCollide_x() ) <= 30 ){
            qDebug() <<"R_A";
            this->setB_tag(1);
        }else{
            qDebug() <<"R_B";
            this->setB_tag(0);
        }
    }
}

int MyRect::getCollide_x()
{
    return collide_x;
}

void MyRect::setCollide_x(int a)
{
    collide_x = a;
}

int MyRect::getA_tag()
{
    return A_tag;
}

void MyRect::setA_tag(int b)
{
    A_tag = b;
}

int MyRect::getB_tag()
{
    return B_tag;
}

void MyRect::setB_tag(int c)
{
    B_tag = c;
}

void MyRect::spawn()
{
    game->mytimer->decrease();

    //create a drum
    if(game->mytimer->getTime() > 7){
    Drums * drum = new Drums();
    scene()->addItem(drum);
    }

    if(game->mytimer->getTime() == 0){
        game->gameOver();
    }
}
