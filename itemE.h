#ifndef ITEME_H
#define ITEME_H
#include "item.h"
#include "player.h"

class ItemE : public Item {
public:
    ItemE(Canvas* canvas_, Player* player_);

private:
    Player *player;
    
};

#endif // ITEME_H
