#include "player.h"

Player::Player(Canvas* canvas_) : Item(canvas_) {
    x=25;
    y=383;
    
    width=50;
    height=50;
    
    defaultX=x;
    defaultY=y;

    velocityX = 3;
    velocityY = 2;
    
    loc=0;
    
    bouncing=false;
    grabbing=false;
    rising=false;
    grab_left=false;
    grab_right=false;
    
    set(x, y, width, height, velocityX, velocityY);
    
    timer = new QTimer(this);
    timer->setInterval(5);
    connect(timer, SIGNAL(timeout()), this, SLOT(timercontrol()));
    timer->start();
}

void Player::eat() {
	if (bouncing==false&&grabbing==false){
    		bouncing=true;
    		rising=true;
    	    	count=0;
    		velocityY=2;
    	}
}

void Player::leaf(int loc_) {
	if (grabbing==false&&bouncing==false){
		loc=loc_;
		count=0;
		velocityX=(loc-width-x)/30;
    		grabbing=true;
    		rising=true;
    		defaultX=x;
    		defaultY=y;
    		if (x+width<loc_)
    			grab_right=true;
    		else if (x>loc_)
    			grab_left=true;
    	}
}

void Player::timercontrol() {
	grab();
	bounce();
}

void Player::bounce() {
	if (bouncing==false)
		return;
		
	if (rising==false){
		count--;
		y+=velocityY;
		if (count==0) {
			bouncing=false;
		}
	}
	else {
		y-=velocityY;
		count++;
		if (count==20){
     			rising=false;
		}
	}
        setOffset(x,y);
}

void Player::grab() {
    if (grabbing==false)
	return;
		
    if (grab_right){	
	if (rising==false){
		x-=velocityX;
		count--;
		if (count==0) {
			grabbing=false;
     			grab_right=false;
     			grab_left=false;
		}
	}
	else {
		count++;
		x+=velocityX;
		if (count==30){
     			rising=false;
		}
	}
     }
     else if (grab_left){
	if (rising) {
		count++;
		x+=velocityX;
		if (count==30){
     			rising=false;
		}
	}
	else {
		count--;
		x-=velocityX;
		if (count==0) {
			grabbing=false;
     			grab_left=false;
     			grab_right=false;
		}
	}
     }
     else {
     	grabbing=false;
     	grab_left=false;
     	grab_right=false;
     	bouncing=false;
     	rising=false;
     	count=0;
     }

	
        setOffset(x,y);
}

Player::~Player()
{
}
