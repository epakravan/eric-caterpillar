#include "canvas.h"

Canvas::Canvas(double nx, double ny, double w, double h, int mTop, int mBottom, int mLeft, int mRight) {
    x = nx;
    y = ny;
    width = w;
    height = h;
    marginTop = mTop;
    marginBottom = mBottom;
    marginLeft = mLeft;
    marginRight = mRight;
    setOffset(x,y);
}

int Canvas::getX() {
    return x;
}

int Canvas::getY() {
    return y;
}

int Canvas::getWidth() {
    return width;
}

int Canvas::getHeight() {
    return height;
}

int Canvas::getMarginTop() {
    return marginTop;
}

int Canvas::getMarginBottom() {
    return marginBottom;
}

int Canvas::getMarginLeft() {
    return marginLeft;
}

int Canvas::getMarginRight() {
    return marginRight;
}


