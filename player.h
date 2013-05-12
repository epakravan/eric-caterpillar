#ifndef PLAYER_H
#define PLAYER_H
#include <QTimer>
#include <iostream>
#include "item.h"
#include "data.h"
#include "canvas.h"

class Player : public QObject, public Item {
    Q_OBJECT
public:
    Player(Canvas* canvas_);
    ~Player();
    void eat();
    void leaf(int loc_);
    void bounce();
    void grab();

private:
    int defaultX;
    int defaultY;
    int loc;
    int count;
    bool bouncing;
    bool grabbing;
    bool grab_left;
    bool grab_right;
    bool rising;
    QTimer *timer;

public slots:
    void timercontrol();

};

#endif // PLAYER_H
