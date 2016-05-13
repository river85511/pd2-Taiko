#ifndef DRUMS_H
#define DRUMS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "myrect.h"
class Drums: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Drums();
    void setDrumType(int a);
    int getDrumType();
public slots:
    void move();
private:
    int drum_type;
};

#endif // DRUMS_H
