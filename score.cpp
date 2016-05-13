#include "score.h"
#include <QFont>
#include <QDebug>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    //initialize the score to 0
    score = 0;

    //draw the text
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::black);
    setFont(QFont("times",20));
    setPos(670,40);
}


void Score::increase(){
    score += 20;
    qDebug() << "score up!";
    setPlainText(QString("Score: ") + QString::number(score));
}

int Score::getScore()
{
    return score;
}

