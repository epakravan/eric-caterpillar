#include "itemA.h"

ItemA::ItemA(Canvas* canvas_, Player* player_) : Item (canvas_) {
    player = player_;
    width = 26;
    height = 40;
    x = windowMaxX-width;
    y = ((player->getTop()+player->getBottom())-height)/2;
    velocityX = -2;
    set(x, y, width, height, velocityX, velocityY);
}

void ItemA::move_up() {
    if (player->Top()) {
    	y -= 4;
    }
    //Everything is good. Update the QRectF that is actually displayed.
    setOffset(x, y);
}

void ItemA::move_down() {
    if (player->Bottom()) {
    	y += 4;
    }
    //Everything is good. Update the QRectF that is actually displayed.
    setOffset(x, y);
}
