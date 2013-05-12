#ifndef ITEMC_H
#define ITEMC_H
#include <QGraphicsPixmapItem>
#include "data.h"
#include "item.h"
#include "canvas.h"

class ItemC : public Item {
public:
    ItemC(Canvas* canvas_);
    int onTimer();
    
private:
    int finalY;
    int counter;
    bool placed;
};

#endif // ITEMC_H
