#ifndef MYTIMER_H
#define MYTIMER_H

#include <QGraphicsTextItem>

class Mytimer: public QGraphicsTextItem{

public:
    Mytimer(QGraphicsItem * parent = 0);
    void decrease();
    int getTime();
private:
    int mytime;

};

#endif // MYTIMER_H
