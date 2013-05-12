#ifndef ITEMA_H
#define ITEMA_H
#include "item.h"
#include "player.h"

/**
  This class maintains the location, size, and speed of a QGraphicsRectItem.
  It is easier to do the arithmetic with this data, and then update the position
  separately, then to extract coordinates from the QRectF that is contained within
  the QGraphicsRectItem
  */
class ItemA : public Item {
public:
    ItemA(Canvas* canvas_, Player* player_);
    void move_up();
    void move_down();

private:
    Player *player;
    
};

#endif // ITEMA_H
