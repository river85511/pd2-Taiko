#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>
#include <QMediaPlayer>
class MyRect:public QObject, public QGraphicsRectItem{
    Q_OBJECT
    friend class drums;
public:
    MyRect(QGraphicsItem * parent = 0);
    void keyPressEvent(QKeyEvent * event);
    int getCollide_x();
    void setCollide_x(int a);
    int getA_tag();
    void setA_tag(int b);
    int getB_tag();
    void setB_tag(int c);
public slots:
    void spawn();
private:
    int collide_x;
    int A_tag;
    int B_tag;
    QMediaPlayer *drumsound_dong;
    QMediaPlayer *drumsound_ka;

};
#endif // MYRECT_H
