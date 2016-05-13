#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class Button: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    //constructors
    Button(QString name, QGraphicsItem* parent = NULL);

    //public methods(event)
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneMouseEvent *event);
    void hoverLeaveEvent(QGraphicsSceneMouseEvent *event);
signals:
    void clicked();
private:
    QGraphicsTextItem* text;

};

#endif // BUTTON_H
