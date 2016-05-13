#include "button.h"
#include <QGraphicsTextItem>
#include <QBrush>
#include <QFont>
#include <QDebug>

Button::Button(QString name, QGraphicsItem *parent): QGraphicsRectItem(parent){
    //draw the rect
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::gray);
    setBrush(brush);

    // draw the text
    text = new QGraphicsTextItem(name,this);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);
    //text->setFont(QFont("Arial",20));


    // allow responding to hover events
    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    emit clicked();
    qDebug() << "Clicked";
}

void Button::hoverEnterEvent(QGraphicsSceneMouseEvent *event){
    // change color to cyan
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::cyan);
    setBrush(brush);
    qDebug() << "HOVERING";
}

void Button::hoverLeaveEvent(QGraphicsSceneMouseEvent *event){
    // change color to dark cyan
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::darkCyan);
    setBrush(brush);
    qDebug() << "NOT HOVERING";
}


