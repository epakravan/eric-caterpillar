#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QObject>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <iostream>
#include <QHBoxLayout>
#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QGraphicsSimpleTextItem>


#include "data.h"
#include "player.h"
#include "canvas.h"
#include "itemA.h"
#include "itemB.h"
#include "itemC.h"
#include "itemD.h"
#include "itemE.h"

#define WINDOW_MAX_X 1000
#define WINDOW_MAX_Y 500

class MainWindow : public QGraphicsView {
    Q_OBJECT
    
public:
    MainWindow(QApplication *a_);
    ~MainWindow();
    void eat();
    void leaf();
    void addFood();
    void addItemA();
    void addItemB();    
    void addItemC();
    void addItemD();
    void addItemE();
    
protected:    
    void keyPressEvent(QKeyEvent *e);
    void keyReleaseEvent(QKeyEvent *e);
    
private:
    int score;
    int lives;
    int interval;
    
    bool paused;
    
    QApplication* a;
    QGraphicsScene *scene;
    QTimer *timer;
    QPushButton *startButton;
    QPushButton *pauseButton;
    QPushButton *resignButton;
    QPushButton *quitButton;
    
    QGraphicsSimpleTextItem *titleText;
    QGraphicsSimpleTextItem *subtitleText;
    QGraphicsSimpleTextItem *scoreCaptionText;
    QGraphicsSimpleTextItem *livesCaptionText;
    QGraphicsSimpleTextItem *scoreText;
    QGraphicsSimpleTextItem *livesText;
    
    QPixmap* mainMap;
    QPixmap* backgroundMap;
    QPixmap* caterpillarMap;
    QPixmap* leafMap;
    QPixmap* ladybugMap;
    QPixmap* spiderMap;
    QPixmap* beeMap;
    QPixmap* strawberryMap;
    QPixmap* orangeMap;
    QPixmap* plumMap;
    QPixmap* appleMap;
    QPixmap* pearMap;
    QPixmap* sunMap;
    QPixmap* cakeMap;
    QPixmap* pieMap;
    QPixmap* icecreamMap;
    QPixmap* cupcakeMap;
    
    Player *player;
    Canvas *canvas;
    
    Data<Item*> itemAs, itemBs, itemCs, itemDs, itemEs;

public slots:
    void HandleTimer();
    void StartGame();
    void PauseGame();
    void GameOver();
    void QuitGame();
};

#endif // MAINWINDOW_H
