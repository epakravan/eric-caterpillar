#ifndef ITEMD_H
#define ITEMD_H
#include <QGraphicsRectItem>
#include "data.h"
#include "item.h"
#include "canvas.h"

class ItemD : public Item {
public:
    ItemD(Canvas* canvas);
    int onTimer();

private:
    int counter;
    int finalY;
    bool placed;
};

#endif // ITEMD_H
