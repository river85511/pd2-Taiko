#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QGraphicsScene>
#include <QTimer>
#include "myrect.h"
#include <QGraphicsView>
#include <QObject>
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>
#include <QFont>
#include <score.h>
#include "mytimer.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget * parent=0);


    //public methods
    void displayMainMenu();
    void gameOver();
    void displayGameOverWindow(QString textToDisplay);

    //public attributes
    QGraphicsScene * scene;
    MyRect * player;
    Score * score;
    Mytimer * mytimer;

private:
    void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    QMediaPlayer *opening_song;
    QMediaPlayer *game_song;
public slots:
    void start();
    void restartGame();

};

#endif // GAME_H
