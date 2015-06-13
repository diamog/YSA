#include "stdafx.h"
#include "Platform.h"
#include "utilities.h"

Platform::Platform() : Actor() {
	you = NULL;
	isLeft = isRight= isUp = isDown = true;

}

Platform::Platform(float x_,float y_,float w,float h,You* yo) : Actor(x_,y_,w,h){
	you = yo;
	shape.setFillColor(sf::Color(0,255,0));
	shape.setSize(sf::Vector2f(width,height));
	shape.setPosition(x,y);
	isLeft = isRight= isUp = isDown = true;
}

void Platform::act() {
  if (isRectangularHit(you,this)) {
    int dir = getApproachDirection(you,this);
    if (dir==0)
      you->ceiling(y+height);
    else if (dir==1)
      you->hitRightWall(x,y,y+height);
    else if (dir==2)
      you->land(y,x,x+width);
    else if (dir==3)
      you->hitLeftWall(x+width,y,y+height);
  }
}
void Platform::render(sf::RenderWindow& window) {
	
  window.draw(shape);
}
