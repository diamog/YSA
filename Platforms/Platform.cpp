#include "stdafx.h"
#include "Platform.h"
#include "../Extras/utilities.h"
#include "ColorPlat.h"
#include "../Enemies/Reverser.h"
Platform::Platform() : Actor() {
  you = NULL;
  isLeft = isRight= isUp = isDown = true;

}

Platform::Platform(Level* l, float x_,float y_,float w,float h,You* yo) : Actor(l,x_,y_,w,h){
  you = yo;
#ifndef COMPILE_NO_SF
  shape.setFillColor(sf::Color(0,255,0));
#endif
  isLeft = isRight= isUp = isDown = true;
  kickLeft=kickRight=false;
}

void Platform::act() {
  if (isRectangularHit(you,this)) {
    int dir = getApproachDirection(you,this);
    if (dir==0&& isUp)
      you->ceiling(getY2());
    else if (dir==1 && isRight)
      you->hitRightWall(getX1(),kickLeft);
    else if (dir==2 && isDown)
      you->land(getY1(),getX1(),getX2());
    else if (dir==3 && isLeft)
      you->hitLeftWall(getX2(),kickRight);
  }
  if (rev!=NULL) {
    if (isRectangularHit(rev,this)) {
      int dir = getApproachDirection(rev,this);
      if (dir==0&& isUp)
	rev->ceiling(y+height);
      else if (dir==1 && isRight)
	rev->hitRightWall(x,kickLeft);
      else if (dir==2 && isDown)
	rev->land(y,x,x+width);
      else if (dir==3 && isLeft)
	rev->hitLeftWall(x+width,kickRight);
    }
  
  }
}

#ifndef COMPILE_NO_SF
void Platform::render(sf::RenderWindow& window) {
  shape.setPosition(getX1(),getY1());
  shape.setSize(sf::Vector2f(width,height));
  if (!dynamic_cast<ColorPlatform*>(this)&&!dynamic_cast<ColorPlat*>(this)) {
    if (!you->boss1())
      shape.setFillColor(sf::Color(255,255,255));
    else
      shape.setFillColor(sf::Color(0,255,0));
  }
  window.draw(shape);
}
#endif
