#include "stdafx.h"
#include "VerticalPlat.h"

VertPlat::VertPlat() :  Actor(), ThinPlat(),Mover() {
}

VertPlat::VertPlat(Level* l, float x_,float y_,float w,You* yo,bool isV) : 
  Actor(l,x_,y_,w,3),ThinPlat(l,x_,y_,w,yo),Mover(l,x_,y_,w,3) {
  isVert = isV;
  vel = .5*frame_diff;
}

void VertPlat::act() {
  Platform::act();
  Mover::act();
  if (vel>0)
    ThinPlat::act();
  if (isVert)
    y-=vel;
  else
    y+=vel;
  if (you->getPlatX1()==getX1() && you->getPlatX2()==getX2())
    you->land(getY1(),getX1(),getX2());
	
}
#ifndef COMPILE_NO_SF

void VertPlat::render(sf::RenderWindow& window) {
  shape.setPosition(x,y);
  ThinPlat::render(window);
}
#endif
void VertPlat::hitDetector(int dir) {
  if (dir==0)
    isVert=false;
  else if (dir==2)
    isVert=true;
}
