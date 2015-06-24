#include "stdafx.h"
#include "Platform.h"
#include "../Extras/utilities.h"

Platform::Platform() : Actor() {
  you = NULL;
  isLeft = isRight= isUp = isDown = true;

}

Platform::Platform(Level* l, float x_,float y_,float w,float h,You* yo) : Actor(l,x_,y_,w,h){
  you = yo;
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(0,255,0));
  shape.setSize(sf::Vector2f(width,height));
  shape.setPosition(x,y);
#endif
  isLeft = isRight= isUp = isDown = true;
}

void Platform::act() {
  if (isRectangularHit(you,this)) {
    int dir = getApproachDirection(you,this);
    if (dir==0&& isUp)
      you->ceiling(y+height);
    else if (dir==1 && isRight)
      you->hitRightWall(x,y,y+height);
    else if (dir==2 && isDown)
      you->land(y,x,x+width);
    else if (dir==3 && isLeft)
      you->hitLeftWall(x+width,y,y+height);
  }
}

#ifndef COMPILE_NO_SF
void Platform::render(sf::RenderWindow& window) {
	
  window.draw(shape);
}
#endif
