#include "mytimer.h"
#include <QFont>
#include <QDebug>
#include <QTimer>

Mytimer::Mytimer(QGraphicsItem *parent): QGraphicsTextItem(){

    //initialize the score to 0
    mytime = 30;

    //draw the text
    setPlainText(QString("Time: ") + QString::number(mytime)); // Score: 0
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",20));
    setPos(670,10);



}

void Mytimer::decrease(){
    if(mytime>0){
    mytime--;
    qDebug() << "time decreased!";
    setPlainText(QString("Time: ") + QString::number(mytime));
    }else if(mytime ==0){
        mytime =0;
    }
}

int Mytimer::getTime()
{
    return mytime;
}
