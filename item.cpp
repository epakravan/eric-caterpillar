#include "item.h"
#include "data.h"
#include "canvas.h"
#include <iostream>

//Constructors

Item::Item(Canvas* canvas_) {
    width = 0;
    height = 0;
    x = 0;
    y = 0;
    velocityX = 0;
    velocityY = 0;
    speedX = 4;
    speedY = 4;
    canvas=canvas_;
    items = NULL;
    windowMaxX=canvas->getWidth();
    windowMaxY=canvas->getHeight();
    marginTop=canvas->getMarginTop();
    marginBottom=canvas->getMarginBottom();
    marginLeft=canvas->getMarginLeft();
    marginRight=canvas->getMarginRight();
    left_blocker=NULL;
    right_blocker=NULL;
    up_blocker=NULL;
    down_blocker=NULL;
    setOffset(x, y);
}

//Setters

void Item::set(int nx, int ny, int w, int h, int vx, int vy) {
    x = nx;
    y = ny;
    width = w;
    height = h;
    velocityX = vx;
    velocityY = vy;
    setOffset(x, y);
}

void Item::setData(Data<Item*>* items_){
    items=items_;
}

void Item::setX(int nx) {
    x = nx;
    setOffset(x, y);
}

void Item::setY(int ny) {
    y = ny;
    setOffset(x, y);
}

void Item::setSize(int w, int h){
    width = w;
    height = h;
}

void Item::setWidth(int w) {
    width = w;
}

void Item::setHeight(int h) {
    height = h;
}

void Item::setVelocity(int vx, int vy) {
    velocityX = vx;
    velocityY = vy;
}

void Item::setVelocityX(int vx) {
    velocityX = vx;
}

void Item::setVelocityY(int vy) {
    velocityY = vy;
}

void Item::setSpeed(int sx, int sy){
    speedX=sx;
    speedY=sy;
}

void Item::setSpeedX(int sx){
    speedX=sx;
}

void Item::setSpeedY(int sy){
    speedY=sy;
}

void Item::setWindowMax(int wx, int wy){
    windowMaxX=wx;
    windowMaxY=wy;
}

void Item::setWindowMaxX(int wx){
    windowMaxX=wx;
}

void Item::setWindowMaxY(int wy){
    windowMaxY=wy;
}

void Item::setMargin(int mTop, int mBottom, int mLeft, int mRight){
    marginTop=mTop;
    marginBottom=mBottom;
    marginLeft=mLeft;
    marginRight=mRight;
}

void Item::setMarginTop(int mTop){
    marginTop=mTop;
}

void Item::setMarginBottom(int mBottom){
    marginBottom=mBottom;
}

void Item::setMarginLeft(int mLeft){
    marginLeft=mLeft;
}

void Item::setMarginRight(int mRight){
    marginRight=mRight;
}


//Getters


int Item::getX() {
    return x;
}

int Item::getY() {
    return y;
}

int Item::getVelocityX() {
    return velocityX;
}

int Item::getVelocityY() {
    return velocityY;
}

int Item::getWidth() {
    return width;
}

int Item::getHeight() {
    return height;
}

int Item::getSpeedX() {
    return speedX;
}

int Item::getSpeedY() {
    return speedY;
}

int Item::getWindowMaxX() {
    return windowMaxX;
}

int Item::getWindowMaxY() {
    return windowMaxY;
}
 
int Item::getMarginTop() {
    return marginTop;
}

int Item::getMarginBottom() {
    return marginBottom;
}

int Item::getMarginLeft() {
    return marginLeft;
}

int Item::getMarginRight() {
    return marginRight;
}


int Item::getLeft() {
    return x;
}

int Item::getRight() {
    return x+width;
}

int Item::getTop() {
    return y;
}

int Item::getBottom() {
    return y+height;
}


//Booleans

bool Item::Top( ) {
 /*   if (up_blocker!=NULL)  {
    	if (up_blocker->getBottom()<y&&up_blocker->getBottom()>=y-speedY){
    		return(up_blocker->Top());
    	}
    	else {
    		up_blocker=NULL;
    		return TRUE;
    	}
    }
    else */
        return (y>=marginTop+speedY);
}

bool Item::Bottom() {
 /*   if (down_blocker!=NULL)  {
    	if (down_blocker->getTop()>y+height&&down_blocker->getTop()<=y+height+speedY){
    		return(down_blocker->Bottom());
    	}
    	else {
    		down_blocker=NULL;
    		return TRUE;
    	}
    }
    else */
        return ( (y+height) <= windowMaxY - marginBottom - speedY );
}

bool Item::Right() {
  /*  if (right_blocker!=NULL)  {
    	if (right_blocker->getLeft()>x+width&&right_blocker->getLeft()<=x+width+speedX){
    		return(right_blocker->Right());
    	}
    	else {
    		right_blocker=NULL;
    		return TRUE;
    	}
    }
    else */
        return ((x+width) <= windowMaxX - marginRight - speedX );
}

