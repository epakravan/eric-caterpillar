#ifndef ITEM_H
#define ITEM_H
#include <QGraphicsPixmapItem>
#include "data.h"
#include "canvas.h"

/**
  This class maintains the location, size, and speed of a QGraphicsRectItem.
  It is easier to do the arithmetic with this data, and then update the position
  separately, then to extract coordinates from the QRectF that is contained within
  the QGraphicsRectItem
  */
class Item : public QGraphicsPixmapItem {
public:
    Item(Canvas* canvas_);
    void setData(Data<Item*>* items_);
    void set(int nx, int ny, int w, int h, int vx, int vy);
    void setX(int nx);
    void setY(int ny);
    void setSize(int w, int h);
    void setWidth(int w);
    void setHeight(int h);
    void setVelocity(int vx, int vy);
    void setVelocityX(int vx);
    void setVelocityY(int vy);
    void setSpeed(int sx, int sy);
    void setSpeedX(int sx);
    void setSpeedY(int sy);
    void setWindowMax(int wx, int wy);
    void setWindowMaxX(int wx);
    void setWindowMaxY(int wy);
    void setMargin(int mTop, int mBottom, int mLeft, int mRight);
    void setMarginTop(int mTop);
    void setMarginBottom(int mBottom);
    void setMarginLeft(int mLeft);
    void setMarginRight(int mRight);
    
    int getLeft(); 
    int getRight();
    int getTop(); 
    int getBottom();
    
    int getX();
    int getY();
    int getVelocityX();
    int getVelocityY();
    int getWidth();
    int getHeight();
    int getSpeedX();
    int getSpeedY(); 
    int getWindowMaxX();
    int getWindowMaxY();
    int getMarginTop();
    int getMarginBottom();
    int getMarginLeft();
    int getMarginRight();
    
    bool Top();
    bool Bottom();
    bool Left();
    bool Right();
    
    void move();
    virtual void move_up();
    virtual void move_down();
    virtual void move_left();
    virtual void move_right();
    
    virtual int onTimer();
    
protected:
    int x;
    int y;
    int width;
    int height;
    int velocityX;
    int velocityY;
    int speedX;
    int speedY;
    int windowMaxX;
    int windowMaxY;
    int marginTop;
    int marginBottom;
    int marginLeft;
    int marginRight;
    
    Data<Item*>* items;
    Canvas* canvas;
    
    Item* left_blocker;
    Item* right_blocker;
    Item* up_blocker;
    Item* down_blocker;
};

#endif // ITEM_H
