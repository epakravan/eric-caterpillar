#include "itemE.h"

ItemE::ItemE(Canvas* canvas_, Player* player_) : Item (canvas_) {
    player = player_;
    width = 26;
    height = 40;
    x = windowMaxX-width;
    y = ((player->getTop()+player->getBottom())-height)/2;
    velocityX = -2;
    set(x, y, width, height, velocityX, velocityY);
}
