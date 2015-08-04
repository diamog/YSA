#include "stdafx.h"
#include "VerticalPlat.h"

VertPlat::VertPlat() :  Actor(), ThinPlat(),Mover() {
}

VertPlat::VertPlat(Level* l, float x_,float y_,float w,You* yo,bool isV, int dir) : 
  Actor(l,x_,y_,w,3),ThinPlat(l,x_,y_,w,yo),Mover(l,x_,y_,w,3) {
  isVert = isV;
  vel = .5*frame_diff*dir;
}

void VertPlat::act() {
  Platform::act();
  Mover::act();
  ThinPlat::act();
  if (isVert)
    y+=vel;
  else
    x+=vel;
  if (you->getPlat()==this)
    you->land(this);
}
#ifndef COMPILE_NO_SF

void VertPlat::render(sf::RenderWindow& window) {
  shape.setPosition(x,y);
  ThinPlat::render(window);
}
#endif
void VertPlat::hitDetector(int dir) {
  vel*=-1;
}
