#include "stdafx.h"
#include "Wall.h"
#include "Extras/utilities.h"
#include "../Level.h"
Wall::Wall() : Actor(),BigEye(),Platform() {

}
Wall::Wall(Level* l, float x_,float y_, float w, float h,
	     SmallEye* e,You* yo, bool on) : 
  Actor(l,x_,y_,w,h), BigEye(l,x_,y_,NOTHING,e), Platform(l,x_,y_,w,h,yo){
  isVis=on;
  shape.setFillColor(sf::Color(200,140,10));
  shape.setSize(sf::Vector2f(w,h));
  dir=-2;
  isHit=false;
}

void Wall::act() {
  if (isVis) {
    Platform::act();
    BigEye::act();
  }
}
#ifndef COMPILE_NO_SF
void Wall::render(sf::RenderWindow& window) {
  if (isVis) {
    shape.setPosition(getX1(),getY1());
    window.draw(shape);
  }
}
#endif
