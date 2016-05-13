#include "drums.h"
#include "myrect.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <time.h>
#include <QDebug>
#include <score.h>
#include "game.h"

extern Game * game;

Drums::Drums(): QObject(), QGraphicsPixmapItem(){

    // set spawn position
    setPos(800,165);
    srand (time(NULL));
    drum_type = rand()%100;
    drum_type = drum_type%2;
    // draw the rect
    //setRect(0,0,50,50);
    if(drum_type == 0){
    setPixmap(QPixmap(":/images/dong.png"));
    }else if(drum_type == 1){
    setPixmap(QPixmap(":/images/ka.png"));
    }

    // connect
    QTimer * timer = new QTimer(this);
    connect( timer,SIGNAL(timeout()),this,SLOT(move()) );

    timer->start(50);
}

void Drums::setDrumType(int a)
{
    drum_type = a;
}

int Drums::getDrumType()
{
    return drum_type;
}

void Drums::move(){

    srand (time(NULL));
    // set drums spawning position
    setPos(x()- 5, y());

    // move drums left
    if(pos().x()+ pixmap().width()< 150){
        qDebug() <<"drum is removed";
        scene()->removeItem(this);
        delete this;
    }

    // check if drums collide with player
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i =0, n = colliding_items.size(); i<n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(MyRect)){
            //qDebug() << this->drum_type;
            game->player->setCollide_x(this->pos().x());
            if( (game->player->getA_tag() == 1) && (this->drum_type == 0) ){
                game->player->setA_tag(0);
                qDebug() <<"A and Red drum is removed";
                game->score->increase();
                delete this;
                game->player->setCollide_x(200);
                return;
            }

            if( (game->player->getB_tag() == 1) && (this->drum_type == 1) ){
                game->player->setB_tag(0);
                qDebug() <<"A and Blue drum is removed";
                game->score->increase();
                delete this;
                game->player->setCollide_x(200);
                return;
            }
            game->player->setA_tag(0);
            game->player->setB_tag(0);
        }
    }



}
