#include "itemD.h"

ItemD::ItemD(Canvas* canvas_) : Item(canvas_) {
    placed=false;
    counter=0;
    width = 50;
    height = 50;
    x = rand()%(windowMaxX-width-50*2)+1; //rand 1->1000 inclusive
    y = windowMaxY - speedY - marginBottom - height;
    finalY=rand()%(windowMaxY-height-50*2-marginTop-speedY)+1+50+marginTop+speedY; //rand 1->1000 inclusive
    set(x, y, width, height, velocityX, velocityY);
    setOffset(x, y);
}

int ItemD::onTimer() {
    if (!placed){
    	if (y>finalY)
    		move_up();
    	else
    		placed=true;
    }
    return ++counter;
}
