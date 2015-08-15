#include "stdafx.h"
#include "Wall.h"
#include "../Extras/utilities.h"
#include "../Level.h"
Wall::Wall() : Actor(),BigEye(),Platform() {

}
Wall::Wall(Level* l, float x_,float y_, float w, float h,
	     SmallEye* e,You* yo, bool on) : 
  Actor(l,x_,y_,w,h), BigEye(l,x_,y_,NOTHING,e), Platform(l,x_,y_,w,h,yo){
  isVis=on;
  alpha=0;
  shape.setFillColor(sf::Color(200,140,10));
  shape.setSize(sf::Vector2f(w,h));
  dir=-2;
  isHit=false;
}

void Wall::act() {
  if (isVis) {
    if (alpha<248)
      alpha+=6;
    else
      alpha=255;
    Platform::act();
    BigEye::act();
  }
  else {
    if (alpha>7)
      alpha-=6;
    else
      alpha=0;
  }
}
#ifndef COMPILE_NO_SF
void Wall::render(sf::RenderWindow& window) {
  shape.setFillColor(sf::Color(200,140,10,alpha));
  shape.setPosition(getX1(),getY1());
  window.draw(shape);
}
#endif
