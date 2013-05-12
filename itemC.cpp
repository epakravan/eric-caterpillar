#include "itemC.h"
#include <iostream>

ItemC::ItemC(Canvas* canvas_) : Item(canvas_) {
    placed=false;
    counter=0;
    width = 50;
    height = 50;
    x = rand()%(windowMaxX-width-50*2)+1; //rand 1->1000 inclusive
    y = marginTop + speedY;
    finalY=rand()%(windowMaxY-height-50*2-marginTop-speedY)+1+50+marginTop+speedY; //rand 1->1000 inclusive
    set(x, y, width, height, velocityX, velocityY);
}

int ItemC::onTimer() {
    if (!placed){
    	if (y<finalY)
    		move_down();
    	else
    		placed=true;
    }
    return ++counter;
}