bool Item::Left() {
 /*   if (left_blocker!=NULL)  {
    	if (left_blocker->getRight()<x&&left_blocker->getRight()>=x-speedX){
    		return(left_blocker->Left());
    	}
    	else {
    		left_blocker=NULL;
    		return TRUE;
    	}
    }
    else */
    	return ( x >= marginLeft + speedX );
}

//Functions

void Item::move() {
    x += velocityX;
    y += velocityY;

    if ( x < 0 + marginLeft ) {
        velocityX = -velocityX;
        x +=velocityX;
    }

    if ( y < 0 + marginTop ) {
        velocityY = -velocityY;
        y +=velocityY;
    }

    if ( (x+width) > windowMaxX - marginRight ) {
         velocityX = -velocityX;
         x+=velocityX;
    }

    if ( (y+height) > windowMaxY - marginBottom ) {
         velocityY = -velocityY;
         y+=velocityY;
    }

    setOffset(x, y);

}

void Item::move_up() {
    up_blocker=NULL;
    Item* blocker=NULL;
    if (items){
    for (int i=0; i<items->size();i++){
    	Item* item = items->at(i);
    	if (item->getBottom()<y&&item->getBottom()>=y-speedY){
    	    if (item->getLeft()+item->getWidth()>=x&&item->getLeft()<x+width){
    		if(!up_blocker)
    			up_blocker=item;
    		else {
    			blocker=item;
    			break;
    		}
    	    }
    	}
    }
    }
    if (up_blocker) {
    	if (blocker) {
    		if (up_blocker->Top() && blocker->Top()){
    			y -= speedY;
    			up_blocker->move_up();
    			blocker->move_up();
    		}
    	}
    	else if ( up_blocker->Top() ) {
    		y -= speedY;
    		up_blocker->move_up();
    	}
    }
    else if ( y>= marginTop+speedY ) {
    		y -= speedY;
    }
    setOffset(x, y);
}

void Item::move_down() {
    down_blocker=NULL;
    Item* blocker=NULL;
    if (items) {
    for (int i=0; i<items->size();i++){
    	Item* item = items->at(i);
    	if (item->getTop()>y+height&&item->getTop()<=y+height+speedY){
    	    if (item->getRight()>=x&&item->getLeft()<x+width){
    		if(!down_blocker)
    			down_blocker=item;
    		else {
    			blocker=item;
    			break;
    		}
    	    }
    	}
    }
    }
    if (down_blocker) {
    	if (blocker) {
    		if (down_blocker->Bottom() && blocker->Bottom()){
    			y += speedY;
    			down_blocker->move_down();
    			blocker->move_down();
    		}
    	}
    	else if ( down_blocker->Bottom() ) {
    		y += speedY;
    		down_blocker->move_down();
    	}
    }
    else if ( (y+height) <= windowMaxY-marginBottom-speedY ) {
    	y += speedY;
    }
    setOffset(x, y);
}

void Item::move_right() {
    right_blocker=NULL;
    Item* blocker=NULL;
    if (items){
    for (int i=0; i<items->size();i++){
    	Item* item = items->at(i);
    	if (item->getLeft()>x+width&&item->getLeft()<=x+width+speedX){
    	    if (item->getBottom()>=y&&item->getTop()<y+height){
    		if(!right_blocker)
    			right_blocker=item;
    		else {
    			blocker=item;
    			break;
    		}
    	    }
    	}
    }
    }
    if (right_blocker) {
    	if (blocker) {
    		if (right_blocker->Right() && blocker->Right()){
    			x += speedX;
    			right_blocker->move_right();
    			blocker->move_right();
    		}
    	}
    	else if ( right_blocker->Right() ) {
    		x += speedX;
    		right_blocker->move_right();
    	}
    }
    else if ( (x+width) <= windowMaxX-marginRight-speedX ) {
    	x += speedX;
    }
    setOffset(x, y);
}

void Item::move_left() {
    left_blocker=NULL;
    Item* blocker=NULL;
    if (items){
    for (int i=0; i<items->size();i++){
    	Item* item = items->at(i);
    	if (item->getRight()<x&&item->getRight()>=x-speedX){
    	    if (item->getBottom()>=y&&item->getTop()<y+height){
    		if(!left_blocker)
    			left_blocker=item;
    		else {
    			blocker=item;
    			break;
    		}
    	    }
    	}
    }
    }
    if (left_blocker) {
    	if (blocker) {
    		if (left_blocker->Left() && blocker->Left()){
    			x -= speedX;
    			left_blocker->move_left();
    			blocker->move_left();
    		}
    	}
    	else if ( left_blocker->Left() ) {
    		x -= speedX;
    		left_blocker->move_left();
    	}
    }
    else if ( x >= marginLeft+speedX ) {
    	x -= speedX;
    }
    setOffset(x, y);
}

int Item::onTimer(){
	return -1;
}
