#ifndef CANVAS_H
#define CANVAS_H
#include <QGraphicsPixmapItem>

/**
  This class maintains the location, size, and speed of a QGraphicsRectItem.
  It is easier to do the arithmetic with this data, and then update the position
  separately, then to extract coordinates from the QRectF that is contained within
  the QGraphicsRectItem
  */
class Canvas : public QGraphicsPixmapItem {
public:
    Canvas(double nx, double ny, double w, double h, int mTop, int mBottom, int mLeft, int mRight);
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    int getMarginTop();
    int getMarginBottom();
    int getMarginLeft();
    int getMarginRight();

private:
    int x;
    int y;
    int width;
    int height;
    int marginTop;
    int marginBottom;
    int marginLeft;
    int marginRight;
};

#endif // CANVAS_H
