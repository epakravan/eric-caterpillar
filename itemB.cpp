#include "itemB.h"

ItemB::ItemB(Canvas* canvas_) : Item(canvas_) {
    width = 20;
    height = 20;
    x = rand()%(1000-width)+1; //rand 1->1000 inclusive
    y = marginTop;
    velocityX = rand()%4-2; //rand -4->4 inclusive
    velocityY = 2;
    set(x, y, width, height, velocityX, velocityY);
}
