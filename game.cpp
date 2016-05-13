#include "game.h"
#include <QTimer>
#include <QApplication>
#include <QGraphicsScene>
#include "myrect.h"
#include <QGraphicsView>
#include <QObject>
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>
#include <QFont>
#include <score.h>
#include "mytimer.h"
#include <QWidget>
#include <QPushButton>
#include <QGraphicsTextItem>
#include "button.h"


Game::Game(QWidget *parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    //setScene(scene);
    scene->setBackgroundBrush(QBrush(QImage(":/images/startmenu.png")));
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    setScene(scene);

    opening_song = new QMediaPlayer();
    opening_song->setMedia(QUrl("qrc:/sounds/Taiko_opening.mp3"));

    game_song = new QMediaPlayer();
    game_song->setMedia(QUrl("qrc:/sounds/game_song.mp3"));
    //show();
}

void Game::start(){
    //clear the screen

    if(opening_song->state() == QMediaPlayer::PlayingState){
        opening_song->stop();
    }

    scene->clear();

    game_song->play();
    scene->setBackgroundBrush(QBrush(QImage(":/images/taiko_bg.png")));
    player = new MyRect();
    player->setRect(128,160,70,70);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    scene->addItem(player);

    //create the score
    score = new Score();
    scene->addItem(score);
    //create timer
    mytimer = new Mytimer();
    scene->addItem(mytimer);

    // spawn drums
    srand (time(NULL));
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));

    timer->start(1000);

}

void Game::restartGame()
{
    delete player;
    delete score;
    delete mytimer;
    scene->clear();

    start();
}

void Game::displayMainMenu(){

    opening_song->play();

    // create the play button
    Button* playButton = new Button(QString("Start"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 470;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // create the quit button
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int qyPos = 530;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
}

void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity){
    // draws a panel at the specified location with the specified properties
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}

void Game::gameOver()
{
    game_song->stop();
    QString message;

    message.sprintf("%s: %d","Score",score->getScore());
    displayGameOverWindow(message);
}

void Game::displayGameOverWindow(QString textToDisplay){
    //disable all scene items
    for(size_t i =0, n = scene->items().size(); i<n; i++){
        scene->items()[i]->setEnabled(false);
    }

    // draw panel
    drawPanel(200,184,400,300,Qt::lightGray,0.75);

    // create playAgain button
    Button* playAgain = new Button(QString("Play Again"));
    playAgain->setPos(300,300);
    scene->addItem(playAgain);
    connect(playAgain,SIGNAL(clicked()),this,SLOT(restartGame()));

    // create quit button
    Button* quit = new Button(QString("Quit"));
    quit->setPos(300,375);
    scene->addItem(quit);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));

    // create text to disply score
    QGraphicsTextItem* scoreText = new QGraphicsTextItem(textToDisplay);
    scoreText->setPos(300,225);
    scoreText->setScale(3);
    scene->addItem(scoreText);
}



